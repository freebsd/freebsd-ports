# $FreeBSD$

PORTNAME=	libepoxy
PORTVERSION=	1.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library to handle OpenGL function pointer management

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	anholt

USES=		autoreconf libtool pathfix pkgconfig python:build
USE_XORG=	xorg-macros x11
USE_GL=		egl glesv2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
