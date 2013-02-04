#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# bsd.perl.mk - Support for Perl-based ports.
#
# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
#
# For FreeBSD committers:
# Please send all suggested changes to the maintainer instead of committing
# them to CVS yourself.
#
# PERL5			- Set to full path of perl5, either in the system or
#				  installed from a port.
# PERL			- Set to full path of perl5, either in the system or
#				  installed from a port, but without the version number.
#				  Use this if you need to replace "#!" lines in scripts.
# PERL_VERSION	- Full version of perl5 (see below for current value).
# PERL_LEVEL	- Perl version as an integer of the form MNNNPP, where
#				  M is major version, N is minor version, and P is
#				  the patch level. E.g., PERL_VERSION=5.14.2 would give
#				  a PERL_LEVEL of 501402. This can be used in comparisons
#				  to determine if the version of perl is high enough,
#				  whether a particular dependency is needed, etc.
# PERL_ARCH		- Directory name of architecture dependent libraries
#				  (value: mach).
# PERL_PORT		- Name of the perl port that is installed
#				  (value: perl5.14)
# SITE_PERL		- Directory name where site specific perl packages go.
#				  This value is added to PLIST_SUB.
# USE_PERL5		- If set, this port uses perl5 in one or more of the extract,
#				  patch, build, install or run phases.
# PERL_CONFIGURE
#				- Configure using Perl's MakeMaker.  Implies USE_PERL5.
# USE_PERL5_BUILD
#				- If set, this port uses perl5 in one or more of the
#				  extract, patch, build or install phases.
# USE_PERL5_RUN	- If set, this port uses perl5 for running.
# PERL_MODBUILD	- Use Module::Build to configure, build and install port.

.if !defined(_POSTMKINCLUDED) && !defined(Perl_Pre_Include)

Perl_Pre_Include=			bsd.perl.mk
PERL_Include_MAINTAINER=	perl@FreeBSD.org

PERL_VERSION?=	5.14.2

.if !defined(PERL_LEVEL) && defined(PERL_VERSION)
perl_major=		${PERL_VERSION:C|^([1-9]+).*|\1|}
_perl_minor=	00${PERL_VERSION:C|^([1-9]+)\.([0-9]+).*|\2|}
perl_minor=		${_perl_minor:C|^.*(...)|\1|}
.if ${perl_minor} >= 100
perl_minor=		${PERL_VERSION:C|^([1-9]+)\.([0-9][0-9][0-9]).*|\2|}
perl_patch=		${PERL_VERSION:C|^.*(..)|\1|}
.else # ${perl_minor} < 100
_perl_patch=	0${PERL_VERSION:C|^([1-9]+)\.([0-9]+)\.*|0|}
perl_patch=		${_perl_patch:C|^.*(..)|\1|}
.endif # ${perl_minor} < 100
PERL_LEVEL=	${perl_major}${perl_minor}${perl_patch}
.else
PERL_LEVEL=0
.endif # !defined(PERL_LEVEL) && defined(PERL_VERSION)

PERL_ARCH?=		mach

# there must always be a default to prevent dependency failures such
# as "ports/lang: not found"
.if    ${PERL_LEVEL} >= 501600
PERL_PORT?=	perl5.16
.elif  ${PERL_LEVEL} >= 501400
PERL_PORT?=	perl5.14
.else  # ${PERL_LEVEL} < 501400
PERL_PORT?=	perl5.12
.endif

SITE_PERL_REL?=	lib/perl5/site_perl/${PERL_VERSION}
SITE_PERL?=	${LOCALBASE}/${SITE_PERL_REL}

PERL5=		${LOCALBASE}/bin/perl${PERL_VERSION}
PERL=		${LOCALBASE}/bin/perl

# Decide where to look for the version string
.ifdef USE_PERL5
USE_PERL5_STRING=	${USE_PERL5}
.elifdef USE_PERL5_BUILD
USE_PERL5_STRING=	${USE_PERL5_BUILD}
.elifdef USE_PERL5_RUN
USE_PERL5_STRING=	${USE_PERL5_RUN}
.elifdef PERL_MODBUILD
USE_PERL5_STRING=	${PERL_MODBUILD}
.elifdef PERL_CONFIGURE
USE_PERL5_STRING=	${PERL_CONFIGURE}
.else
USE_PERL5_STRING=	yes  # currently unreachable
.endif

.if ${USE_PERL5_STRING:L} != "yes"
want_perl_sign=		${USE_PERL5_STRING:C|^[0-9.]+||}
want_perl_ver=		${USE_PERL5_STRING:S|${want_perl_sign}$||}
want_perl_major=	${want_perl_ver:C|\..*||}
_want_perl_minor=	${want_perl_ver:S|^${want_perl_major}||:S|^.||:C|\..*||}
_want_perl_patch=	${want_perl_ver:S|^${want_perl_major}||:S|^.${_want_perl_minor}||:S|^.||:C|\..*||}
want_perl_minor=	${_want_perl_minor:S|^|000|:C|.*(...)|\1|}
want_perl_patch=	${_want_perl_patch:S|^|00|:C|.*(..)|\1|}
USE_PERL5_LEVEL=	${want_perl_major}${want_perl_minor}${want_perl_patch}

# Mask unspecified components. E.g. this way "5" will match any "5.x.x".
.if empty(_want_perl_minor)
masked_PERL_LEVEL=	${PERL_LEVEL:C|(.....)$|00000|}
.elif empty(_want_perl_patch)
masked_PERL_LEVEL=	${PERL_LEVEL:C|(..)$|00|}
.else
masked_PERL_LEVEL=	${PERL_LEVEL}
.endif

.if ${want_perl_sign} == "+"
.if ${USE_PERL5_LEVEL} > ${masked_PERL_LEVEL}
USE_PERL5_REASON?=	requires Perl ${want_perl_ver} or later, install lang/perl${want_perl_major}.${want_perl_minor:C|^0||} and try again
IGNORE=	${USE_PERL5_REASON}
.endif # ${USE_PERL5_LEVEL} > ${masked_PERL_LEVEL}
.elif ${want_perl_sign} == ""
.if ${USE_PERL5_LEVEL} != ${masked_PERL_LEVEL}
USE_PERL5_REASON?=	requires Perl ${want_perl_ver} exactly
IGNORE=	${USE_PERL5_REASON}
.endif # ${USE_PERL5_LEVEL} != ${masked_PERL_LEVEL}
.elif ${want_perl_sign} == "-"
.if ${USE_PERL5_LEVEL} <= ${masked_PERL_LEVEL}
USE_PERL5_REASON?=	requires a Perl version earlier than ${want_perl_ver}
IGNORE=	${USE_PERL5_REASON}
.endif # ${USE_PERL5_LEVEL} <= ${masked_PERL_LEVEL}
.else # wrong suffix
IGNORE=	improper use of USE_PERL5
.endif
.endif #${USE_PERL5_STRING:L} != "yes"

.endif # !defined(_POSTMKINCLUDED) && !defined(Perl_Pre_Include)

.if defined(_POSTMKINCLUDED) && !defined(Perl_Post_Include)

Perl_Post_Include=		bsd.perl.mk

PLIST_SUB+=	PERL_VERSION=${PERL_VERSION} \
			PERL_VER=${PERL_VERSION} \
			PERL_ARCH=${PERL_ARCH} \
			SITE_PERL=${SITE_PERL_REL}

.if defined(PERL_MODBUILD)
PERL_CONFIGURE=		yes
CONFIGURE_SCRIPT?=	Build.PL
.if ${PORTNAME} != Module-Build
BUILD_DEPENDS+=		${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build
.endif
ALL_TARGET?=
PL_BUILD?=		Build
CONFIGURE_ARGS+= \
	create_packlist=0 \
	install_path=lib="${PREFIX}/${SITE_PERL_REL}" \
	install_path=arch="${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}" \
	install_path=script="${PREFIX}/bin" \
	install_path=bin="${PREFIX}/bin" \
	install_path=libdoc="${MAN3PREFIX}/man/man3" \
	install_path=bindoc="${MAN1PREFIX}/man/man1"
.elif defined(PERL_CONFIGURE)
CONFIGURE_ARGS+=	INSTALLDIRS="site"
.endif # defined(PERL_MODBUILD)

.if defined(PERL_CONFIGURE)
USE_PERL5?=	yes
# Disable AutoInstall from attempting to install from CPAN directly in
# the case of missing dependencies.  This causes the build to loop on
# the build cluster asking for interactive input.
CONFIGURE_ENV+= PERL_EXTUTILS_AUTOINSTALL="--skipdeps"
.if defined(BATCH) && !defined(IS_INTERACTIVE)
CONFIGURE_ENV+=	PERL_MM_USE_DEFAULT="YES"
.endif # defined(BATCH) && !defined(IS_INTERACTIVE)
.endif # defined(PERL_CONFIGURE)

.if defined(USE_PERL5) || defined(USE_PERL5_BUILD)
EXTRACT_DEPENDS+=	${PERL5}:${PORTSDIR}/lang/${PERL_PORT}
PATCH_DEPENDS+=		${PERL5}:${PORTSDIR}/lang/${PERL_PORT}
BUILD_DEPENDS+=		${PERL5}:${PORTSDIR}/lang/${PERL_PORT}
.endif
.if defined(USE_PERL5) || defined(USE_PERL5_RUN)
RUN_DEPENDS+=		${PERL5}:${PORTSDIR}/lang/${PERL_PORT}
.endif

.if defined(PERL_CONFIGURE)
CONFIGURE_ARGS+=	CC="${CC}" CCFLAGS="${CFLAGS}" PREFIX="${PREFIX}" \
			INSTALLPRIVLIB="${PREFIX}/lib" INSTALLARCHLIB="${PREFIX}/lib"
CONFIGURE_SCRIPT?=	Makefile.PL
MAN3PREFIX?=		${PREFIX}/lib/perl5/${PERL_VERSION}
.undef HAS_CONFIGURE
.endif # defined(PERL_CONFIGURE)

.if defined(PERL_CONFIGURE)
.if !target(do-configure)
# XXX MCL had to duplicate the first block; implies more refactoring needed
do-configure:
	@if [ -f ${SCRIPTDIR}/configure ]; then \
		cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} \
		  ${SCRIPTDIR}/configure; \
	fi
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
.if !defined(PERL_MODBUILD)
	@cd ${CONFIGURE_WRKSRC} && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile
.endif # !defined(PERL_MODBUILD)
.endif # !target(do-configure)
.endif # defined(PERL_CONFIGURE)

.if defined(PERL_MODBUILD)
.if !target(do-build)
do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} ${PL_BUILD} ${MAKE_ARGS} ${ALL_TARGET})
.endif # !target(do-build)

.if !defined(USE_GMAKE)
.if !target(do-install)
do-install:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} ${PL_BUILD} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif # !target(do-install)
.endif # !defined(USE_GMAKE)
.endif # defined(PERL_MODBUILD)
.endif # defined(_POSTMKINCLUDED) && !defined(Perl_Post_Include)
