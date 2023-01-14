PORTNAME=	objectdetect
PORTVERSION=	0.0.3
PORTREVISION=	13
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple library for detecting objects in pictures
WWW=		https://rubygems.org/gems/objectdetect

LICENSE=	MIT

BROKEN=		OpenCV4 no longer ships OpencCV-1.0 headers

LIB_DEPENDS=	libopencv_video.so:graphics/opencv

USES=		gem pkgconfig

post-patch:
	${REINPLACE_CMD} -E 's|(objectdetect)|\1/version|' ${WRKSRC}/test/test_helper.rb

.include <bsd.port.mk>
