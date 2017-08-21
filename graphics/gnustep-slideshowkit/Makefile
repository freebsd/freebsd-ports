# $FreeBSD$

PORTNAME=	slideshowkit
PORTVERSION=	0.0.1
PORTREVISION=	20050213
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/gsimageapps/
PKGNAMEPREFIX=	gnustep-
DISTNAME=	SlideShowKit-20050212

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SlideShow Framework

USES=		gnustep
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Libraries/libSlideShow.so

.include <bsd.port.mk>
