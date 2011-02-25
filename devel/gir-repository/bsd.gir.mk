PORTNAME=	gir-repository
PORTVERSION=	0.6.5
PORTREVISION?=	5

MAINTAINER=	gnome@FreeBSD.org

GIRDIR=		${LOCALBASE}/share/gir-1.0

poppler_CATEGORY=	graphics
poppler_GIR=	Poppler-0.8

libnotify_CATEGORY=	devel
libnotify_GIR=	Notify-0.4

vte_CATEGORY=	x11-toolkits
vte_GIR=	Vte-1.0

goocanvas_CATEGORY=	graphics
goocanvas_GIR=	GooCanvas-0.10

.if defined(PKGNAMESUFFIX)

MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

COMMENT?=	Introspection information for ${GIR_NAME}

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
RUN_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig

GIR_NAME=	${PKGNAMESUFFIX:S/-//g}
DEP_NAMES=	${GIR_NAME}

GIRDIR_REL=	${GIRDIR:S,^${LOCALBASE}/,,}
TYPELIBDIR_REL=	lib/girepository-1.0

PLIST=		${NONEXISTENT}

# This list is used to enable/disable gir modules in the configure script.
# So all girs should be here even if we don't use them.
_USE_GIR_ALL=	dbus atk pango pangoxft poppler gtk gconf soup babl nautilusextension \
		gnomekeyring webkit notify gnio clutter clutter_gtk clutter_cairo \
		gstreamer gstbufferlist_h gstreamer_plugins_base gtksourceview vte \
		goocanvas gssdp gupnp avahi unique gmenu wnck

.if ${GIR_NAME} == "poppler"
LIB_DEPENDS+=	poppler-glib.5:${PORTSDIR}/graphics/poppler-gtk
USE_GNOME+=	gtk20
GIR_FILES=	Poppler-0.8
CLEAR_DEPS+=	Gdk-2.0
.endif

.if ${GIR_NAME} == "libnotify"
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
USE_GNOME+=	gtk20
GIR_FILES=	Notify-0.4
DEP_NAMES=	notify
CLEAR_DEPS+=	Gtk-2.0
.endif

.if ${GIR_NAME} == "vte"
USE_GNOME+=	vte
GIR_FILES=	Vte-1.0
CLEAR_DEPS+=	Gtk-2.0
.endif

.if ${GIR_NAME} == "goocanvas"
LIB_DEPENDS+=	goocanvas.3:${PORTSDIR}/graphics/goocanvas
USE_GNOME+=	gtk20
GIR_FILES=	GooCanvas-0.10
CLEAR_DEPS+=	Gtk-2.0
.endif

. for component in ${USE_GIR:C/^([^:]+).*/\1/}
CLEAR_DEPS+=	${${component}_GIR}
BUILD_DEPENDS+=	${GIRDIR}/${${component}_GIR}.gir:${PORTSDIR}/${${component}_CATEGORY}/gir-repository-${component}
RUN_DEPENDS+=	${GIRDIR}/${${component}_GIR}.gir:${PORTSDIR}/${${component}_CATEGORY}/gir-repository-${component}
. endfor

pre-patch:
# disable all components
.for component in ${_USE_GIR_ALL}
	@${REINPLACE_CMD} -e 's|have_${component}=true|have_${component}=false|g' \
		${WRKSRC}/configure
.endfor
.if defined(DEP_NAMES)
# enable components
.for component in ${DEP_NAMES}
	@${REINPLACE_CMD} -e 's|have_${component}=false|have_${component}=true|g' \
		${WRKSRC}/configure
.endfor
.endif

post-configure:
.if defined(CLEAR_DEPS)
# clear Makefile targets
. for dep in ${CLEAR_DEPS}
	@${REINPLACE_CMD} -e 's|${dep}.gir||g' \
		${WRKSRC}/gir/Makefile
. endfor
.endif

.if !target(post-install-script)
post-install-script:
# build plist
.for gir in ${GIR_FILES}
	@${ECHO} ${TYPELIBDIR_REL}/${gir}.typelib >> ${TMPPLIST}
	@${ECHO} ${GIRDIR_REL}/${gir}.gir >> ${TMPPLIST}
.endfor
.for lib in ${LIB_FILES}
	@${ECHO} lib/libgirepo-${lib}-custom.a >> ${TMPPLIST}
	@${ECHO} lib/libgirepo-${lib}-custom.la >> ${TMPPLIST}
	@${ECHO} lib/libgirepo-${lib}-custom.so >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} "@unexec rmdir %D/${TYPELIBDIR_REL} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${GIRDIR_REL} 2>/dev/null || true" >> ${TMPPLIST}
.endif

.endif

.include <bsd.port.mk>
