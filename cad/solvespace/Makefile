# $FreeBSD$

PORTNAME=	solvespace
PORTVERSION=	2.3
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	cad

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Parametric 2d/3d CAD

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libjson-c.so:devel/json-c \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgtkmm-2.4.so:x11-toolkits/gtkmm24

BROKEN_powerpc64=	fails to compile: cc1plus: unrecognized command line option "-std=c++11"

USE_GITHUB=	yes
GH_PROJECT=	libdxfrw:libdxfrw
GH_TAGNAME=	8f95895:libdxfrw
GH_SUBDIR=	extlib/libdxfrw:libdxfrw

USES=		cmake pkgconfig
USE_GL=		gl glu glew
USE_GNOME=	atkmm gtk20 pangomm
USE_XORG=	x11
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
