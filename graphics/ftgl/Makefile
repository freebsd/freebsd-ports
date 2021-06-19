# Created by: Igor Pokrovsky <tiamat@comset.net>

PORTNAME=	ftgl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OpenGL FreeType fonts rendering library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USE_GITHUB=	yes
GH_ACCOUNT=	frankheckenbach

USES=		autoreconf compiler:c++11-lang gl pathfix gmake libtool \
		pkgconfig xorg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gl-inc="${LOCALBASE}/include" \
		--without-glut-inc
USE_GL=		gl glu
USE_XORG=	ice sm x11 xext xmu
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e '/SUBDIRS/ s|docs||; /SUBDIRS/ s|demo||' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
