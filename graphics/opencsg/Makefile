PORTNAME=	opencsg
PORTVERSION=	1.8.2
#PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.opencsg.org/
DISTNAME=	OpenCSG-${PORTVERSION}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Constructive Solid Geometry rendering library
WWW=		https://www.opencsg.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/copying.txt

USES=		cmake compiler:c++11-lang gl qt:5
USE_GL=		gl glu glut
USE_LDCONFIG=	yes
USE_QT=		opengl
PLIST_SUB=	PORTVERSION=${PORTVERSION}

CMAKE_OFF=	BUILD_EXAMPLE

.include <bsd.port.mk>
