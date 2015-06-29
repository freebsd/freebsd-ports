#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#	$NetBSD: $
#     $MCom: ports/trunk/Mk/bsd.gnome.mk 20033 2014-11-02 23:07:27Z kwm $
#
# Please view me with 4 column tabs!

#######################################################
#
# *** WARNING: Disable MARCUSCOM before merge in FreeBSD!
#     Please also remove this section before merging into FreeBSD.
#
#MARCUSCOM_CVS=yes

# ======================= USERS =================================
#
# There are no significant user-definable settings in here.
# This file is a framework to make it easier to create GNOME ports.
#
# ======================= /USERS ================================

.if !defined(_POSTMKINCLUDED) && !defined(Gnome_Pre_Include)

# Please make sure all changes to this file are passed through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Gnome_Include_MAINTAINER=	gnome@FreeBSD.org
Gnome_Pre_Include=			bsd.gnome.mk

# This section defines possible names of GNOME components and all information
# necessary for ports to use those components.

# Ports can use this as follows:
#
# USE_GNOME=	glib20 introspection:build
#
# .include <bsd.port.mk>
#
# As a result proper LIB_DEPENDS/RUN_DEPENDS will be added and CONFIGURE_ENV
# and MAKE_ENV defined.
#
#
# GCONF_SCHEMAS		- Set the following to list of all the gconf schema files
#				that your port installs. These schema files and
#				%gconf.xml files will be automatically added to
#				the ${PLIST}. For example, if your port has
#				"etc/gconf/schemas/(foo.schemas and bar.schemas)",
#				add the following to your Makefile:
#				"GCONF_SCHEMAS=foo.schemas bar.schemas".
#
# GLIB_SCHEMAS		- Set the following to list of all gsettings schema files
#				(*.gschema.xml) that your ports installs. The 
#				schema files will be automatically added to 
#				the ${PLIST}. For example, if your port has 
#				"share/glib-2.0/schemas/(foo.gschema.xml and bar.gschema.xml)", 
#				add the following to your Makefile:
#				"GLIB_SCHEMAS=foo.gschema.xml bar.gschema.xml".
#
# INSTALLS_OMF		- If set, bsd.gnome.mk will automatically scan pkg-plist
#				file and add apropriate @exec/@unexec directives for
#				each .omf file found to track OMF registration database.
#
# INSTALLS_ICONS	- If a GTK+ port installs Freedesktop-style icons to
#				${LOCALBASE}/share/icons, then you should use this
#				macro. Using this macro ensures that icons are cached
#				and will display correctly. This macro isn't needed
#				for QT based applications, which use a different method.
#

# non-version specific components
_USE_GNOME_ALL= esound intlhack intltool introspection \
		referencehack gnomemimedata \
		gnomeprefix

# GNOME 1 components
_USE_GNOME_ALL+= gdkpixbuf glib12 gtk12

# GNOME 2 components
_USE_GNOME_ALL+= atk atspi cairo gal2 \
		gdkpixbuf2 gconf2 glib20 \
		gnomedocutils gnomesharp20 \
		gnomespeech gnomevfs2 gtk-update-icon-cache gtk20 gtkhtml3 gtksharp10 \
		gtksharp20 gtksourceview gtksourceview2 gvfs libartlgpl2 libbonobo \
		libbonoboui libgda4 libglade2 libgnome \
		libgnomecanvas libgnomedb libgnomekbd libgnomeprint libgnomeprintui \
		libgnomeui libgsf libgtkhtml libidl librsvg2 libwnck \
		libxml2 libxslt linc \
		orbit2 pango pangox-compat pygnome2 pygobject pygtk2 \
		pygtksourceview vte

# GNOME 3 components
_USE_GNOME_ALL+=dconf evolutiondataserver3 gnomecontrolcenter3 gnomedesktop3 \
		gnomemenus3 gtk30 gtkhtml4 gtksourceview3 libgda5 \
		libgda5-ui libwnck3 metacity nautilus3 py3gobject3 \
		pygobject3 vte3

# C++ bindings
_USE_GNOME_ALL+=atkmm cairomm gconfmm26 glibmm gtkmm20 gtkmm24 \
		gtkmm30 gtksourceviewmm3 libgdamm libgdamm5 \
		libgtksourceviewmm libxml++26 libsigc++12 libsigc++20 \
		pangomm

GNOME_MAKEFILEIN?=	Makefile.in
SCROLLKEEPER_DIR=	/var/db/rarian

referencehack_PRE_PATCH=	${FIND} ${WRKSRC} -name "Makefile.in" -type f | ${XARGS} ${REINPLACE_CMD} -e \
				"s|test \"\$$\$$installfiles\" = '\$$(srcdir)/html/\*'|:|"

GNOME_HTML_DIR?=	${PREFIX}/share/doc
GCONF_CONFIG_OPTIONS?=	merged
GCONF_CONFIG_DIRECTORY?=etc/gconf/gconf.xml.defaults
GCONF_CONFIG_SOURCE?=xml:${GCONF_CONFIG_OPTIONS}:${PREFIX}/${GCONF_CONFIG_DIRECTORY}
GNOME_LOCALSTATEDIR?=	${PREFIX}/share
gnomeprefix_CONFIGURE_ENV=GTKDOC="false"
gnomeprefix_CONFIGURE_ARGS=--localstatedir=${GNOME_LOCALSTATEDIR} \
			   --with-html-dir=${GNOME_HTML_DIR} \
			   --disable-gtk-doc \
			   --with-gconf-source=${GCONF_CONFIG_SOURCE}

atkmm_DETECT=		${LOCALBASE}/libdata/pkgconfig/atkmm-1.6.pc
atkmm_LIB_DEPENDS=	libatkmm-1.6.so:${PORTSDIR}/accessibility/atkmm
atkmm_USE_GNOME_IMPL=	glibmm atk

libxml++26_DETECT=		${LOCALBASE}/libdata/pkgconfig/libxml++-2.6.pc
libxml++26_LIB_DEPENDS=		libxml++-2.6.so:${PORTSDIR}/textproc/libxml++26
libxml++26_USE_GNOME_IMPL=	glibmm libxml2

cairo_DETECT=		${LOCALBASE}/libdata/pkgconfig/cairo.pc
cairo_LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo

cairomm_DETECT=		${LOCALBASE}/libdata/pkgconfig/cairomm-1.0.pc
cairomm_LIB_DEPENDS=	libcairomm-1.0.so:${PORTSDIR}/graphics/cairomm
cairomm_USE_GNOME_IMPL=	cairo libxml++26

gconfmm26_DETECT=		${LOCALBASE}/libdata/pkgconfig/gconfmm-2.6.pc
gconfmm26_LIB_DEPENDS=		libgconfmm-2.6.so:${PORTSDIR}/devel/gconfmm26
gconfmm26_USE_GNOME_IMPL=	glibmm gconf2

glibmm_DETECT=		${LOCALBASE}/libdata/pkgconfig/glibmm-2.4.pc
glibmm_LIB_DEPENDS=	libglibmm-2.4.so:${PORTSDIR}/devel/glibmm
glibmm_USE_GNOME_IMPL=	libsigc++20 glib20

gtkmm20_DETECT=		${LOCALBASE}/libdata/pkgconfig/gtkmm-2.0.pc
gtkmm20_LIB_DEPENDS=	libgtkmm-2.0.so:${PORTSDIR}/x11-toolkits/gtkmm20
gtkmm20_USE_GNOME_IMPL=	libsigc++12 gtk20

gtkmm24_DETECT=		${LOCALBASE}/libdata/pkgconfig/gtkmm-2.4.pc
gtkmm24_LIB_DEPENDS=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24
gtkmm24_USE_GNOME_IMPL=	glibmm cairomm atkmm pangomm gtk20

gtkmm30_DETECT=		${LOCALBASE}/libdata/pkgconfig/gtkmm-3.0.pc
gtkmm30_LIB_DEPENDS=	libgtkmm-3.0.so:${PORTSDIR}/x11-toolkits/gtkmm30
gtkmm30_USE_GNOME_IMPL=	glibmm cairomm atkmm pangomm gtk30

gtksourceviewmm3_DETECT=		${LOCALBASE}/libdata/pkgconfig/gtksourceviewmm-3.0.pc
gtksourceviewmm3_LIB_DEPENDS=		libgtksourceviewmm-3.0.so:${PORTSDIR}/x11-toolkits/gtksourceviewmm3
gtksourceviewmm3_USE_GNOME_IMPL=	gtkmm30 gtksourceview3

libgdamm_DETECT=	${LOCALBASE}/libdata/pkgconfig/libgdamm-4.0.pc
libgdamm_LIB_DEPENDS=	libgdamm-4.0.so:${PORTSDIR}/databases/libgdamm
libgdamm_USE_GNOME_IMPL=libgda4 glibmm

libgdamm5_DETECT=		${LOCALBASE}/libdata/pkgconfig/libgdamm-5.0.pc
libgdamm5_LIB_DEPENDS=		libgdamm-5.0.so:${PORTSDIR}/databases/libgdamm5
libgdamm5_USE_GNOME_IMPL=	libgda5 glibmm

libgtksourceviewmm_DETECT=		${LOCALBASE}/libdata/pkgconfig/gtksourceviewmm-2.0.pc
libgtksourceviewmm_LIB_DEPENDS=		libgtksourceviewmm-2.0.so:${PORTSDIR}/x11-toolkits/libgtksourceviewmm
libgtksourceviewmm_USE_GNOME_IMPL=	gtksourceview2 gtkmm24

libsigc++12_DETECT=		${LOCALBASE}/libdata/pkgconfig/sigc++-1.2.pc
libsigc++12_LIB_DEPENDS=	libsigc-1.2.so:${PORTSDIR}/devel/libsigc++12

libsigc++20_DETECT=		${LOCALBASE}/libdata/pkgconfig/sigc++-2.0.pc
libsigc++20_LIB_DEPENDS=	libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20

pangomm_DETECT=		${LOCALBASE}/libdata/pkgconfig/pangomm-1.4.pc
pangomm_LIB_DEPENDS=	libpangomm-1.4.so:${PORTSDIR}/x11-toolkits/pangomm
pangomm_USE_GNOME_IMPL=	pango glibmm cairomm

ESD_CONFIG?=		${LOCALBASE}/bin/esd-config
esound_LIB_DEPENDS=	libesd.so:${PORTSDIR}/audio/esound
esound_CONFIGURE_ENV=	ESD_CONFIG="${ESD_CONFIG}"
esound_MAKE_ENV=	ESD_CONFIG="${ESD_CONFIG}"
esound_DETECT=		${ESD_CONFIG}

GLIB_CONFIG?=		${LOCALBASE}/bin/glib-config
glib12_LIB_DEPENDS=	libglib.so:${PORTSDIR}/devel/glib12
glib12_CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}"
glib12_MAKE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}"
glib12_DETECT=		${GLIB_CONFIG}

GTK_CONFIG?=		${LOCALBASE}/bin/gtk-config
gtk12_LIB_DEPENDS=	libgtk.so:${PORTSDIR}/x11-toolkits/gtk12
gtk12_CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
gtk12_MAKE_ENV=		GTK_CONFIG="${GTK_CONFIG}"
gtk12_DETECT=		${GTK_CONFIG}
gtk12_USE_GNOME_IMPL=	glib12

GDK_PIXBUF_CONFIG?=	${LOCALBASE}/bin/gdk-pixbuf-config
gdkpixbuf_LIB_DEPENDS=	libgdk_pixbuf.so:${PORTSDIR}/graphics/gdk-pixbuf
gdkpixbuf_CONFIGURE_ENV=GDK_PIXBUF_CONFIG="${GDK_PIXBUF_CONFIG}"
gdkpixbuf_MAKE_ENV=	GDK_PIXBUF_CONFIG="${GDK_PIXBUF_CONFIG}"
gdkpixbuf_DETECT=	${GDK_PIXBUF_CONFIG}
gdkpixbuf_USE_GNOME_IMPL=gtk12

gnomemimedata_DETECT=	${LOCALBASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc
gnomemimedata_BUILD_DEPENDS=${gnomemimedata_DETECT}:${PORTSDIR}/misc/gnome-mime-data
gnomemimedata_RUN_DEPENDS=${gnomemimedata_DETECT}:${PORTSDIR}/misc/gnome-mime-data

glib20_LIB_DEPENDS=	libglib-2.0.so:${PORTSDIR}/devel/glib20
glib20_DETECT=		${LOCALBASE}/libdata/pkgconfig/glib-2.0.pc

atk_LIB_DEPENDS=	libatk-1.0.so:${PORTSDIR}/accessibility/atk
atk_DETECT=		${LOCALBASE}/libdata/pkgconfig/atk.pc
atk_USE_GNOME_IMPL=	glib20

dconf_LIB_DEPENDS=	libdconf.so:${PORTSDIR}/devel/dconf
dconf_DETECT=		${LOCALBASE}/libdata/pkgconfig/dconf.pc
dconf_USE_GNOME_IMPL=	glib20

pango_LIB_DEPENDS=	libpango-1.0.so:${PORTSDIR}/x11-toolkits/pango
pango_DETECT=		${LOCALBASE}/libdata/pkgconfig/pango.pc
pango_USE_GNOME_IMPL=	glib20

pangox-compat_LIB_DEPENDS=	libpangox-1.0.so:${PORTSDIR}/x11-toolkits/pangox-compat
pangox-compat_DETECT=		${LOCALBASE}/libdata/pkgconfig/pangox.pc
pangox-compat_USE_GNOME_IMPL=	glib20 pango

gdkpixbuf2_LIB_DEPENDS=	libgdk_pixbuf-2.0.so:${PORTSDIR}/graphics/gdk-pixbuf2
gdkpixbuf2_DETECT=	${LOCALBASE}/libdata/pkgconfig/gdk-pixbuf-2.0.pc
gdkpixbuf2_USE_GNOME_IMPL=glib20

gtk-update-icon-cache_BUILD_DEPENDS=	gtk-update-icon-cache:${PORTSDIR}/graphics/gtk-update-icon-cache
gtk-update-icon-cache_RUN_DEPENDS=	gtk-update-icon-cache:${PORTSDIR}/graphics/gtk-update-icon-cache
gtk-update-icon-cache_DETECT=		${LOCALBASE}/bin/gtk-update-icon-cache
gtk-update-icon-cache_USE_GNOME_IMPL=	atk pango gdkpixbuf2

gtk20_LIB_DEPENDS=	libgtk-x11-2.0.so:${PORTSDIR}/x11-toolkits/gtk20
gtk20_DETECT=		${LOCALBASE}/libdata/pkgconfig/gtk+-x11-2.0.pc
gtk20_USE_GNOME_IMPL=	intltool atk pango
GTK2_VERSION=		2.10.0

gtk30_LIB_DEPENDS=	libgtk-3.so:${PORTSDIR}/x11-toolkits/gtk30
gtk30_DETECT=		${LOCALBASE}/libdata/pkgconfig/gtk+-3.0.pc
gtk30_USE_GNOME_IMPL=	intltool atk pango
GTK3_VERSION=		3.0.0

linc_LIB_DEPENDS=	liblinc.so:${PORTSDIR}/net/linc
linc_DETECT=		${LOCALBASE}/libdata/pkgconfig/linc.pc
linc_USE_GNOME_IMPL=	glib20

libidl_LIB_DEPENDS=	libIDL-2.so:${PORTSDIR}/devel/libIDL
libidl_DETECT=		${LOCALBASE}/libdata/pkgconfig/libIDL-2.0.pc
libidl_USE_GNOME_IMPL=	glib20

orbit2_LIB_DEPENDS=	libORBit-2.so:${PORTSDIR}/devel/ORBit2
orbit2_DETECT=		${LOCALBASE}/libdata/pkgconfig/ORBit-2.0.pc
orbit2_USE_GNOME_IMPL=	libidl

libglade2_LIB_DEPENDS=	libglade-2.0.so:${PORTSDIR}/devel/libglade2
libglade2_DETECT=	${LOCALBASE}/libdata/pkgconfig/libglade-2.0.pc
libglade2_USE_GNOME_IMPL=libxml2 gtk20

libxml2_BUILD_DEPENDS=	xml2-config:${PORTSDIR}/textproc/libxml2
libxml2_LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2
libxml2_RUN_DEPENDS=	xml2-config:${PORTSDIR}/textproc/libxml2
libxml2_DETECT=		${LOCALBASE}/libdata/pkgconfig/libxml-2.0.pc

libxslt_BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
libxslt_LIB_DEPENDS=	libxslt.so:${PORTSDIR}/textproc/libxslt
libxslt_RUN_DEPENDS=	${libxslt_BUILD_DEPENDS}
libxslt_DETECT=		${LOCALBASE}/libdata/pkgconfig/libxslt.pc
libxslt_USE_GNOME_IMPL=	libxml2

libbonobo_LIB_DEPENDS=	libbonobo-2.so:${PORTSDIR}/devel/libbonobo
libbonobo_DETECT=	${LOCALBASE}/libdata/pkgconfig/libbonobo-2.0.pc
libbonobo_USE_GNOME_IMPL=libxml2 orbit2

introspection_DETECT=		${LOCALBASE}/libdata/pkgconfig/gobject-introspection-1.0.pc
introspection_BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
introspection_LIB_DEPENDS=	libgirepository-1.0.so:${PORTSDIR}/devel/gobject-introspection
introspection_RUN_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
introspection_USE_GNOME_IMPL=	glib20
introspection_MAKE_ENV=		GI_SCANNER_DISABLE_CACHE=1 XDG_CACHE_HOME=${WRKDIR}

gconf2_LIB_DEPENDS=	libgconf-2.so:${PORTSDIR}/devel/gconf2
gconf2_DETECT=		${LOCALBASE}/libdata/pkgconfig/gconf-2.0.pc
gconf2_USE_GNOME_IMPL=	orbit2 libxml2 gtk20

gnomevfs2_LIB_DEPENDS=	libgnomevfs-2.so:${PORTSDIR}/devel/gnome-vfs
gnomevfs2_DETECT=	${LOCALBASE}/libdata/pkgconfig/gnome-vfs-2.0.pc
gnomevfs2_USE_GNOME_IMPL=gconf2 gnomemimedata

libgnomecanvas_LIB_DEPENDS=	libgnomecanvas-2.so:${PORTSDIR}/graphics/libgnomecanvas
libgnomecanvas_DETECT=		${LOCALBASE}/libdata/pkgconfig/libgnomecanvas-2.0.pc
libgnomecanvas_USE_GNOME_IMPL=	libglade2 libartlgpl2

libartlgpl2_LIB_DEPENDS=	libart_lgpl_2.so:${PORTSDIR}/graphics/libart_lgpl
libartlgpl2_DETECT=		${LOCALBASE}/libdata/pkgconfig/libart-2.0.pc

libgnomeprint_LIB_DEPENDS=	libgnomeprint-2-2.so:${PORTSDIR}/print/libgnomeprint
libgnomeprint_DETECT=		${LOCALBASE}/libdata/pkgconfig/libgnomeprint-2.2.pc
libgnomeprint_USE_GNOME_IMPL=	libbonobo libartlgpl2 gtk20

libgnomeprintui_LIB_DEPENDS=	libgnomeprintui-2-2.so:${PORTSDIR}/x11-toolkits/libgnomeprintui
libgnomeprintui_DETECT=		${LOCALBASE}/libdata/pkgconfig/libgnomeprintui-2.2.pc
libgnomeprintui_USE_GNOME_IMPL=	libgnomeprint libgnomecanvas

libgnome_LIB_DEPENDS=	libgnome-2.so:${PORTSDIR}/x11/libgnome
libgnome_DETECT=	${LOCALBASE}/libdata/pkgconfig/libgnome-2.0.pc
libgnome_USE_GNOME_IMPL=gnomevfs2 esound libbonobo

libbonoboui_LIB_DEPENDS=	libbonoboui-2.so:${PORTSDIR}/x11-toolkits/libbonoboui
libbonoboui_DETECT=		${LOCALBASE}/libdata/pkgconfig/libbonoboui-2.0.pc
libbonoboui_USE_GNOME_IMPL=	libgnomecanvas libgnome

libgnomeui_LIB_DEPENDS=		libgnomeui-2.so:${PORTSDIR}/x11-toolkits/libgnomeui
libgnomeui_DETECT=		${LOCALBASE}/libdata/pkgconfig/libgnomeui-2.0.pc
libgnomeui_USE_GNOME_IMPL=	libbonoboui

atspi_LIB_DEPENDS=	libspi.so:${PORTSDIR}/accessibility/at-spi
atspi_DETECT=		${LOCALBASE}/libdata/pkgconfig/cspi-1.0.pc
atspi_USE_GNOME_IMPL=	gtk20 libbonobo

libgtkhtml_LIB_DEPENDS=	libgtkhtml-2.so:${PORTSDIR}/www/libgtkhtml
libgtkhtml_DETECT=	${LOCALBASE}/libdata/pkgconfig/libgtkhtml-2.0.pc
libgtkhtml_USE_GNOME_IMPL=libxslt gnomevfs2

gnomedesktop3_LIB_DEPENDS=	libgnome-desktop-3.so:${PORTSDIR}/x11/gnome-desktop
gnomedesktop3_DETECT=		${LOCALBASE}/libdata/pkgconfig/gnome-desktop-3.0.pc
gnomedesktop3_USE_GNOME_IMPL=	gtk30

libwnck_LIB_DEPENDS=	libwnck-1.so:${PORTSDIR}/x11-toolkits/libwnck
libwnck_DETECT=		${LOCALBASE}/libdata/pkgconfig/libwnck-1.0.pc
libwnck_USE_GNOME_IMPL=	gtk20

libwnck3_LIB_DEPENDS=	libwnck-3.so:${PORTSDIR}/x11-toolkits/libwnck3
libwnck3_DETECT=	${LOCALBASE}/libdata/pkgconfig/libwnck-3.0.pc
libwnck3_USE_GNOME_IMPL=gtk30

vte_LIB_DEPENDS=	libvte.so:${PORTSDIR}/x11-toolkits/vte
vte_DETECT=		${LOCALBASE}/libdata/pkgconfig/vte.pc
vte_USE_GNOME_IMPL=	gtk20

vte3_LIB_DEPENDS=	libvte-2.91.so:${PORTSDIR}/x11-toolkits/vte3
vte3_DETECT=		${LOCALBASE}/libdata/pkgconfig/vte-2.91.pc
vte3_USE_GNOME_IMPL=	gtk30

librsvg2_LIB_DEPENDS=	librsvg-2.so:${PORTSDIR}/graphics/librsvg2
librsvg2_DETECT=	${LOCALBASE}/libdata/pkgconfig/librsvg-2.0.pc
librsvg2_USE_GNOME_IMPL=libgsf gtk20

nautilus3_LIB_DEPENDS=	libnautilus-extension.so:${PORTSDIR}/x11-fm/nautilus
nautilus3_DETECT=	${LOCALBASE}/share/gir-1.0/Nautilus-3.0.gir
nautilus3_USE_GNOME_IMPL=gnomedesktop3 gvfs libxml2
nautilus3_GNOME_DESKTOP_VERSION=3

metacity_LIB_DEPENDS=	libmetacity-private.so:${PORTSDIR}/x11-wm/metacity
metacity_DETECT=	${LOCALBASE}/libdata/pkgconfig/libmetacity-private.pc
metacity_GNOME_DESKTOP_VERSION=3

gal2_LIB_DEPENDS=	libgal-2.4.so:${PORTSDIR}/x11-toolkits/gal2
gal2_DETECT=		${LOCALBASE}/libdata/pkgconfig/gal-2.4.pc
gal2_USE_GNOME_IMPL=gnomeui libgnomeprintui

gnomecontrolcenter3_DETECT=	${LOCALBASE}/libdata/pkgconfig/gnome-keybindings.pc
gnomecontrolcenter3_BUILD_DEPENDS=	${gnomecontrolcenter3_DETECT}:${PORTSDIR}/sysutils/gnome-control-center
gnomecontrolcenter3_RUN_DEPENDS=	${gnomecontrolcenter3_DETECT}:${PORTSDIR}/sysutils/gnome-control-center
gnomecontrolcenter3_USE_GNOME_IMPL=	gnomedesktop3
gnomecontrolcenter3_GNOME_DESKTOP_VERSION=3

libgda4_LIB_DEPENDS=	libgda-4.0.so:${PORTSDIR}/databases/libgda4
libgda4_DETECT=		${LOCALBASE}/libdata/pkgconfig/libgda-4.0.pc
libgda4_USE_GNOME_IMPL=	glib20 libxslt

libgda5_LIB_DEPENDS=	libgda-5.0.so:${PORTSDIR}/databases/libgda5
libgda5_DETECT=		${LOCALBASE}/libdata/pkgconfig/libgda-5.0.pc
libgda5_USE_GNOME_IMPL=	glib20 libxslt

libgda5-ui_LIB_DEPENDS=	libgda-ui-5.0.so:${PORTSDIR}/databases/libgda5-ui
libgda5-ui_DETECT=	${LOCALBASE}/libdata/pkgconfig/libgda-ui-5.0.pc
libgda5-ui_USE_GNOME_IMPL=glib20 libxslt libgda5

libgnomedb_LIB_DEPENDS=	libgnomedb-3.0.so:${PORTSDIR}/databases/libgnomedb
libgnomedb_DETECT=	${LOCALBASE}/libdata/pkgconfig/libgnomedb.pc
libgnomedb_USE_GNOME_IMPL=libgnomeui libgda3

gtksourceview_LIB_DEPENDS=	libgtksourceview-1.0.so:${PORTSDIR}/x11-toolkits/gtksourceview
gtksourceview_DETECT=	${LOCALBASE}/libdata/pkgconfig/gtksourceview-1.0.pc
gtksourceview_USE_GNOME_IMPL=libgnome libgnomeprintui

gtksourceview2_LIB_DEPENDS=	libgtksourceview-2.0.so:${PORTSDIR}/x11-toolkits/gtksourceview2
gtksourceview2_DETECT=	${LOCALBASE}/libdata/pkgconfig/gtksourceview-2.0.pc
gtksourceview2_USE_GNOME_IMPL=gtk20 libxml2

gtksourceview3_LIB_DEPENDS=	libgtksourceview-3.0.so:${PORTSDIR}/x11-toolkits/gtksourceview3
gtksourceview3_DETECT=	${LOCALBASE}/libdata/pkgconfig/gtksoureview-3.0.pc
gtksourceview3_USE_GNOME_IMPL=gtk30 libxml2

libgsf_LIB_DEPENDS=	libgsf-1.so:${PORTSDIR}/devel/libgsf
libgsf_DETECT=		${LOCALBASE}/libdata/pkgconfig/libgsf-1.pc
libgsf_USE_GNOME_IMPL=	glib20 libxml2

pygobject_DETECT=		${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc
pygobject_BUILD_DEPENDS=	pygobject-codegen-2.0:${PORTSDIR}/devel/py-gobject
pygobject_RUN_DEPENDS=		pygobject-codegen-2.0:${PORTSDIR}/devel/py-gobject
pygobject_USE_GNOME_IMPL=	glib20

py3gobject3_DETECT=		${LOCALBASE}/share/py3gobject3/.keep
py3gobject3_BUILD_DEPENDS=	py3?-gobject3>=0:${PORTSDIR}/devel/py3-gobject3
py3gobject3_RUN_DEPENDS=	py3?-gobject3>=0:${PORTSDIR}/devel/py3-gobject3
py3gobject3_USE_GNOME_IMPL=	glib20

pygobject3_DETECT=		${LOCALBASE}/share/pygobject3/.keep
pygobject3_BUILD_DEPENDS=	py2?-gobject3>=0:${PORTSDIR}/devel/py-gobject3
pygobject3_RUN_DEPENDS=		py2?-gobject3>=0:${PORTSDIR}/devel/py-gobject3
pygobject3_USE_GNOME_IMPL=	glib20

pygtk2_DETECT=		${LOCALBASE}/libdata/pkgconfig/pygtk-2.0.pc
pygtk2_BUILD_DEPENDS=	${pygtk2_DETECT}:${PORTSDIR}/x11-toolkits/py-gtk2
pygtk2_RUN_DEPENDS=	${pygtk2_DETECT}:${PORTSDIR}/x11-toolkits/py-gtk2
pygtk2_USE_GNOME_IMPL=	libglade2 pygobject

pygnome2_DETECT=	${LOCALBASE}/libdata/pkgconfig/gnome-python-2.0.pc
pygnome2_BUILD_DEPENDS=	${pygnome2_DETECT}:${PORTSDIR}/x11-toolkits/py-gnome2
pygnome2_RUN_DEPENDS=	${pygnome2_DETECT}:${PORTSDIR}/x11-toolkits/py-gnome2
pygnome2_USE_GNOME_IMPL=libgnomeui pygtk2

intltool_DETECT=	${LOCALBASE}/bin/intltool-extract
intltool_BUILD_DEPENDS=	${intltool_DETECT}:${PORTSDIR}/textproc/intltool

intlhack_PRE_PATCH=	${FIND} ${WRKSRC} -name "intltool-merge.in" | ${XARGS} ${REINPLACE_CMD} \
			's|mkdir $$lang or|mkdir $$lang, 0777 or| ; \
			 s|^push @INC, "/.*|push @INC, "${LOCALBASE}/share/intltool";| ; \
			 s|/usr/bin/iconv|${ICONV_CMD}|g ; \
			 s|unpack *[(]'"'"'U\*'"'"'|unpack ('"'"'C*'"'"'|' ; \
			${FIND} ${WRKSRC} -name configure | ${XARGS} ${REINPLACE_CMD} \
			's/DATADIRNAME=lib/DATADIRNAME=share/'
intlhack_USE_GNOME_IMPL=intltool

gtkhtml3_LIB_DEPENDS=	libgtkhtml-3.14.so:${PORTSDIR}/www/gtkhtml3
gtkhtml3_DETECT=	${LOCALBASE}/libdata/pkgconfig/libgtkhtml-3.14.pc
gtkhtml3_USE_GNOME_IMPL=libglade2

gtkhtml4_LIB_DEPENDS=	libgtkhtml-4.0.so:${PORTSDIR}/www/gtkhtml4
gtkhtml4_DETECT=	${LOCALBASE}/libdata/pkgconfig/libgtkhtml-4.0.pc
gtkhtml4_USE_GNOME_IMPL=gtk30 libxml2

gnomespeech_LIB_DEPENDS=libgnomespeech.so:${PORTSDIR}/accessibility/gnome-speech
gnomespeech_DETECT=	${LOCALBASE}/libdata/pkgconfig/gnome-speech-1.0.pc
gnomespeech_USE_GNOME_IMPL=libbonobo

evolutiondataserver3_LIB_DEPENDS=	libedataserver-1.2.so:${PORTSDIR}/databases/evolution-data-server
evolutiondataserver3_DETECT=		${LOCALBASE}/libdata/pkgconfig/libedataserverui-3.0.pc
evolutiondataserver3_USE_GNOME_IMPL=	libxml2 gtk30
evolutiondataserver3_GNOME_DESKTOP_VERSION=3

gnomemenus3_BUILD_DEPENDS=	gnome-menus>=3.2.0:${PORTSDIR}/x11/gnome-menus
gnomemenus3_RUN_DEPENDS=	gnome-menus>=3.2.0:${PORTSDIR}/x11/gnome-menus
gnomemenus3_DETECT=		${LOCALBASE}/libdata/pkgconfig/libgnome-menu-3.0.pc
gnomemenus3_USE_GNOME_IMPL=	glib20
gnomemenus3_GNOME_DESKTOP_VERSION=3

gnomedocutils_DETECT=		${LOCALBASE}/libdata/pkgconfig/gnome-doc-utils.pc
gnomedocutils_BUILD_DEPENDS=	${gnomedocutils_DETECT}:${PORTSDIR}/textproc/gnome-doc-utils
gnomedocutils_RUN_DEPENDS=	${gnomedocutils_DETECT}:${PORTSDIR}/textproc/gnome-doc-utils
gnomedocutils_USE_GNOME_IMPL=	libxslt

gtksharp10_DETECT=		${LOCALBASE}/libdata/pkgconfig/gtk-sharp.pc
gtksharp10_BUILD_DEPENDS=	${gtksharp10_DETECT}:${PORTSDIR}/x11-toolkits/gtk-sharp10
gtksharp10_RUN_DEPENDS=		${gtksharp10_DETECT}:${PORTSDIR}/x11-toolkits/gtk-sharp10
gtksharp10_USE_GNOME_IMPL=	gtk20

gtksharp20_DETECT=		${LOCALBASE}/libdata/pkgconfig/gtk-sharp-2.0.pc
gtksharp20_BUILD_DEPENDS=	${gtksharp20_DETECT}:${PORTSDIR}/x11-toolkits/gtk-sharp20
gtksharp20_RUN_DEPENDS=		${gtksharp20_DETECT}:${PORTSDIR}/x11-toolkits/gtk-sharp20
gtksharp20_USE_GNOME_IMPL=	gtk20

gnomesharp20_DETECT=		${LOCALBASE}/libdata/pkgconfig/gnome-sharp-2.0.pc
gnomesharp20_BUILD_DEPENDS=	${gnomesharp20_DETECT}:${PORTSDIR}/x11-toolkits/gnome-sharp20
gnomesharp20_RUN_DEPENDS=	${gnomesharp20_DETECT}:${PORTSDIR}/x11-toolkits/gnome-sharp20
gnomesharp20_USE_GNOME_IMPL=	gnomevfs2 gtkhtml3 gtksharp20 librsvg2 vte

libgnomekbd_DETECT=		${LOCALBASE}/libdata/pkgconfig/libgnomekbd.pc
libgnomekbd_LIB_DEPENDS=	libgnomekbd.so:${PORTSDIR}/x11/libgnomekbd
libgnomekbd_USE_GNOME_IMPL=	gtk30 libxml2

pygtksourceview_DETECT=		${LOCALBASE}/libdata/pkgconfig/pygtksourceview-2.0.pc
pygtksourceview_BUILD_DEPENDS=	${pygtksourceview_DETECT}:${PORTSDIR}/x11-toolkits/py-gtksourceview
pygtksourceview_RUN_DEPENDS=	${pygtksourceview_DETECT}:${PORTSDIR}/x11-toolkits/py-gtksourceview
pygtksourceview_USE_GNOME_IMPL=	gtksourceview2 pygtk2

gvfs_DETECT=		${LOCALBASE}/lib/gvfs/libgvfscommon.so
gvfs_BUILD_DEPENDS=	gvfs>=0:${PORTSDIR}/devel/gvfs
gvfs_RUN_DEPENDS=	gvfs>=0:${PORTSDIR}/devel/gvfs
gvfs_USE_GNOME_IMPL=	glib20

.if defined(MARCUSCOM_CVS)
.sinclude "${PORTSDIR}/Mk/bsd.gnome-experimental.mk"
.endif

.if defined(INSTALLS_ICONS)
USE_GNOME+=	gtk-update-icon-cache
.endif

# End component definition section

# This section defines tests for optional software.  These work off four
# types of variables:  WANT_GNOME, WITH_GNOME, HAVE_GNOME and USE_GNOME.
# The logic of this is that a port can WANT support for a package; a user
# specifies if they want ports compiled WITH certain features; this section
# tests if we HAVE these features; and the port is then free to USE them.

# The logic of this section is like this:
#
# .if defined(WANT_GNOME) && !defined(WITHOUT_GNOME)
#   .for foo in ALL_GNOME_COMPONENTS
#     .if defined(WITH_GNOME)
#       HAVE_GNOME += foo
#     .elif (foo installed)
#       HAVE_GNOME += foo
#     .else
#       Print option message
#     .endif
#   .endfor
# .endif
#
# Although it appears a little more convoluted in the tests.

# Ports can make use of this like so:
#
# WANT_GNOME=		yes
#
# .include <bsd.port.pre.mk>
#
# .if ${HAVE_GNOME:Mfoo}!=""
# ... Do some things ...
# USE_GNOME=		foo
# .else
# ... Do some other things ...
# .endif

# If the user has not defined GNOME_DESKTOP_VERSION, let's try to prevent
# users from shooting themselves in the foot.  We will try to make an
# intelligent choice on the user's behalf.
.if exists(${gnomepanel3_DETECT})
GNOME_DESKTOP_VERSION?=	3
.elif exists(${gnomepanel_DETECT})
GNOME_DESKTOP_VERSION?=	2
.endif

# We also check each component to see if it has a desktop requirement.  If
# it does, and its requirement disagrees with the user's chosen desktop,
# do not add the component to the HAVE_GNOME list.

_USE_GNOME_SAVED:=${USE_GNOME}
_USE_GNOME_DESKTOP=yes
HAVE_GNOME?=
.if (defined(WANT_GNOME) && !defined(WITHOUT_GNOME))
. for component in ${_USE_GNOME_ALL}
.      if defined(GNOME_DESKTOP_VERSION) && \
	defined(${component}_GNOME_DESKTOP_VERSION)
.         if ${GNOME_DESKTOP_VERSION}==${${component}_GNOME_DESKTOP_VERSION}
HAVE_GNOME+=	${component}
.         else
_USE_GNOME_DESKTOP=no
.         endif
.      else
.         if exists(${${component}_DETECT})
HAVE_GNOME+=	${component}
.         elif defined(WITH_GNOME)
.            if ${WITH_GNOME}=="yes" || ${WITH_GNOME:M${component}}!="" \
		|| ${WITH_GNOME}=="1"
HAVE_GNOME+=	${component}
.            endif
.         endif
.       endif
. endfor
.elif defined(WITHOUT_GNOME)
.  if ${WITHOUT_GNOME}!="yes" && ${WITHOUT_GNOME}!="1"
.    for component in ${_USE_GNOME_ALL}
.      if ${WITHOUT_GNOME:M${component}}==""
.        if exists(${${component}_DETECT})
HAVE_GNOME+=	${component}
.        endif
.      endif
.    endfor
.  endif
.endif

.endif
# End of optional part.

.if defined(_POSTMKINCLUDED) && !defined(Gnome_Post_Include)

Gnome_Post_Include=		bsd.gnome.mk

.if !defined(Gnome_Pre_Include)
.error The Pre include part of bsd.gnome.mk part is not included. Did you forget WANT_GNOME=yes before bsd.port.pre.mk?
.endif

.if defined(USE_GNOME)
# First of all expand all USE_GNOME_IMPL recursively
. for component in ${_USE_GNOME_ALL}
.  for subcomponent in ${${component}_USE_GNOME_IMPL}
${component}_USE_GNOME_IMPL+=${${subcomponent}_USE_GNOME_IMPL}
.  endfor
. endfor

# Then use already expanded USE_GNOME_IMPL to expand USE_GNOME.
# Also, check to see if each component has a desktop requirement.  If it does,
# and if the user's chosen desktop is not of the same version, mark the
# port as IGNORE.
. for component in ${USE_GNOME:C/^([^:]+).*/\1/}
.      if defined(GNOME_DESKTOP_VERSION) && \
	defined(${component}_GNOME_DESKTOP_VERSION)
.         if ${GNOME_DESKTOP_VERSION}!=${${component}_GNOME_DESKTOP_VERSION}
IGNORE=	cannot install: ${PORTNAME} wants to use the GNOME
IGNORE+=${${component}_GNOME_DESKTOP_VERSION} desktop, but you wish to use
IGNORE+=the GNOME ${GNOME_DESKTOP_VERSION} desktop
.         endif
.      endif
.  if ${_USE_GNOME_ALL:M${component}}==""
IGNORE=	cannot install: Unknown component ${component}
.  endif
_USE_GNOME+=	${${component}_USE_GNOME_IMPL} ${component}
. endfor

# Setup the GTK+ API version for pixbuf loaders, input method modules,
# and theme engines.
PLIST_SUB+=			GTK2_VERSION="${GTK2_VERSION}" \
				GTK3_VERSION="${GTK3_VERSION}"

# Set USE_CSTD for all ports that depend on glib12
.if defined(_USE_GNOME) && !empty(_USE_GNOME:Mglib12)
USE_CSTD=	gnu89
.endif

# Then traverse through all components, check which of them
# exist in ${_USE_GNOME} and set variables accordingly
.ifdef _USE_GNOME

. for component in ${_USE_GNOME:O:u}
.  if defined(${component}_PATCH_DEPENDS)
PATCH_DEPENDS+=	${${component}_PATCH_DEPENDS}
.  endif

.  if defined(${component}_DETECT)
.   if ${USE_GNOME:M${component}\:build}!=""
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
.   elif ${USE_GNOME:M${component}\:run}!=""
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}
.   else
.    if defined(${component}_LIB_DEPENDS)
LIB_DEPENDS+=	${${component}_LIB_DEPENDS}
.    else
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}
.    endif
.   endif
.  endif

.  if defined(${component}_CONFIGURE_ARGS)
CONFIGURE_ARGS+=${${component}_CONFIGURE_ARGS}
.  endif

.  if defined(${component}_CONFIGURE_ENV)
CONFIGURE_ENV+=	${${component}_CONFIGURE_ENV}
.  endif

.  if defined(${component}_MAKE_ENV)
MAKE_ENV+=	${${component}_MAKE_ENV}
.  endif

.  if !defined(CONFIGURE_TARGET) && defined(${component}_CONFIGURE_TARGET)
CONFIGURE_TARGET=	${${component}_CONFIGURE_TARGET}
.  endif

.  if defined(${component}_PRE_PATCH)
GNOME_PRE_PATCH+=	; ${${component}_PRE_PATCH}
.  endif
. endfor
.endif

. if defined(GCONF_SCHEMAS)
MAKE_ENV+=	GCONF_DISABLE_MAKEFILE_SCHEMA_INSTALL=1
. endif
.endif

.if defined(GNOME_PRE_PATCH)

pre-patch: gnome-pre-patch

gnome-pre-patch:
	@${GNOME_PRE_PATCH:C/^;//1}
.endif

.if defined(WANT_GNOME)
USE_GNOME?=
.  if ${_USE_GNOME_SAVED}==${USE_GNOME}
PLIST_SUB+=	GNOME:="@comment " NOGNOME:=""
.  else
PLIST_SUB+=	GNOME:="" NOGNOME:="@comment "
.    if defined(GNOME_DESKTOP_VERSION)
.      if ${_USE_GNOME_DESKTOP}=="yes"
PLIST_SUB+=	GNOMEDESKTOP:="" NOGNOMEDESKTOP:="@comment "
.      else
PLIST_SUB+=	GNOMEDESKTOP:="@comment " NOGNOMEDESKTOP:=""
.      endif
.    endif
.  endif
.endif

.if defined(USE_GNOME_SUBR)
GNOME_SUBR=		${LOCALBASE}/etc/gnome.subr
RUN_DEPENDS+=	${GNOME_SUBR}:${PORTSDIR}/sysutils/gnome_subr
SUB_LIST+=		GNOME_SUBR=${GNOME_SUBR}
.endif

.if ${MAINTAINER}=="gnome@FreeBSD.org"
CONFIGURE_FAIL_MESSAGE= "Please run the gnomelogalyzer, available from \"http://www.freebsd.org/gnome/gnomelogalyzer.sh\", which will diagnose the problem and suggest a solution. If - and only if - the gnomelogalyzer cannot solve the problem, report the build failure to the FreeBSD GNOME team at ${MAINTAINER}, and attach (a) \"${CONFIGURE_WRKSRC}/${CONFIGURE_LOG}\", (b) the output of the failed make command, and (c) the gnomelogalyzer output. Also, it might be a good idea to provide an overview of all packages installed on your system (i.e. an \`ls ${PKG_DBDIR}\`). Put your attachment up on any website, copy-and-paste into http://freebsd-gnome.pastebin.com, or use send-pr(1) with the attachment. Try to avoid sending any attachments to the mailing list (${MAINTAINER}), because attachments sent to FreeBSD mailing lists are usually discarded by the mailing list software."
.endif


.if defined(GCONF_SCHEMAS) || defined(INSTALLS_OMF) || defined(INSTALLS_ICONS) \
	|| defined(GLIB_SCHEMAS)
post-install: gnome-post-install

gnome-post-install:
.  if defined(GCONF_SCHEMAS)
	@for i in ${GCONF_SCHEMAS}; do \
		${ECHO_CMD} "@unexec env GCONF_CONFIG_SOURCE=xml:${GCONF_CONFIG_OPTIONS}:%D/${GCONF_CONFIG_DIRECTORY} HOME=${WRKDIR} gconftool-2 --makefile-uninstall-rule %D/etc/gconf/schemas/$${i} > /dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
		${ECHO_CMD} "etc/gconf/schemas/$${i}" >> ${TMPPLIST}; \
		${ECHO_CMD} "@exec env GCONF_CONFIG_SOURCE=xml:${GCONF_CONFIG_OPTIONS}:%D/${GCONF_CONFIG_DIRECTORY} HOME=${WRKDIR} gconftool-2 --makefile-install-rule %D/etc/gconf/schemas/$${i} > /dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
	done
.  endif

# we put the @unexec behind the plist schema entry, because it compiles files 
# in the directory. So we should remove the port file first before recompiling.
.  if defined(GLIB_SCHEMAS)
	@for i in ${GLIB_SCHEMAS}; do \
		${ECHO_CMD} "share/glib-2.0/schemas/$${i}" >> ${TMPPLIST}; \
	done
	@${ECHO_CMD} "@exec glib-compile-schemas %D/share/glib-2.0/schemas > /dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
	${ECHO_CMD} "@unexec glib-compile-schemas %D/share/glib-2.0/schemas > /dev/null || /usr/bin/true" \
			>> ${TMPPLIST};
.endif

.  if defined(INSTALLS_OMF)
	@for i in `${GREP} "\.omf$$" ${TMPPLIST}`; do \
		${ECHO_CMD} "@exec scrollkeeper-install -q %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
		${ECHO_CMD} "@unexec scrollkeeper-uninstall -q %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
	done
.  endif

.  if defined(INSTALLS_ICONS)
	@${RM} -f ${TMPPLIST}.icons1
	@for i in `${GREP} "^share/icons/.*/" ${TMPPLIST} | ${CUT} -d / -f 1-3 | ${SORT} -u`; do \
		${ECHO_CMD} "@rmtry $${i}/icon-theme.cache" \
			>> ${TMPPLIST}.icons1; \
		${ECHO_CMD} "@exec ${LOCALBASE}/bin/gtk-update-icon-cache -q -f %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
		${ECHO_CMD} "@unexec ${LOCALBASE}/bin/gtk-update-icon-cache -q -f %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
	done
	@if test -f ${TMPPLIST}.icons1; then \
		${CAT} ${TMPPLIST}.icons1 ${TMPPLIST} > ${TMPPLIST}.icons2; \
		${RM} -f ${TMPPLIST}.icons1; \
		${MV} -f ${TMPPLIST}.icons2 ${TMPPLIST}; \
	fi
.  endif
.endif

.endif
# End of use part.
