PORTNAME=	wmglobe
PORTVERSION=	1.3
PORTREVISION=	12
CATEGORIES=	astro windowmaker geography
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	jd.fbsd@goneja.de
COMMENT=	Neat xearth-like WindowMaker dockapp
WWW=		https://www.dockapps.net/wmglobe

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwraster.so:x11-wm/libwraster

USES=		xorg
USE_XORG=	x11 xext xpm

MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

PLIST_FILES=	bin/wmglobe \
		share/man/man1/wmglobe.1.gz

.include <bsd.port.mk>
