# $FreeBSD$

PORTNAME=	libepoxy
PORTVERSION=	1.5.2
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/anholt/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library to handle OpenGL function pointer management

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl localbase meson pkgconfig python:3.3+,build tar:xz xorg
USE_XORG=	x11
USE_GL=		gl glesv2 egl
USE_LDCONFIG=	yes

.include <bsd.port.mk>
