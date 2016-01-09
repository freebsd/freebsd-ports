# Created by: jmz
# $FreeBSD$

PORTNAME=	unzip
PORTVERSION=	6.0
PORTREVISION=	7
CATEGORIES=	archivers
MASTER_SITES=	SF/infozip/UnZip%206.x%20%28latest%29/UnZip%20${PORTVERSION}/:main \
		SF/infozip/UnZip%205.x%20and%20earlier/5.51/:unreduce
DISTNAME=	${PORTNAME}60
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	List, test, and extract compressed files from a ZIP archive

LICENSE=	Info-ZIP
LICENSE_NAME=	Info-ZIP license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe
CPE_VENDOR=	info-zip
ALL_TARGET=	bsd
MAKEFILE=	unix/Makefile
MAKE_ARGS=	LF2="${STRIP}"
PORTDOCS=	README WHERE
MANPAGES=	unzip.1 funzip.1 unzipsfx.1 zipgrep.1 zipinfo.1
PLIST_FILES=	bin/unzip bin/funzip bin/unzipsfx bin/zipgrep \
		bin/zipinfo
PLIST_FILES+=	${MANPAGES:C|^(.*)\.([1-9])$|man/man\2/\1.\2.gz|}

LOCAL_UNZIP=	${CFLAGS} -DACORN_FTYPE_NFS -DWILD_STOP_AT_DIR \
		-DUNICODE_SUPPORT -DUTF8_MAYBE_NATIVE -D_MBCS \
		-DLARGE_FILE_SUPPORT

MAKE_ENV=	LOCAL_UNZIP="${LOCAL_UNZIP}" \
		D_USE_BZ2=-DUSE_BZIP2 L_BZ2=-lbz2

.ifdef USE_UNZIP
.error You have "USE_UNZIP" variable defined in environment or in \
	make(1) arguments. Please undefine and try again.
.endif

OPTIONS_DEFINE=		DOCS ICONV
OPTIONS_RADIO=		RG1
OPTIONS_RADIO_RG1=	CHINESE KOREAN RUSSIAN

RG1_DESC=		Localization
CHINESE_DESC=		Chinese language support
KOREAN_DESC=		Korean language support
RUSSIAN_DESC=		CP866 and KOI8-R support

ICONV_USES=		iconv

.include <bsd.port.options.mk>

.if ${ARCH} == i386
ALL_TARGET=	freebsd
.endif

.if ${PORT_OPTIONS:MICONV}
CFLAGS+=	-I${LOCALBASE}/include -DNATIVE
MAKE_ARGS+=	LFLAGS1="-L${LOCALBASE}/lib ${ICONV_LIB}"
EXTRA_PATCHES+=	${FILESDIR}/extra-iconv-patch-unix_unix.c \
		${FILESDIR}/extra-iconv-patch-unix_unxcfg.h \
		${FILESDIR}/extra-iconv-patch-unzip.c \
		${FILESDIR}/extra-iconv-patch-unzpriv.h \
		${FILESDIR}/extra-iconv-patch-zipinfo.c
.endif

.if ${PORT_OPTIONS:MCHINESE}
CATEGORES+=	chinese
EXTRA_PATCHES+=	${FILESDIR}/extra-zh-patch-fileio.c
.endif

.if ${PORT_OPTIONS:MKOREAN}
CATEGORIES+=	korean
EXTRA_PATCHES+=	${FILESDIR}/extra-ko-patch-fileio.c \
		${FILESDIR}/extra-ko-patch-unzip.c \
		${FILESDIR}/extra-ko-patch-unzip.h
.endif

.if ${PORT_OPTIONS:MRUSSIAN}
CATEGORIES+=	russian
EXTRA_PATCHES+=	${FILESDIR}/extra-ru-patch-ebcdic.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unzip \
		${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} funzip unzipsfx ${STAGEDIR}${PREFIX}/bin
	${LN} -sf unzip ${STAGEDIR}${PREFIX}/bin/zipinfo
	${INSTALL_SCRIPT} ${WRKSRC}/unix/zipgrep ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/unzip.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MANPAGES:Nunzip.1:Ninfo-unzip.1} \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
