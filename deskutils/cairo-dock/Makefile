# $FreeBSD$

PORTNAME=	cairo-dock
PORTVERSION=	3.4.1
PORTREVISION=	4
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cairo-Dock is a light and eye-candy dock

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext
RUN_DEPENDS=	bash:shells/bash \
		sox:audio/sox

USE_GITHUB=	yes
GH_ACCOUNT=	Cairo-Dock
GH_PROJECT=	${PORTNAME}-core

GNU_CONFIGURE=	yes
USES=		cmake compiler:c++11-lang gettext gl gnome localbase:ldflags \
		pkgconfig
USE_GL=		glu
USE_GNOME=	glib20 gtk30 librsvg2 libxml2
USE_LDCONFIG=	yes
CMAKE_ARGS=	-Dinstall-pc-path:STRING="${LOCALBASE}/libdata/pkgconfig" \
		-DROOT_PREFIX:PATH=${STAGEDIR} \
		-DCMAKE_INSTALL_MANDIR:PATH=man \

OPTIONS_DEFINE=	X11 WAYLAND
OPTIONS_DEFAULT=EGL WAYLAND X11
OPTIONS_RADIO=	GL
OPTIONS_RADIO_GL=	GLX EGL

EGL_DESC=		${GLX_DESC:S/X11/Native/}
EGL_CMAKE_BOOL=		enable-egl-support
EGL_USE=		GL=egl

GLX_USE=		GL=gl
GLX_IMPLIES=		X11

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_USE=		GL=egl
WAYLAND_CMAKE_BOOL=	enable-wayland-support
WAYLAND_IMPLIES=	EGL

X11_USES=		xorg
X11_USE=		XORG=x11,xcomposite,xinerama,xrandr,xrender,xtst
X11_CMAKE_BOOL=		enable-x11-support

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*" | ${XARGS} ${REINPLACE_CMD} -e \
	    's|/usr/share/pixmaps/|${LOCALBASE}/share/pixmaps/|g; \
	     s|/usr/bin/cairo-dock|${LOCALBASE}/bin/cairo-dock|g; \
	     s|/bin/bash|${LOCALBASE}/bin/bash|g; \
	     s|/usr/share/applications|${LOCALBASE}/share/applications|g; \
	     s|/usr/share/icons|${LOCALBASE}/share/icons|g; \
	     s|%%LOCALBASE%%|${LOCALBASE}|g;'

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgldi.so

.include <bsd.port.mk>
