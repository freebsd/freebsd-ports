PORTNAME=	objectdetect
PORTVERSION=	0.0.3
PORTREVISION=	11
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple library for detecting objects in pictures

LICENSE=	MIT

BROKEN=		OpenCV4 no longer ships OpencCV-1.0 headers

LIB_DEPENDS=	libopencv_video.so:graphics/opencv

USE_RUBY=	yes
USES=		gem pkgconfig

post-patch:
	${REINPLACE_CMD} -E 's|(objectdetect)|\1/version|' ${WRKSRC}/test/test_helper.rb

.include <bsd.port.mk>
