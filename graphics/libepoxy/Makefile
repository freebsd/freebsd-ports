# $FreeBSD$

PORTNAME=       libepoxy
PORTVERSION=    1.2
CATEGORIES=     graphics

MAINTAINER=     x11@FreeBSD.org
COMMENT=        library that handles OpenGL function pointer managerment for you

LICENSE=        MIT

USE_GITHUB=     YES
GH_ACCOUNT=     anholt
GH_PROJECT=     ${PORTNAME}
GH_COMMIT=      7422de5
GH_TAGNAME=     v1.2

USES=		autoreconf libtool pathfix pkgconfig python:3,build
USE_XORG=	xorg-macros
USE_GL=		egl glesv2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PATHFIX_MAKEFILEIN=	Makefile.am

# GLX
USE_XORG+=	x11

.include <bsd.port.mk>
