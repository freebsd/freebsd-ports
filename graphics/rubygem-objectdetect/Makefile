# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	objectdetect
PORTVERSION=	0.0.3
PORTREVISION=	8
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple library for detecting objects in pictures

LICENSE=	MIT

LIB_DEPENDS=	libopencv_legacy.so:graphics/opencv2

USE_RUBY=	yes
USES=		gem pkgconfig

post-patch:
	${REINPLACE_CMD} -E 's|(objectdetect)|\1/version|' ${WRKSRC}/test/test_helper.rb

.include <bsd.port.mk>
