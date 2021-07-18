PORTNAME=	libglvnd
DISTVERSION=	1.3.3
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	GL Vendor-Neutral Dispatch library

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

USES=		localbase meson pkgconfig
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	glvnd
GL_COMMIT=	0f0d49f0f3707f26f68bc44f4cd83144f5f4de86

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

X11_USES=		xorg
X11_USE=		XORG=x11,xext,xorgproto
X11_MESON_ENABLED=	x11 glx

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lib
.endif

# Lots of software expects gl.pc even when it can build with EGL only
post-install-X11-off:
	${LN} -s opengl.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/gl.pc
	${REINPLACE_CMD} -e '/Cflags:/s/$$/ -DEGL_NO_X11/' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/egl.pc

.include <bsd.port.mk>
