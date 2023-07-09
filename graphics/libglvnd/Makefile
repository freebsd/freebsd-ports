PORTNAME=	libglvnd
DISTVERSION=	1.6.0
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	GL Vendor-Neutral Dispatch library
WWW=		https://gitlab.freedesktop.org/glvnd/libglvnd

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

USES=		compiler:c++11-lib localbase meson pkgconfig
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	glvnd
GL_COMMIT=	b05bbcdaeb9b700cf7877e6d66f8fc3ac952295b

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

X11_USES=		xorg
X11_USE=		XORG=x11,xext,xorgproto
X11_MESON_ENABLED=	x11 glx

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64le
BUILD_DEPENDS=	as:devel/binutils
CFLAGS+=	-no-integrated-as
.elif ${ARCH} == powerpc64
BUILD_DEPENDS=	as:devel/binutils
CFLAGS+=	-no-integrated-as -O0
.elif ${ARCH} == powerpc || ${ARCH} == riscv64
MESON_ARGS+=	-Dasm=disabled
.endif

# Lots of software expects gl.pc even when it can build with EGL only
post-install-X11-off:
	${LN} -s opengl.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/gl.pc

.include <bsd.port.mk>
