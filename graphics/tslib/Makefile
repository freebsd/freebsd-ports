PORTNAME=	tslib
DISTVERSION=	1.23
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/libts/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Touchscreen access library
WWW=		http://www.tslib.org/

LICENSE=	LGPL21

USES=	cmake pathfix tar:xz

# - Waveshare requires Linux internals
CMAKE_OFF=	enable-waveshare

.include <bsd.port.mk>
