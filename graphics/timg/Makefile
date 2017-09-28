# $FreeBSD$

PORTNAME=	timg
PORTVERSION=	0.9.5
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Terminal Image Viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick

USE_GITHUB=	yes
GH_ACCOUNT=	hzeller

USES=		gmake
ALL_TARGET=	${PORTNAME}
WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/timg

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
