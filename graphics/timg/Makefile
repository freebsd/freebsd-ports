# $FreeBSD$

PORTNAME=	timg
PORTVERSION=	0.9.8
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Terminal Image Viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick6

USES=		compiler:c++11-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	hzeller

ALL_TARGET=	${PORTNAME}
WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/timg

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
