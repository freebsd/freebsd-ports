# $FreeBSD$

PORTNAME=	libepoxy
PORTVERSION=	1.5.4
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library to handle OpenGL function pointer management

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl localbase meson pkgconfig python:3.3+,build xorg
USE_GITHUB=	yes
GH_ACCOUNT=	anholt
USE_XORG=	x11
USE_GL=		gl glesv2 egl
USE_LDCONFIG=	yes

.include <bsd.port.mk>
