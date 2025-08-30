PORTNAME=	astroterm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.9
CATEGORIES=	astro
MASTER_SITES=	https://web.archive.org/web/20231007085824if_/http://tdc-www.harvard.edu/catalogs/:DATA \
		https://web.archive.org/web/20250114171002if_/http://tdc-www.harvard.edu/catalogs/:ASCIIDATA
DISTFILES=	BSC5:DATA \
		ybsc5.gz:ASCIIDATA
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Explore stars, planets, constellations, and more in your terminal!
WWW=		https://github.com/da-luce/astroterm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xxd:sysutils/xxd
LIB_DEPENDS=	libargtable2.so:devel/argtable

USES=		compiler meson ncurses ninja pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	da-luce

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFAULT=	BINARY
OPTIONS_SINGLE=		DATA
OPTIONS_SINGLE_DATA=	ASCII BINARY

ASCII_DESC=	Download the data source in ASCII format
BINARY_DESC=	Download the data source in binary format

.include <bsd.port.options.mk>

post-extract:
.if ${PORT_OPTIONS:MBINARY}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/BSC5 \
		${WRKSRC}/data/bsc5
.endif
.if ${PORT_OPTIONS:MASCII}
	${GZIP_CMD} -dc ${DISTDIR}/${DIST_SUBDIR}/ybsc5.gz > ${WRKSRC}/data/ybsc5
.endif

.include <bsd.port.mk>
