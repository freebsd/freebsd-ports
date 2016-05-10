# Created by: mat
# $FreeBSD$

PORTNAME=	perl
PORTREVISION=	0
# XXX Remove second line, uncomment first
#DISTVERSION=	${PERL_VERSION}
DISTVERSION=	${GH_TAGNAME:C/^v//:C/-g[0-9a-f]*$//}
CATEGORIES=	lang devel perl5
# XXX Leave only CPAN.
MASTER_SITES=	LOCAL/mat/perl GH CPAN/../../src/5.0
# XXX Remove DISTNAME
DISTNAME=	${PORTNAME}-${DISTVERSION}
DIST_SUBDIR=	perl

# XXX -> perl@
MAINTAINER=	mat@FreeBSD.org
COMMENT=	Practical Extraction and Report Language

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/Artistic
LICENSE_FILE_GPLv1=	${WRKSRC}/Copying

TEST_TARGET=	test_harness
TEST_ENV=	${MAKE_ENV} TEST_JOBS=${MAKE_JOBS_NUMBER} \
		LD_LIBRARY_PATH=${WRKSRC}

# XXX Remove github things.
USE_GITHUB=	yes
GH_ACCOUNT=	Perl
GH_PROJECT=	perl5
GH_TAGNAME=	v5.25.0-8-g51f69a2

OPTIONS_DEFINE=	DEBUG GDBM PERL_64BITINT PTHREAD \
		MULTIPLICITY SITECUSTOMIZE
# it seems perl malloc has problems with threaded perl on FreeBSD
OPTIONS_RADIO=	EXCLUSIVE
OPTIONS_RADIO_EXCLUSIVE=	THREADS PERL_MALLOC
OPTIONS_DEFAULT=	PERL_64BITINT THREADS PTHREAD MULTIPLICITY

EXCLUSIVE_DESC=	Exclusive OPTIONS
GDBM_DESC=	GDBM_File extension
PERL_MALLOC_DESC=	Use Perl malloc
PERL_64BITINT_DESC=	Use 64 bit integers (on i386)
THREADS_DESC=		Build threaded perl
PTHREAD_DESC=		Build with -lpthread
MULTIPLICITY_DESC=	Use multiplicity
SITECUSTOMIZE_DESC=	Run-time customization of @INC

OPTIONS_SUB=		yes
DEBUG_CONFIGURE_ON=	-Doptimize="-g" -DDEBUGGING
DEBUG_CONFIGURE_OFF=	-Doptimize="${CFLAGS}"
GDBM_CONFIGURE_ON=	-Di_gdbm
GDBM_CONFIGURE_OFF=	-Ui_gdbm
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
PERL_64BITINT_CONFIGURE_ON=	-Duse64bitint
MULTIPLICITY_CONFIGURE_ON=	-Dusemultiplicity=y
MULTIPLICITY_CONFIGURE_OFF=	-Dusemultiplicity=n
SITECUSTOMIZE_CONFIGURE_ON=	-Dusesitecustomize
THREADS_CONFIGURE_ON=	-Dusethreads=y
THREADS_CONFIGURE_OFF=	-Dusethreads=n
PERL_MALLOC_CONFIGURE_ON=	-Dusemymalloc=y
PERL_MALLOC_CONFIGURE_OFF=	-Dusemymalloc=n

# XXX uncomment PORTSCOUT line
#PORTSCOUT=	limit:^${PERL_VER}.

.include "version.mk"
PERL_VER=	${PERL_VERSION:C/\.[0-9]+$//}
PERL_ARCH=	mach
SITE_PERL_REL?=	lib/perl5/site_perl
SITE_PERL?=	${PREFIX}/${SITE_PERL_REL}
SITE_ARCH_REL?=	${SITE_PERL_REL}/${PERL_ARCH}/${PERL_VER}
SITE_ARCH?=	${PREFIX}/${SITE_ARCH_REL}
SITE_MAN_PREFIX=	${SITE_PERL_REL}
SITE_MAN3_REL?=	${SITE_MAN_PREFIX}/man/man3
SITE_MAN3?=	${PREFIX}/${SITE_MAN3_REL}
SITE_MAN1_REL?=	${SITE_MAN_PREFIX}/man/man1
SITE_MAN1?=	${PREFIX}/${SITE_MAN1_REL}

_PRIV_LIB=	lib/perl5/${PERL_VER}
_ARCH_LIB=	${_PRIV_LIB}/${PERL_ARCH}

# XXX releases are .tar.xz, add: tar:xz
USES=	cpe

# XXX replace all LIBPERL_VER occurences with PERL_VERSION
LIBPERL_VER=	${PORTVERSION:C/[^0-9.]//}

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	-sde -Dprefix=${PREFIX} \
	-Dlibperl=libperl.so.${LIBPERL_VER} \
	-Darchlib=${PREFIX}/${_ARCH_LIB} \
	-Dprivlib=${PREFIX}/${_PRIV_LIB} \
	-Dman3dir=${PREFIX}/${PERLMANPREFIX_REL}/man/man3 \
	-Dman1dir=${PREFIX}/${PERLMANPREFIX_REL}/man/man1 \
	-Dsitearch=${SITE_ARCH} \
	-Dsitelib=${SITE_PERL} -Dscriptdir=${PREFIX}/bin \
	-Dsiteman3dir=${SITE_MAN3} \
	-Dsiteman1dir=${SITE_MAN1} \
	-Ui_malloc -Ui_iconv -Uinstallusrbinperl -Dusenm=n \
	-Dcc="${CC}" -Duseshrplib -Dinc_version_list=none \
	-Dcf_by=${MAINTAINER:C,@.*,,} -Dcf_email=${MAINTAINER} \
	-Dcf_time="`env LANG=C ${STAT} -t \"%a %b %d %T %Z %Y\" -f %Sm ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}`"
# Keep the following two in sync.
# lddlflags is used for all .so linking
# shrpldflags is used for libperl.so, so remove all the extra bits inherited from lddlflags.
# XXX change the soname to $$(LIBPERL:R)
CONFIGURE_ARGS+= \
	-Alddlflags='-L${WRKSRC} -L${PREFIX}/${_ARCH_LIB}/CORE -lperl' \
	-Dshrpldflags='$$(LDDLFLAGS:N-L${WRKSRC}:N-L${PREFIX}/${_ARCH_LIB}/CORE:N-lperl) -Wl,-soname,$$(LIBPERL)'

# Give a hint of where libperl.so can be found.
USE_LDCONFIG=	${PREFIX}/${_ARCH_LIB}/CORE

# XXX Remove
CONFIGURE_ARGS+=	-Dusedevel -Uversiononly

LOCALE_CLEANUP=	LANG="" LC_ALL="" LC_COLLATE="" LC_CTYPE="" \
		LC_MESSAGES="" LC_MONETARY="" LC_NUMERIC="" \
		LC_TIME=""
CONFIGURE_ENV+=	${LOCALE_CLEANUP} UNAME_v="$$(uname -v | sed 'y/=/ /')"
MAKE_ENV+=	${LOCALE_CLEANUP}

SUB_LIST+=	PERL_VERSION=${PERL_VERSION} \
		PERL_VER=${PERL_VER} \
		SITE_PERL=${SITE_PERL_REL} \
		PRIV_LIB=${_PRIV_LIB} \
		PERLMANPREFIX=${PERLMANPREFIX_REL} \
		SITEMANPREFIX=${SITE_MAN_PREFIX} \
		PERL_ARCH=${PERL_ARCH}

SUB_FILES=	perl-man.conf

INSTALL_TARGET=	install-strip

.if defined(PERL_VENDOR_PREFIX)
CONFIGURE_ARGS+=	\
	-Dvendorprefix=${PERL_VENDOR_PREFIX} \
	-Dvendorarch=${PERL_VENDOR_PREFIX}/${_ARCH_LIB} \
	-Dvendorbin=${PERL_VENDOR_PREFIX}/bin \
	-Dvendorlib=${PERL_VENDOR_PREFIX}/${_PRIV_LIB} \
	-Dvendorman3dir=${PERL_VENDOR_PREFIX}/${_PRIV_LIB}/man/man3 \
	-Dvendorman1dir=${PERL_VENDOR_PREFIX}/man/man1
.endif

# http://perl5.git.perl.org/perl.git/commit/b83080de5c4254
# PERLIOBUF_DEFAULT_BUFSIZ size in bytes (default: 8192 bytes)
.if defined(PERLIOBUF_DEFAULT_BUFSIZ)
CONFIGURE_ARGS+=	\
    -Accflags=-DPERLIOBUF_DEFAULT_BUFSIZ=${PERLIOBUF_DEFAULT_BUFSIZ}
.endif

PERLMANPREFIX_REL=	${_PRIV_LIB}/perl
PERLMANPREFIX=	${PREFIX}/${PERLMANPREFIX_REL}
MANDIRS+=	${PERLMANPREFIX}/man

PLIST_SUB+=	PERL_VERSION=${PERL_VERSION} \
		PERL_VER=${PERL_VER} \
		PERL_ARCH=${PERL_ARCH} \
		MAN1=${PERLMANPREFIX_REL}/man/man1 \
		MAN3=${PERLMANPREFIX_REL}/man/man3 \
		PERLMANPREFIX=${PERLMANPREFIX_REL} \
		SITEMANPREFIX=${SITE_MAN_PREFIX} \
		SITE_PERL=${SITE_PERL_REL} \
		SITE_ARCH=${SITE_ARCH_REL} \
		PRIV_LIB=${_PRIV_LIB} \
		PKGNAMESUFFIX=${PKGNAMESUFFIX} \
		ARCH_LIB=${_ARCH_LIB}
# XXX Remove and change to PERL_VERSION in the plist.
PLIST_SUB+=	LIBPERL_VER=${LIBPERL_VER}

_PERL5_DEFAULT_FILE=	/tmp/PERL5_DEFAULT

# bsd.default-versions.mk needs to know LOCALBASE for Perl, so
# bsd.port.options.mk is needed before including it.
.include <bsd.port.options.mk>
.sinclude "${_PERL5_DEFAULT_FILE}"
.include "${.CURDIR}/../../Mk/bsd.default-versions.mk"

# if this port is default due PERL5_DEFAULT
# change PKGNAME to reflect this
.if ${PERL_VER} == ${PERL5_DEFAULT} || ${PERL5_DEFAULT} == devel # XXX Remove devel case
PKGNAMESUFFIX=	5
IAMDEFAULTPERL=	yes
.else
# make PKGNAME unique among other lang/perl5.x
.if defined(GH_TAGNAME) # XXX remove if, leave only the else.
PKGNAMESUFFIX=	5-devel
.else
PKGNAMESUFFIX=	${PERL_VER}
.endif
.endif

# Am I building the default Perl ?
.if defined(IAMDEFAULTPERL)
PLIST_SUB+=	DEFAULT="" BINSUFFIX=""
.else
BINSUFFIX=	${PERL_VERSION}
PLIST_SUB+=	DEFAULT="@comment " BINSUFFIX=${PERL_VERSION}
CONFIGURE_ARGS+=-Dversiononly
.endif

.if !defined(IAMDEFAULTPERL)
pre-everything::
	@${ECHO_MSG} "##################################################"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      This is *NOT* the DEFAULT perl version"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "It will *NOT* install ${PREFIX}/bin/perl"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "It will *ONLY* install ${PREFIX}/bin/perl${PERL_VERSION}"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The default Perl version currently is ${PERL5_DEFAULT}."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you want to use this version as the default,"
	@${ECHO_MSG} "stop the build now, add this line to your"
	@${ECHO_MSG} "/etc/make.conf, and then restart the build."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "DEFAULT_VERSIONS+=perl5=${PERL_VER}"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "##################################################"
.  if !(defined(PACKAGE_BUILDING) || defined(BATCH))
	@sleep 30
.  endif
.endif

# XXX Remove this
pre-everything::
	@${ECHO_MSG} "########################################"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "This is a DEVELOPER only version of Perl"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "             DO NOT USE IT"
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Things ARE going to be broken with it"
	@${ECHO_MSG} "       and it WILL eat your data"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "         You have been warned !"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "########################################"
# No need to make me, or the package builders, wait
.if !(defined(PACKAGE_BUILDING) || defined(PERL_DEV_SHUT_UP) || defined(BATCH))
	@sleep 30
.endif

# Put a symlink to the future libperl.so.x.yy so that -lperl works.
# Also, save PERL5_DEFAULT in case someone is not using the default Perl
# version whilst not having set DEFAULT_VERSIONS=perl5=blah.  While upgrading,
# portmaster/portupgrade will remove the installed Perl version, and it will
# remove any way to guess what the default Perl version is needed.
post-extract:
	${LN} -s libperl.so.${LIBPERL_VER} ${WRKSRC}/libperl.so
	${LN} -s libperl.so.${LIBPERL_VER} ${WRKSRC}/libperl.so.${PERL_VER}
.if !defined(PACKAGE_BUILDING)
	@${ECHO_CMD} "PERL5_DEFAULT=${PERL5_DEFAULT}" > ${_PERL5_DEFAULT_FILE}
.endif

.if !defined(PACKAGE_BUILDING)
post-clean:
	@${RM} ${_PERL5_DEFAULT_FILE}
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Configure ${WRKSRC}/hints/freebsd.sh
.if !defined(IAMDEFAULTPERL)
	${REINPLACE_CMD} -e '/do_installprivlib = 0 if .versiononly/d; \
		/^if.*nopods.*versiononly || /s/.*/if (1) {/' \
		${WRKSRC}/installperl
.endif
post-patch-PTHREAD-on:
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|-lpthread|g;' \
		${WRKSRC}/hints/freebsd.sh
post-patch-PTHREAD-off:
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%||g;' \
		${WRKSRC}/hints/freebsd.sh

post-build:
	@${REINPLACE_CMD} -e '/^lddlflags/s|-L${WRKSRC} ||' \
		${WRKSRC}/lib/Config_heavy.pl
.if ${CC} == /nxb-bin/usr/bin/cc
	@${REINPLACE_CMD} -e 's=/nxb-bin==' \
		${WRKSRC}/lib/Config.pm ${WRKSRC}/lib/Config_heavy.pl
# Restore Config.pm's timestamp so that Perl's build system does not think it
# needs to rebuild everything.
	@${TOUCH} -r ${WRKSRC}/lib/Config.pm.bak ${WRKSRC}/lib/Config.pm
.endif

post-install:
	${MKDIR} ${STAGEDIR}${SITE_MAN1} ${STAGEDIR}${SITE_MAN3}
	${MKDIR} ${STAGEDIR}${SITE_ARCH}/auto
	${MKDIR} ${STAGEDIR}${SITE_PERL}/auto
	${LN} ${STAGEDIR}${PREFIX}/bin/perl${PERL_VERSION} ${STAGEDIR}${PREFIX}/bin/perl5
	${LN} -sf libperl.so.${LIBPERL_VER} ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/CORE/libperl.so
	${LN} -sf libperl.so.${LIBPERL_VER} ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/CORE/libperl.so.${PERL_VER}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/perl${PERL_VERSION}
	${MKDIR} ${STAGEDIR}${SITE_ARCH}/machine
	${MKDIR} ${STAGEDIR}${SITE_ARCH}/sys
	# h2ph needs perl, but perl is not installed, it's only
	# staged, so, use the one in WRKDIR
	(cd /usr/include && ${SETENV} LD_LIBRARY_PATH=${WRKSRC} \
		${WRKSRC}/perl -I ${WRKSRC}/lib ${STAGEDIR}${PREFIX}/bin/h2ph${BINSUFFIX} \
		-d ${STAGEDIR}${SITE_ARCH} *.h machine/*.h sys/*.h >/dev/null)
	@${FIND} ${STAGEDIR}${SITE_ARCH} -name '*.ph' | sed -e 's|${STAGEDIR}||' >> ${TMPPLIST}
	${FIND} ${STAGEDIR} -name '*.so*' -type f | while read f; \
		do \
			${CHMOD} 644 $$f; \
			${STRIP_CMD} $$f; \
			${CHMOD} 444 $$f; \
		done
	${INSTALL_DATA} ${WRKDIR}/perl-man.conf ${STAGEDIR}${PREFIX}/etc/man.d/perl${PKGNAMESUFFIX}.conf

.include <bsd.port.mk>
