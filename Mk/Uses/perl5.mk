# $FreeBSD$
#
# Provide support to use perl5
#
# PERL5		- Set to full path of perl5, either in the system or
#		  installed from a port.
# PERL		- Set to full path of perl5, either in the system or
#		  installed from a port, but without the version number.
#		  Use this if you need to replace "#!" lines in scripts.
# PERL_VERSION	- Full version of perl5 (see below for current value).
#
# PERL_VER	- Short version of perl5 (major.minor without patchlevel)
#
# PERL_LEVEL	- Perl version as an integer of the form MNNNPP, where
#		  M is major version, N is minor version, and P is
#		  the patch level. E.g., PERL_VERSION=5.14.4 would give
#		  a PERL_LEVEL of 501404. This can be used in comparisons
#		  to determine if the version of perl is high enough,
#		  whether a particular dependency is needed, etc.
# PERL_ARCH	- Directory name of architecture dependent libraries
#		  (value: mach).
# PERL_PORT	- Name of the perl port that is installed
#		  (for example: perl5.24)
# SITE_PERL	- Directory name where site specific perl packages go.
#		  This value is added to PLIST_SUB.
# SITE_ARCH	- Directory name where arch site specific perl packages go.
#		  This value is added to PLIST_SUB.
# USE_PERL5	- If set, this port uses perl5 in one or more of the extract,
#		  patch, build, run or test phases.
#		  It can also have configure, modbuild and modbuildtiny when
#		  the port needs to run Makefile.PL, Build.PL and a
#		  Module::Build::Tiny flavor of Build.PL.
#
# MAINTAINER: perl@FreeBSD.org

.if !defined(_INCLUDE_USES_PERL5_MK)
_INCLUDE_USES_PERL5_MK=	yes

.  if !empty(perl5_ARGS)
IGNORE=	Incorrect 'USES+=perl5:${perl5_ARGS}' perl5 takes no arguments
.  endif

USE_PERL5?=	run build

# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
.    if ${PERL5_DEFAULT} == 5.22
.include "${PORTSDIR}/lang/perl5.22/version.mk"
.    elif ${PERL5_DEFAULT} == 5.24
.include "${PORTSDIR}/lang/perl5.24/version.mk"
.    elif ${PERL5_DEFAULT} == 5.26
.include "${PORTSDIR}/lang/perl5.26/version.mk"
.    elif ${PERL5_DEFAULT} == devel
.include "${PORTSDIR}/lang/perl5-devel/version.mk"
# Force PERL_PORT here in case two identical PERL_VERSION.
PERL_PORT?=	perl5-devel
.    else
IGNORE=	Invalid perl5 version ${PERL5_DEFAULT}
.    endif

PERL_VER?=	${PERL_VERSION:C/\.[0-9]+$//}

.  if !defined(PERL_LEVEL) && defined(PERL_VERSION)
perl_major=	${PERL_VERSION:C|^([1-9]+).*|\1|}
_perl_minor=	00${PERL_VERSION:C|^([1-9]+)\.([0-9]+).*|\2|}
perl_minor=	${_perl_minor:C|^.*(...)|\1|}
.    if ${perl_minor} >= 100
perl_minor=	${PERL_VERSION:C|^([1-9]+)\.([0-9][0-9][0-9]).*|\2|}
perl_patch=	${PERL_VERSION:C|^.*(..)|\1|}
.    else # ${perl_minor} < 100
_perl_patch=	0${PERL_VERSION:C|^([1-9]+)\.([0-9]+)\.*|0|}
perl_patch=	${_perl_patch:C|^.*(..)|\1|}
.    endif # ${perl_minor} < 100
PERL_LEVEL=	${perl_major}${perl_minor}${perl_patch}
.  else
PERL_LEVEL=0
.  endif # !defined(PERL_LEVEL) && defined(PERL_VERSION)

PERL_ARCH?=	mach

# there must always be a default to prevent dependency failures such
# as "ports/lang: not found".  Also, perl5-devel is taken care in the
# perl5_default file, or up there in the default versions selection.
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
.  if   ${PERL_LEVEL} >= 502600
PERL_PORT?=	perl5.26
.  elif   ${PERL_LEVEL} >= 502400
PERL_PORT?=	perl5.24
.  else # ${PERL_LEVEL} < 502400
PERL_PORT?=	perl5.22
.  endif

SITE_PERL_REL?=	lib/perl5/site_perl
SITE_PERL?=	${LOCALBASE}/${SITE_PERL_REL}
SITE_ARCH_REL?=	${SITE_PERL_REL}/${PERL_ARCH}/${PERL_VER}
SITE_ARCH?=	${LOCALBASE}/${SITE_ARCH_REL}
SITE_MAN3_REL?=	${SITE_PERL_REL}/man/man3
SITE_MAN3?=	${PREFIX}/${SITE_MAN3_REL}
SITE_MAN1_REL?=	${SITE_PERL_REL}/man/man1
SITE_MAN1?=	${PREFIX}/${SITE_MAN1_REL}

PERL5?=		${LOCALBASE}/bin/perl${PERL_VERSION}
PERL?=		${LOCALBASE}/bin/perl
CONFIGURE_ENV+=	ac_cv_path_PERL=${PERL} ac_cv_path_PERL_PATH=${PERL} \
		PERL_USE_UNSAFE_INC=1

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

QA_ENV+=	SITE_ARCH_REL=${SITE_ARCH_REL} LIBPERL=libperl.so.${PERL_VER}

# Define the want perl first if defined
.  if ${USE_PERL5:M5*}
want_perl_sign=		${USE_PERL5:M5*:C|^[0-9.]+||}
want_perl_ver=		${USE_PERL5:M5*:S|${want_perl_sign}$||}
want_perl_major=	${want_perl_ver:C|\..*||}
_want_perl_minor=	${want_perl_ver:S|^${want_perl_major}||:S|^.||:C|\..*||}
_want_perl_patch=	${want_perl_ver:S|^${want_perl_major}||:S|^.${_want_perl_minor}||:S|^.||:C|\..*||}
want_perl_minor=	${_want_perl_minor:S|^|000|:C|.*(...)|\1|}
want_perl_patch=	${_want_perl_patch:S|^|00|:C|.*(..)|\1|}
USE_PERL5_LEVEL=	${want_perl_major}${want_perl_minor}${want_perl_patch}
.  endif

# All but version
_USE_PERL5=	${USE_PERL5:N5*}

# Mask unspecified components. E.g. this way "5" will match any "5.x.x".
.  if empty(_want_perl_minor)
masked_PERL_LEVEL=	${PERL_LEVEL:C|(.....)$|00000|}
.  elif empty(_want_perl_patch)
masked_PERL_LEVEL=	${PERL_LEVEL:C|(..)$|00|}
.  else
masked_PERL_LEVEL=	${PERL_LEVEL}
.  endif

.  if defined(want_perl_sign)
.    if ${want_perl_sign} == "+"
.      if ${USE_PERL5_LEVEL} > ${masked_PERL_LEVEL}
USE_PERL5_REASON?=	requires Perl ${want_perl_ver} or later, install lang/perl${want_perl_major}.${want_perl_minor:C|^0||} and try again
IGNORE=	${USE_PERL5_REASON}
.      endif # ${USE_PERL5_LEVEL} > ${masked_PERL_LEVEL}
.    elif ${want_perl_sign} == ""
.      if ${USE_PERL5_LEVEL} != ${masked_PERL_LEVEL}
USE_PERL5_REASON?=	requires Perl ${want_perl_ver} exactly
IGNORE=	${USE_PERL5_REASON}
.      endif # ${USE_PERL5_LEVEL} != ${masked_PERL_LEVEL}
.    elif ${want_perl_sign} == "-"
.      if ${USE_PERL5_LEVEL} <= ${masked_PERL_LEVEL}
USE_PERL5_REASON?=	requires a Perl version earlier than ${want_perl_ver}
IGNORE=	${USE_PERL5_REASON}
.      endif # ${USE_PERL5_LEVEL} <= ${masked_PERL_LEVEL}
.    else # wrong suffix
IGNORE=	improper use of USE_PERL5
.    endif
.  endif

_USES_POST+=	perl5
.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_PERL5_POST_MK)
_INCLUDE_USES_PERL5_POST_MK=	yes

PLIST_SUB+=	PERL_VERSION=${PERL_VERSION} \
		PERL_VER=${PERL_VER} \
		PERL5_MAN1=${SITE_MAN1_REL} \
		PERL5_MAN3=${SITE_MAN3_REL} \
		SITE_PERL=${SITE_PERL_REL} \
		SITE_ARCH=${SITE_ARCH_REL}

# handle perl5 specific manpages
.  for sect in 3
.    if defined(P5MAN${sect})
_MANPAGES+=	${P5MAN${sect}:S%^%${PREFIX}/lib/perl5/${PERL_VER}/man/man${sect}/%}
.    endif
.  endfor
MANDIRS+=	${PREFIX}/${SITE_PERL_REL}/man

.  if ${_USE_PERL5:Mmodbuild} || ${_USE_PERL5:Mmodbuildtiny}
_USE_PERL5+=	configure
ALL_TARGET?=	# empty
CONFIGURE_ARGS+=--install_path lib="${PREFIX}/${SITE_PERL_REL}" \
		--install_path arch="${PREFIX}/${SITE_ARCH_REL}" \
		--install_path script="${PREFIX}/bin" \
		--install_path bin="${PREFIX}/bin" \
		--install_path libdoc="${MAN3PREFIX}/man/man3" \
		--install_path bindoc="${MAN1PREFIX}/man/man1"
CONFIGURE_SCRIPT?=	Build.PL
PL_BUILD?=	Build
CONFIGURE_ARGS+=--destdir ${STAGEDIR}
DESTDIRNAME=	--destdir
.    if ${_USE_PERL5:Mmodbuild}
CONFIGURE_ARGS+=--perl="${PERL}"
.      if ${PORTNAME} != Module-Build
BUILD_DEPENDS+=	p5-Module-Build>=0.4206:devel/p5-Module-Build
.      endif
CONFIGURE_ARGS+=--create_packlist 1
.    endif
.    if ${_USE_PERL5:Mmodbuildtiny}
.      if ${PORTNAME} != Module-Build-Tiny
BUILD_DEPENDS+=	p5-Module-Build-Tiny>=0.039:devel/p5-Module-Build-Tiny
.      endif
CONFIGURE_ARGS+=--create_packlist 1
.    endif
.  elif ${_USE_PERL5:Mconfigure}
CONFIGURE_ARGS+=INSTALLDIRS="site"
.  endif # modbuild

.  if ${_USE_PERL5:Mconfigure}
_USE_PERL5+=	build run
# Disable AutoInstall from attempting to install from CPAN directly in
# the case of missing dependencies.  This causes the build to loop on
# the build cluster asking for interactive input.
CONFIGURE_ENV+= PERL_EXTUTILS_AUTOINSTALL="--skipdeps"
.    if defined(BATCH) && !defined(IS_INTERACTIVE)
CONFIGURE_ENV+=	PERL_MM_USE_DEFAULT="YES"
.    endif # defined(BATCH) && !defined(IS_INTERACTIVE)
.  endif # configure

.  if ${_USE_PERL5:Mextract}
EXTRACT_DEPENDS+=	${PERL5_DEPEND}:lang/${PERL_PORT}
.  endif

.  if ${_USE_PERL5:Mpatch}
PATCH_DEPENDS+=		${PERL5_DEPEND}:lang/${PERL_PORT}
.  endif

.  if ${_USE_PERL5:Mbuild}
BUILD_DEPENDS+=		${PERL5_DEPEND}:lang/${PERL_PORT}
.  endif

.  if ${_USE_PERL5:Mrun}
RUN_DEPENDS+=		${PERL5_DEPEND}:lang/${PERL_PORT}
.  endif

.  if ${_USE_PERL5:Mtest}
TEST_DEPENDS+=		${PERL5_DEPEND}:lang/${PERL_PORT}
.  endif

.  if ${_USE_PERL5:Mconfigure}
CONFIGURE_ARGS+=	CC="${CC}" CCFLAGS="${CFLAGS}" PREFIX="${PREFIX}" \
			INSTALLPRIVLIB="${PREFIX}/lib" INSTALLARCHLIB="${PREFIX}/lib"
CONFIGURE_SCRIPT?=	Makefile.PL
MAN3PREFIX?=		${PREFIX}/${SITE_PERL_REL}
MAN1PREFIX?=		${PREFIX}/${SITE_PERL_REL}
.undef HAS_CONFIGURE

.    if !target(do-configure)
do-configure:
	@if [ -f ${SCRIPTDIR}/configure ]; then \
		cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} \
		${SCRIPTDIR}/configure; \
	fi
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PERL5} ${CONFIGURE_CMD} ${CONFIGURE_ARGS}
.      if !${_USE_PERL5:Mmodbuild*}
	@cd ${CONFIGURE_WRKSRC} && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile
.      endif # ! modbuild
.    endif # !target(do-configure)
.  endif # configure

.  if ${_USE_PERL5:Mmodbuild*}
.    if !target(do-build)
do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} ${PL_BUILD} ${ALL_TARGET} ${MAKE_ARGS})
.    endif # !target(do-build)

.    if !${USES:Mgmake}
.      if !target(do-install)
do-install:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} ${PL_BUILD} ${INSTALL_TARGET} ${MAKE_ARGS})
.      endif # !target(do-install)
.    endif # ! USES=gmake
.  endif # modbuild

PACKLIST_DIR?=	${PREFIX}/${SITE_ARCH_REL}/auto

# In all those, don't use - before the command so that the user does
# not wonder what has been ignored by this message "*** Error code 1 (ignored)"
_USES_install+=	560:fix-perl-things
fix-perl-things:
# Remove STAGEDIR from .packlist and add the file to the plist.
	@(if [ -d ${STAGEDIR}${PACKLIST_DIR} ] ; then \
		${FIND} ${STAGEDIR}${PACKLIST_DIR} -name .packlist | while read f ; do \
			${SED} -i '' 's|^${STAGEDIR}||' "$$f"; \
			${ECHO} $$f | ${SED} -e 's|^${STAGEDIR}||' >> ${TMPPLIST}; \
		done \
	fi) || :

# Starting with perl 5.20, the empty bootstrap files are not installed any more
# by ExtUtils::MakeMaker.  As we don't need them anyway, remove them.
# Module::Build continues to install them, so remove the files unconditionally.
	@${FIND} ${STAGEDIR} -name '*.bs' -size 0 -delete || :

# Some ports use their own way of building perl modules and generate
# perllocal.pod, remove it here so that those ports don't include it
# by mistake in their plists.  It is sometime compressed, so use a
# shell glob for the removal.  Also, remove the directories that
# contain it to not leave orphans directories around.
	@${RM} ${STAGEDIR}${PREFIX}/lib/perl5/${PERL_VER}/${PERL_ARCH}/perllocal.pod* || :
	@${RMDIR} -p ${STAGEDIR}${PREFIX}/lib/perl5/${PERL_VER}/${PERL_ARCH} 2>/dev/null || :
# Starting at ExtUtils::MakeMaker 7.06 and Perl 5.25.1, the base README.pod is
# no longer manified into a README.3, as the README.pod is installed and can be
# read with perldoc, remove the README.3 files that may be generated.
	@[ -d "${STAGEDIR}${SITE_MAN3}" ] && \
		${FIND} ${STAGEDIR}${SITE_MAN3} -name '*::README.3' -delete || :

.  if !target(do-test) && (!empty(USE_PERL5:Mmodbuild*) || !empty(USE_PERL5:Mconfigure))
TEST_TARGET?=	test
TEST_WRKSRC?=	${BUILD_WRKSRC}
do-test:
.    if ${USE_PERL5:Mmodbuild*}
	@cd ${TEST_WRKSRC}/ && ${SETENV} ${TEST_ENV} ${PERL5} ${PL_BUILD} ${TEST_TARGET} ${TEST_ARGS}
.    elif ${USE_PERL5:Mconfigure}
	@cd ${TEST_WRKSRC}/ && ${SETENV} ${TEST_ENV} ${MAKE_CMD} ${TEST_ARGS} ${TEST_TARGET}
.    endif # USE_PERL5:Mmodbuild*
.  endif # do-test
.endif # defined(_POSTMKINCLUDED)
