# $FreeBSD$

PORTNAME=	libglvnd
DISTVERSION=	1.3.1
CATEGORIES=	graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GL Vendor-Neutral Dispatch library

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

CONFLICTS_INSTALL=	mesa-libs # include/GL/gl.h

USES=		compiler:c++11-lib localbase meson pkgconfig
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	glvnd
GL_COMMIT=	1c32de07074fee8edcb274899948b6551081ed54

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

X11_USES=		xorg
X11_USE=		XORG=x11,xext,xorgproto
X11_MESON_ENABLED=	x11 glx

# Lots of software expects gl.pc even when it can build with EGL only
post-install-X11-off:
	${LN} -s opengl.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/gl.pc
	${REINPLACE_CMD} -e '/Cflags:/s/$$/ -DEGL_NO_X11/' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/egl.pc

.include <bsd.port.mk>
