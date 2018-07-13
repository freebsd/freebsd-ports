# $FreeBSD$

PORTNAME=	slideshowkit
PORTVERSION=	0.0.1
PORTREVISION=	20050214
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/gsimageapps/
PKGNAMEPREFIX=	gnustep-
DISTNAME=	SlideShowKit-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SlideShow Framework

LICENSE=	NONE

DEPRECATED=	unknown license
EXPIRATION_DATE=	2018-08-15

USES=		gnustep
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Libraries/libSlideShow.so

.include <bsd.port.mk>
