# $FreeBSD$

PORTNAME=	urho3d
PORTVERSION=	1.7.1
CATEGORIES=	graphics

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Cross-platform 2D and 3D game engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:noninja,insource dos2unix gl xorg
USE_GITHUB=	yes
USE_XORG=	x11 xext
USE_GL=		gl

PORTSCOUT=	skipv:1.11,1.12,1.13,1.14,1.15,1.16,1.21,1.22,1.23,1.31,1.32 # incorrect versioning upstream

DOS2UNIX_FILES=	${WRKSRC}/Source/ThirdParty/StanHull/hull.cpp

GH_PROJECT=	Urho3D

OPTIONS_DEFINE=	EXAMPLES
EXAMPLES_CMAKE_OFF=	-DURHO3D_SAMPLES:BOOL=false

.include <bsd.port.mk>
