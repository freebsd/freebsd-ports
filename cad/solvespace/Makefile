# $FreeBSD$

PORTNAME=	solvespace
PORTVERSION=	2.3
DISTVERSIONPREFIX=	v
PORTREVISION=	5
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

USE_GITHUB=	yes
GH_PROJECT=	libdxfrw:libdxfrw
GH_TAGNAME=	8f95895:libdxfrw
GH_SUBDIR=	extlib/libdxfrw:libdxfrw

USES=		cmake compiler:c++11-lang gl gnome pkgconfig xorg
USE_GL=		gl glu glew
USE_GNOME=	atkmm gtk20 pangomm
USE_XORG=	x11
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

post-patch:
	${REINPLACE_CMD} -e '/-stdlib=libc++/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
