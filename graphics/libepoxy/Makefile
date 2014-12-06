# $FreeBSD$

PORTNAME=	libepoxy
PORTVERSION=	1.2
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library to handle OpenGL function pointer management

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	anholt
GH_COMMIT=	7422de5
GH_TAGNAME=	v${PORTVERSION}

USES=		autoreconf libtool pathfix pkgconfig python:3,build
USE_XORG=	xorg-macros x11
USE_GL=		egl glesv2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PATHFIX_MAKEFILEIN=	Makefile.am

.include <bsd.port.mk>
