PORTNAME=	astroterm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.8
CATEGORIES=	astro
MASTER_SITES=	https://web.archive.org/web/20231007085824if_/http://tdc-www.harvard.edu/catalogs/:DATA
DISTFILES=	BSC5:DATA
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

post-extract:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/BSC5 \
		${WRKSRC}/data/bsc5

.include <bsd.port.mk>
