# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	objectdetect
PORTVERSION=	0.0.3
PORTREVISION=	7
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple library for detecting objects in pictures

LICENSE=	MIT

LIB_DEPENDS=	libopencv_legacy.so:${PORTSDIR}/graphics/opencv

USES=		pkgconfig
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

post-patch:
	${REINPLACE_CMD} -E 's|(objectdetect)|\1/version|' ${WRKSRC}/test/test_helper.rb

.include <bsd.port.post.mk>
