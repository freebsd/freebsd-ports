PORTNAME=	solvespace
PORTVERSION=	3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	cad

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Parametric 2d/3d CAD

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libjson-c.so:devel/json-c \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lang gl gnome pkgconfig xorg
USE_GL=		gl glu glew
USE_GNOME=	gtkmm30 pangomm
USE_XORG=	x11
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft:mimalloc
GH_PROJECT=	libdxfrw:libdxfrw mimalloc:mimalloc
GH_TAGNAME=	0b7b7b7:libdxfrw 38a0322:mimalloc
GH_SUBDIR=	extlib/libdxfrw:libdxfrw extlib/mimalloc:mimalloc

INSTALLS_ICONS=	YES

post-patch:
	${REINPLACE_CMD} -e '/-stdlib=libc++/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
