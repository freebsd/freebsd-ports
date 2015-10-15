# Created by: markm
# $FreeBSD$

PORTNAME=	perl
PORTVERSION=	${PERL_VERSION}
PORTREVISION=	24
CATEGORIES=	lang devel perl5
MASTER_SITES=	CPAN/../../src/5.0
DIST_SUBDIR=	perl

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Practical Extraction and Report Language

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/Artistic
LICENSE_FILE_GPLv1=	${WRKSRC}/Copying

DEPRECATED=	Unsupported, please upgrade to a more recent version of Perl
EXPIRATION_DATE=2015-12-31

TEST_TARGET=	test_harness
TEST_ENV=	${MAKE_ENV} TEST_JOBS=${MAKE_JOBS_NUMBER}

OPTIONS_DEFINE=	DEBUG GDBM PERL_MALLOC PERL_64BITINT THREADS PTHREAD \
		MULTIPLICITY SITECUSTOMIZE USE_PERL
OPTIONS_DEFAULT=	PERL_64BITINT THREADS PTHREAD USE_PERL MULTIPLICITY
OPTIONS_SUB=
GDBM_DESC=	GDBM_File extension
PERL_MALLOC_DESC=	Use Perl malloc
PERL_64BITINT_DESC=	Use 64 bit integers (on i386)
THREADS_DESC=		Build threaded perl
PTHREAD_DESC=		Build with -lpthread
MULTIPLICITY_DESC=	Use multiplicity
SITECUSTOMIZE_DESC=	Run-time customization of @INC
USE_PERL_DESC=		Rewrite links in /usr/bin

PORTSCOUT=	limit:^${PERL_VER}.

# Remember to update Mk/Uses/perl5.mk too.
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

USES=	tar:bzip2 cpe
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	-sde -Dprefix=${PREFIX} \
	-Dlibperl=libperl.so.${PERL_VERSION} \
	-Darchlib=${PREFIX}/${_ARCH_LIB} \
	-Dprivlib=${PREFIX}/${_PRIV_LIB} \
	-Dman3dir=${PREFIX}/${PERLMANPREFIX_REL}/man/man3 \
	-Dman1dir=${PREFIX}/${PERLMANPREFIX_REL}/man/man1 \
	-Dsitearch=${SITE_ARCH} \
	-Dsitelib=${SITE_PERL} -Dscriptdir=${PREFIX}/bin \
	-Dsiteman3dir=${SITE_MAN3} \
	-Dsiteman1dir=${SITE_MAN1} \
	-Dotherlibdirs=${PREFIX}/lib/perl5/site_perl/${PERL_VER}:${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH} \
	-Ui_malloc -Ui_iconv -Uinstallusrbinperl -Dusenm=n \
	-Dcc="${CC}" -Duseshrplib -Dinc_version_list=none \
	-Dcf_by=${MAINTAINER:C,@.*,,} -Dcf_email=${MAINTAINER} \
	-Dcf_time="`env LANG=C ${STAT} -t \"%a %b %d %T %Z %Y\" -f %Sm ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}`"
# Keep the following two in sync.
# lddlflags is used for all .so linking
# shrpldflags is used for libperl.so, so remove all the extra bits inherited from lddlflags.
CONFIGURE_ARGS+= \
	-Alddlflags='-L${WRKSRC} -L${PREFIX}/${_ARCH_LIB}/CORE -Wl,-rpath=${PREFIX}/${_ARCH_LIB}/CORE -lperl' \
	-Dshrpldflags='$$(LDDLFLAGS:N-L${WRKSRC}:N-L${PREFIX}/${_ARCH_LIB}/CORE:N-Wl,-rpath=${PREFIX}/${_ARCH_LIB}/CORE:N-lperl) -Wl,-soname,$$(LIBPERL:R)'
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

SUB_FILES=	use.perl perl-man.conf

PKGINSTALL=	${WRKDIR}/use.perl
PKGDEINSTALL=	${WRKDIR}/use.perl
INSTALL_TARGET=	install-strip

_PERL5_DEFAULT_FILE=	/tmp/PERL5_DEFAULT

.include <bsd.port.pre.mk>
.sinclude "${_PERL5_DEFAULT_FILE}"
.include "${PORTSDIR}/Mk/bsd.default-versions.mk"

# if this port is default due PERL5_DEFAULT
# change PKGNAME to reflect this
.if ${PERL_VER} == ${PERL5_DEFAULT}
PKGNAMESUFFIX=	${PERL_VERSION:C/\.[0-9]+\.[0-9]+$//}
IAMDEFAULTPERL=	yes
.else
# make PKGNAME unique among other lang/perl5.x
PKGNAMESUFFIX=	${PERL_VER}
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
		ARCH_LIB=${_ARCH_LIB}

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	-Doptimize="-g" -DDEBUGGING
STRIP=
STRIP_CMD=	${TRUE}
.else
CONFIGURE_ARGS+=	-Doptimize="${CFLAGS}"
.endif

.if ${PORT_OPTIONS:MGDBM}
CONFIGURE_ARGS+=	-Di_gdbm
LIB_DEPENDS+=		libgdbm.so:${PORTSDIR}/databases/gdbm
.else
CONFIGURE_ARGS+=	-Ui_gdbm
.endif

.if ${PORT_OPTIONS:MTHREADS}
#XXX .if ${ARCH} == "amd64"
#XXX IGNORE=	Threaded perl does not pass tests on ${ARCH}
#XXX .endif
CONFIGURE_ARGS+=	-Dusethreads=y
WITH_PTHREAD=		yes
# it seems perl malloc has problems with threaded perl on FreeBSD
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}
PORT_OPTIONS:=	${PORT_OPTIONS:NPERL_MALLOC}
.else
CONFIGURE_ARGS+=	-Dusethreads=n
.endif

.if ${PORT_OPTIONS:MPERL_MALLOC}
CONFIGURE_ARGS+=	-Dusemymalloc=y
.else
CONFIGURE_ARGS+=	-Dusemymalloc=n
.endif

.if ${PORT_OPTIONS:MPERL_64BITINT}
CONFIGURE_ARGS+=	-Duse64bitint
.endif

.if ${PORT_OPTIONS:MMULTIPLICITY}
CONFIGURE_ARGS+=	-Dusemultiplicity=y
.else
CONFIGURE_ARGS+=	-Dusemultiplicity=n
.endif

.if ${PORT_OPTIONS:MSITECUSTOMIZE}
CONFIGURE_ARGS+=	-Dusesitecustomize
.endif

.if ${PORT_OPTIONS:MUSE_PERL}
LINK_USRBIN=	yes
.else
LINK_USRBIN=	no
.endif
SUB_LIST+=	LINK_USRBIN=${LINK_USRBIN}

# Put a symlink to the future libperl.so.x.yy so that -lperl works.
# Also, save PERL5_DEFAULT in case someone is not using the default Perl
# version whilst not having set DEFAULT_VERSIONS=perl5=blah.  While upgrading,
# portmaster/portupgrade will remove the installed Perl version, and it will
# remove any way to guess what the default Perl version is needed.
post-extract:
	${LN} -s libperl.so.${PERL_VERSION} ${WRKSRC}/libperl.so
	${LN} -s libperl.so.${PERL_VERSION} ${WRKSRC}/libperl.so.${PERL_VER}
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
.if ${PORT_OPTIONS:MPTHREAD}
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|-lpthread|g;' \
		${WRKSRC}/hints/freebsd.sh
.else
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%||g;' \
		${WRKSRC}/hints/freebsd.sh
.endif

post-install:
	${MKDIR} ${STAGEDIR}${SITE_MAN1} ${STAGEDIR}${SITE_MAN3}
	${MKDIR} ${STAGEDIR}${SITE_ARCH}/auto
	${MKDIR} ${STAGEDIR}${SITE_PERL}/auto
	${LN} ${STAGEDIR}${PREFIX}/bin/perl${PERL_VERSION} ${STAGEDIR}${PREFIX}/bin/perl5
	${LN} -sf libperl.so.${PERL_VERSION} ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/CORE/libperl.so
	${LN} -sf libperl.so.${PERL_VERSION} ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/CORE/libperl.so.${PERL_VER}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/perl${PERL_VERSION}
	${FIND} ${STAGEDIR} -name '*.bs' -size 0 -delete
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
	${INSTALL_DATA} ${WRKDIR}/perl-man.conf ${STAGEDIR}${PREFIX}/etc/man.d/perl${PERL_VER}.conf

.include <bsd.port.post.mk>
