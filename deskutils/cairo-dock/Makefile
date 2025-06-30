PORTNAME=	cairo-dock
DISTVERSION=	3.5.2
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Lightweight and eye-candy dock (program launcher)
WWW=		https://www.glx-dock.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	bash:shells/bash \
		compiz:x11-wm/compiz \
		sox:audio/sox

USES=		cmake gettext-tools gl gnome localbase:ldflags pathfix \
		pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	Cairo-Dock
GH_PROJECT=	${PORTNAME}-core
USE_GL=		glu
USE_GNOME=	cairo glib20 gtk30 librsvg2 libxml2
USE_LDCONFIG=	yes
SHEBANG_FILES=	data/scripts/cairo-dock-package-theme.sh \
		data/scripts/help_scripts.sh data/scripts/initial-setup.sh

LDFLAGS+=	-lm

OPTIONS_DEFINE=		WAYLAND X11
OPTIONS_DEFAULT=	EGL WAYLAND X11
OPTIONS_RADIO=		GL
OPTIONS_RADIO_GL=	EGL GLX

EGL_DESC=	${GLX_DESC:S/X11/Native/}

EGL_USE=		GL=egl
EGL_CMAKE_BOOL=		enable-egl-support
GLX_IMPLIES=		X11
GLX_USE=		GL=gl
WAYLAND_IMPLIES=	EGL
WAYLAND_CATEGORIES=	wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_USE=		GL=egl
WAYLAND_CMAKE_BOOL=	enable-wayland-support
X11_USES=		xorg
X11_USE=		XORG=x11,xcomposite,xinerama,xrandr,xrender,xtst
X11_CMAKE_BOOL=		enable-x11-support

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/pixmaps|${LOCALBASE}/share/pixmaps|g' \
		${WRKSRC}/data/cairo-dock \
		${WRKSRC}/src/gldit/cairo-dock-gui-factory.c
	@${REINPLACE_CMD} -e 's|/usr/share/icons|${LOCALBASE}/share/icons|g' \
		${WRKSRC}/src/gldit/cairo-dock-gui-factory.c \
		${WRKSRC}/src/cairo-dock-user-menu.c
	@${REINPLACE_CMD} -e 's|/usr/share/applications|${LOCALBASE}/share/applications|g' \
		${WRKSRC}/src/gldit/cairo-dock-class-manager.c
	@${FIND} ${WRKSRC} -type f -name "*.desktop" ! -exec ${GREP} -q "${SHAREDIR}/applications" \
		{} \; | \
		${XARGS} ${REINPLACE_CMD} -e 's|/usr/share/applications|${LOCALBASE}/share/applications|g'
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/data/desktop-manager/cairo-dock-session
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|g' \
		${WRKSRC}/data/cairo-dock

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgldi.so

.include <bsd.port.mk>
