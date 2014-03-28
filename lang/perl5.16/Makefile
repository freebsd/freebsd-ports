# Created by: markm
# $FreeBSD$

PORTNAME=	perl
PORTVERSION=	${PERL_VERSION}
PORTREVISION=	8
CATEGORIES=	lang devel perl5
MASTER_SITES=	CPAN \
		${MASTER_SITE_LOCAL:S/$/:local/} \
		http://protey.ru/freebsd/distfiles/:local
MASTER_SITE_SUBDIR=	../../src \
			skv/:local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		BSDPAN-${BSDPAN_VERSION}${EXTRACT_SUFX}:local
DIST_SUBDIR=	perl

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Practical Extraction and Report Language

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

CONFLICTS_INSTALL=	perl5.14-* perl5.16-* perl5.18-*

OPTIONS_DEFINE=	DEBUG GDBM PERL_MALLOC PERL_64BITINT THREADS PTHREAD \
		MULTIPLICITY SITECUSTOMIZE USE_PERL
OPTIONS_DEFAULT=	PERL_64BITINT THREADS PTHREAD USE_PERL
OPTIONS_SUB=
GDBM_DESC=	GDBM_File extension
PERL_MALLOC_DESC=	Use Perl malloc
PERL_64BITINT_DESC=	Use 64 bit integers (on i386)
THREADS_DESC=		Build threaded perl
PTHREAD_DESC=		Build with -pthread
MULTIPLICITY_DESC=	Use multiplicity
SITECUSTOMIZE_DESC=	Run-time customization of @INC
USE_PERL_DESC=		Rewrite links in /usr/bin

PORTSCOUT=	limit:^${PERL_VER}.

PERL_VERSION=	5.16.3
PERL_VER=	${PERL_VERSION:C/\.[0-9]+$//}
PERL_ARCH=	mach
SITE_PERL_REL?=	lib/perl5/site_perl/${PERL_VER}
SITE_PERL?=	${LOCALBASE}/${SITE_PERL_REL}

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	-sde -Dprefix=${PREFIX} \
	-Darchlib=${PREFIX}/lib/perl5/${PERL_VER}/${PERL_ARCH} \
	-Dprivlib=${PREFIX}/lib/perl5/${PERL_VER} \
	-Dman3dir=${PREFIX}/lib/perl5/${PERL_VER}/perl/man/man3 \
	-Dman1dir=${PREFIX}/man/man1 \
	-Dsitearch=${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH} \
	-Dsitelib=${PREFIX}/${SITE_PERL_REL} -Dscriptdir=${PREFIX}/bin \
	-Dsiteman3dir=${PREFIX}/lib/perl5/${PERL_VER}/man/man3 \
	-Dsiteman1dir=${PREFIX}/man/man1 \
	-Ui_malloc -Ui_iconv -Uinstallusrbinperl \
	-Dcc="${CC}" -Duseshrplib -Dinc_version_list=none \
	-Dccflags=-DAPPLLIB_EXP=\"${BSDPAN_DEST}\"
LOCALE_CLEANUP=	LANG="" LC_ALL="" LC_COLLATE="" LC_CTYPE="" \
		LC_MESSAGES="" LC_MONETARY="" LC_NUMERIC="" \
		LC_TIME=""
CONFIGURE_ENV+=	${LOCALE_CLEANUP} UNAME_v="$$(uname -v | sed 'y/=/ /')"
MAKE_ENV+=	${LOCALE_CLEANUP}

SUB_LIST+=	PERL_VERSION=${PERL_VERSION} \
		PERL_VER=${PERL_VER} \
		PERL_ARCH=${PERL_ARCH}

SUB_FILES=	perl5_version use.perl perl-man.conf

PKGINSTALL=	${WRKDIR}/use.perl
PKGDEINSTALL=	${WRKDIR}/use.perl

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.default-versions.mk"

# if this port is default due PERL5_DEFAULT
# change PKGNAME to reflect this
.if ${PERL_VER} == ${PERL5_DEFAULT}
PKGNAMESUFFIX=	${PERL_VERSION:C/\.[0-9]+\.[0-9]+$//}
.else
# make PKGNAME unique among other lang/perl5.x
PKGNAMESUFFIX=	${PERL_VER}
# always add default perl5 pkgname to conflicts
CONFLICTS_INSTALL+=	perl5-*
.endif

.if defined(PERL_VENDOR_PREFIX)
CONFIGURE_ARGS+=	\
	-Dvendorprefix=${PERL_VENDOR_PREFIX} \
	-Dvendorarch=${PERL_VENDOR_PREFIX}/lib/perl5/${PERL_VER}/${PERL_ARCH} \
	-Dvendorbin=${PERL_VENDOR_PREFIX}/bin \
	-Dvendorlib=${PERL_VENDOR_PREFIX}/lib/perl5/${PERL_VER} \
	-Dvendorman3dir=${PERL_VENDOR_PREFIX}/lib/perl5/${PERL_VER}/man/man3 \
	-Dvendorman1dir=${PERL_VENDOR_PREFIX}/man/man1
.endif

# http://perl5.git.perl.org/perl.git/commit/b83080de5c4254
# PERLIOBUF_DEFAULT_BUFSIZ size in bytes (default: 8192 bytes)
.if defined(PERLIOBUF_DEFAULT_BUFSIZ)
CONFIGURE_ARGS+=	\
    -Accflags=-DPERLIOBUF_DEFAULT_BUFSIZ=${PERLIOBUF_DEFAULT_BUFSIZ}
.endif

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VER}/perl
MANDIRS+=	${MAN3PREFIX}

PLIST_SUB+=	PERL_VERSION=${PERL_VERSION} \
		PERL_VER=${PERL_VER} \
		PERL_ARCH=${PERL_ARCH} \
		MAN3=${MAN3PREFIX:S|^${LOCALBASE}/||}/man/man3 \
		SITE_PERL=${SITE_PERL:S|^${LOCALBASE}/||}

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

.if ${OSVERSION} >= 900022
PLIST_SUB+=	MANCONF=""
.else
PLIST_SUB+=	MANCONF="@comment "
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

BSDPAN_DEST=	${PREFIX}/lib/perl5/${PERL_VER}/BSDPAN
BSDPAN_FILES=	BSDPAN.pm BSDPAN/Override.pm Config.pm \
		ExtUtils/MM_Unix.pm \
		ExtUtils/MakeMaker.pm \
		ExtUtils/Packlist.pm
BSDPAN_VERSION=	20111107
BSDPAN_WRKSRC=	${WRKDIR}/BSDPAN-${BSDPAN_VERSION}

post-patch:
	${SED} -i '' -e 's|%%PERL_PKGNAME%%|${PKGNAME}|g; s|%%PERL_VER%%|${PERL_VER}|g;' \
		-e 's!%%BSDPAN_VERSION%%!${BSDPAN_VERSION}!g;' \
		${BSDPAN_WRKSRC}/ExtUtils/*.pm
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Configure ${WRKSRC}/hints/freebsd.sh
.if ${PORT_OPTIONS:MPTHREAD}
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g;' \
		-e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g;' \
		${WRKSRC}/hints/freebsd.sh
.else
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%||g;' \
		-e 's|%%PTHREAD_CFLAGS%%||g;' \
		${WRKSRC}/hints/freebsd.sh
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/perl5/${PERL_VER}/man/man3
	@${MKDIR} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto
	@${MKDIR} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/machine
	@${MKDIR} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/sys
	@${MKDIR} ${STAGEDIR}${SITE_PERL}/auto
	@${LN} ${STAGEDIR}${PREFIX}/bin/perl${PERL_VERSION} ${STAGEDIR}${PREFIX}/bin/perl5
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/perl${PERL_VERSION}
	${INSTALL_DATA} ${WRKDIR}/perl5_version ${STAGEDIR}${PREFIX}/etc
.if ${OSVERSION} >= 900022
	${INSTALL_DATA} ${WRKDIR}/perl-man.conf ${STAGEDIR}${PREFIX}/etc/man.d/perl${PERL_VER}.conf
.endif
.for files in ${BSDPAN_FILES}
	@${MKDIR} ${STAGEDIR}${BSDPAN_DEST}/${files:H}
	${INSTALL_DATA} \
		${BSDPAN_WRKSRC}/${files} ${STAGEDIR}${BSDPAN_DEST}/${files}
.endfor

test: build
	@(cd ${WRKSRC}; TEST_JOBS=${MAKE_JOBS_NUMBER} make test_harness)

regression-test: test

.include <bsd.port.post.mk>
