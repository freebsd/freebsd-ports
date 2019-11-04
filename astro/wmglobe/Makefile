# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	wmglobe
PORTVERSION=	1.3
PORTREVISION=	11
CATEGORIES=	astro windowmaker geography
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	jd.fbsd@goneja.de
COMMENT=	Neat xearth-like WindowMaker dockapp

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwraster.so:x11-wm/libwraster

USES=		xorg
USE_XORG=	x11 xext xpm

PLIST_FILES=	bin/wmglobe \
		man/man1/wmglobe.1.gz
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
