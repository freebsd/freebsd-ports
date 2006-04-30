#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#	$NetBSD: $
#     $MCom: ports/Mk/bsd.gnome.mk,v 1.370 2006/04/27 01:40:22 ahze Exp $
#
# Please view me with 4 column tabs!

.if !defined(_POSTMKINCLUDED) && !defined(Gnome_Pre_Include)

# Please make sure all changes to this file are passed through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Gnome_Include_MAINTAINER=	gnome@FreeBSD.org
Gnome_Pre_Include=			bsd.gnome.mk

# This section defines possible names of GNOME components and all information
# necessary for ports to use those components.

# Ports can use this as follows:
#
# USE_GNOME=	gnomeprint bonobo
#
# .include <bsd.port.mk>
#
# As a result proper LIB_DEPENDS/RUN_DEPENDS will be added and CONFIGURE_ENV
# and MAKE_ENV defined.
#
#
# GCONF_SCHEMAS		- Set the following to list of all schema files
#					  that your port installs. These schema files and
#					  %gconf.xml files will be automatically added to
#					  ${PLIST}. For example, if your port has
#					  "etc/gconf/schemas/(foo.schemas and bar.schemas)",
#					  add the following to your Makefile:
#					  "GCONF_SCHEMAS=foo.schemas bar.schemas".
#
# INSTALLS_OMF		- If set, bsd.gnome.mk will automatically scan pkg-plist
#					  file and add apropriate @exec/@unexec directives for
#					  each .omf file found to track OMF registration database.
#
# INSTALLS_ICONS	- If your port installs Freedesktop-style icons to
#					  ${LOCALBASE}/share/icons or ${X11BASE}/share/icons, then
#					  you should use this macro. If the icons are not cached,
#					  they will not be displayed.
#

# non-version specific components
_USE_GNOME_ALL= esound intlhack intltool lthack ltverhack gnomehack \
		gnomehier gnomemimedata gnomeprefix gnometarget pkgconfig

# GNOME 1 components
_USE_GNOME_ALL+= bonobo gal gconf gdkpixbuf glib12 glibwww \
		gnomecanvas gnomedb gnomelibs gnomeprint gnomevfs gtk12 \
		gtkhtml libcapplet libgda libghttp libglade libxml imlib \
		oaf orbit pygnome pygtk

# GNOME 2 components
_USE_GNOME_ALL+= atk atspi desktopfileutils eel2 evolutiondataserver \
		gail gal2 gconf2 glib20 gnomecontrolcenter2 gnomedesktop \
		gnomedocutils gnomemenus gnomepanel gnomespeech gnomevfs2 \
		gtk20 gtkhtml3 gtksourceview libartlgpl2 libbonobo \
		libbonoboui libgailgnome libgda2 libgda3 libglade2 libgnome \
		libgnomecanvas libgnomedb libgnomeprint libgnomeprintui \
		libgnomeui libgsf libgsf_gnome libgtkhtml libidl librsvg2 libwnck \
		libxml2 libxslt libzvt linc metacity nautilus2 nautiluscdburner \
		orbit2 pango pygnome2 pygnomeextras pygtk2 vte pygnomedesktop

SCROLLKEEPER_DIR=	/var/db/scrollkeeper
gnomehack_PRE_PATCH=	${FIND} ${WRKSRC} -name "Makefile.in*" -type f | ${XARGS} ${REINPLACE_CMD} -e \
				's|[(]GNOME_datadir[)]/gnome/|(datadir)/|g ; \
				 s|[(]GNOME_datadir[)]/locale|(prefix)/share/locale|g ; \
				 s|[(]datadir[)]/locale|(prefix)/share/locale|g ; \
				 s|[(]libdir[)]/locale|(prefix)/share/locale|g ; \
				 s|[(]gnomedatadir[)]/gnome|(gnomedatadir)|g ; \
				 s|[(]datadir[)]/aclocal|(prefix)/share/aclocal|g ; \
				 s|[(]datadir[)]/gnome/|(datadir)/|g ; \
				 s|[(]datadir[)]/mime/|(prefix)/share/mime/|g ; \
				 s|[(]datadir[)]/mime"|(prefix)/share/mime"|g ; \
				 s|[(]datadir[)]/mime;|(prefix)/share/mime;|g ; \
				 s|[(]datadir[)]/mime$$|(prefix)/share/mime|g ; \
				 s|[(]datadir[)]/dbus-1|(prefix)/share/dbus-1|g ; \
				 s|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
				 s|[$$][(]localstatedir[)]/scrollkeeper|${SCROLLKEEPER_DIR}|g ; \
				 s|[(]datadir[)]/icons/hicolor|(prefix)/share/icons/hicolor|g ; \
				 s|[(]libdir[)]/bonobo/servers|(prefix)/libdata/bonobo/servers|g' ; \
			${FIND} ${WRKSRC} -name "configure" -type f | ${XARGS} ${REINPLACE_CMD} -e \
				's|-lpthread|${PTHREAD_LIBS}|g ; \
				 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
				 s|{datadir}/locale|{prefix}/share/locale|g ; \
				 s|DATADIR/dbus-1/services|prefix/share/dbus-1/services|g ; \
				 s|datadir/dbus-1/services|prefix/share/dbus-1/services|g ; \
				 s|{libdir}/locale|{prefix}/share/locale|g'

lthack_PRE_PATCH=	${FIND} ${WRKSRC} -name "configure" -type f | ${XARGS} ${REINPLACE_CMD} -e \
				'/^LIBTOOL_DEPS="$$ac_aux_dir\/ltmain.sh"$$/s|$$|; $$ac_aux_dir/ltconfig $$LIBTOOL_DEPS;|'

GNOME_MTREE_FILE?=		${X11BASE}/etc/mtree/BSD.gnome-x11.dist
gnomehier_DETECT=	${GNOME_MTREE_FILE}
gnomehier_RUN_DEPENDS=	${gnomehier_DETECT}:${PORTSDIR}/misc/gnomehier

GNOME_HTML_DIR?=	${PREFIX}/share/doc
GCONF_CONFIG_OPTIONS?=	merged
GCONF_CONFIG_DIRECTORY?=etc/gconf/gconf.xml.defaults
GCONF_CONFIG_SOURCE?=xml:${GCONF_CONFIG_OPTIONS}:${PREFIX}/${GCONF_CONFIG_DIRECTORY}
GNOME_LOCALSTATEDIR?=	${PREFIX}/share/gnome
gnomeprefix_CONFIGURE_ENV=GTKDOC="false"
gnomeprefix_CONFIGURE_ARGS=--localstatedir=${GNOME_LOCALSTATEDIR} \
			   --datadir=${PREFIX}/share/gnome \
			   --with-html-dir=${GNOME_HTML_DIR} \
			   --with-help-dir=${PREFIX}/share/gnome/help \
			   --disable-gtk-doc \
			   --with-gconf-source=${GCONF_CONFIG_SOURCE}
gnomeprefix_USE_GNOME_IMPL=gnomehier

gnometarget_CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

ESD_CONFIG?=		${LOCALBASE}/bin/esd-config
esound_LIB_DEPENDS=	esd.2:${PORTSDIR}/audio/esound
esound_CONFIGURE_ENV=	ESD_CONFIG="${ESD_CONFIG}"
esound_MAKE_ENV=	ESD_CONFIG="${ESD_CONFIG}"
esound_DETECT=		${ESD_CONFIG}

libghttp_LIB_DEPENDS=	ghttp.1:${PORTSDIR}/www/libghttp
libghttp_DETECT=	${LOCALBASE}/etc/ghttpConf.sh

GLIB_CONFIG?=		${LOCALBASE}/bin/glib12-config
glib12_LIB_DEPENDS=	glib-12.3:${PORTSDIR}/devel/glib12
glib12_CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}"
glib12_MAKE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}"
glib12_DETECT=		${GLIB_CONFIG}
glib12_USE_GNOME_IMPL=	pkgconfig

GTK_CONFIG?=		${X11BASE}/bin/gtk12-config
gtk12_LIB_DEPENDS=	gtk-12.2:${PORTSDIR}/x11-toolkits/gtk12
gtk12_CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
gtk12_MAKE_ENV=		GTK_CONFIG="${GTK_CONFIG}"
gtk12_DETECT=		${GTK_CONFIG}
gtk12_USE_GNOME_IMPL=	glib12

XML_CONFIG?=		${LOCALBASE}/bin/xml-config
libxml_LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml
libxml_CONFIGURE_ENV=	XML_CONFIG="${XML_CONFIG}"
libxml_MAKE_ENV=	XML_CONFIG="${XML_CONFIG}"
libxml_DETECT=		${XML_CONFIG}
libxml_USE_GNOME_IMPL=	glib12

ORBIT_CONFIG?=		${LOCALBASE}/bin/orbit-config
orbit_LIB_DEPENDS=	ORBit.2:${PORTSDIR}/devel/ORBit
orbit_CONFIGURE_ENV=	ORBIT_CONFIG="${ORBIT_CONFIG}"
orbit_MAKE_ENV=		ORBIT_CONFIG="${ORBIT_CONFIG}"
orbit_DETECT=		${ORBIT_CONFIG}
orbit_USE_GNOME_IMPL=	glib12

GDK_PIXBUF_CONFIG?=	${X11BASE}/bin/gdk-pixbuf-config
gdkpixbuf_LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
gdkpixbuf_CONFIGURE_ENV=GDK_PIXBUF_CONFIG="${GDK_PIXBUF_CONFIG}"
gdkpixbuf_MAKE_ENV=	GDK_PIXBUF_CONFIG="${GDK_PIXBUF_CONFIG}"
gdkpixbuf_DETECT=	${GDK_PIXBUF_CONFIG}
gdkpixbuf_USE_GNOME_IMPL=gtk12

IMLIB_CONFIG?=		${X11BASE}/bin/imlib-config
imlib_LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib
imlib_CONFIGURE_ENV=	IMLIB_CONFIG="${IMLIB_CONFIG}"
imlib_MAKE_ENV=		IMLIB_CONFIG="${IMLIB_CONFIG}"
imlib_DETECT=		${IMLIB_CONFIG}
imlib_USE_GNOME_IMPL=	gtk12

GNOME_CONFIG?=		${X11BASE}/bin/gnome-config
gnomelibs_LIB_DEPENDS=	gnome.5:${PORTSDIR}/x11/gnomelibs
gnomelibs_CONFIGURE_ENV=GNOME_CONFIG="${GNOME_CONFIG}"
gnomelibs_MAKE_ENV=	GNOME_CONFIG="${GNOME_CONFIG}"
gnomelibs_DETECT=	${GNOME_CONFIG}
gnomelibs_USE_GNOME_IMPL=esound gtk12 imlib libxml orbit

gnomecanvas_LIB_DEPENDS=gnomecanvaspixbuf.1:${PORTSDIR}/graphics/gnomecanvas
gnomecanvas_DETECT=	${X11BASE}/etc/gnomecanvaspixbufConf.sh
gnomecanvas_USE_GNOME_IMPL=gnomelibs gdkpixbuf

OAF_CONFIG?=		${X11BASE}/bin/oaf-config
oaf_LIB_DEPENDS=	oaf.0:${PORTSDIR}/devel/oaf
oaf_CONFIGURE_ENV=	OAF_CONFIG="${OAF_CONFIG}"
oaf_MAKE_ENV=		OAF_CONFIG="${OAF_CONFIG}"
oaf_DETECT=		${OAF_CONFIG}
oaf_USE_GNOME_IMPL=	glib12 orbit libxml

gnomemimedata_DETECT=	${X11BASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc
gnomemimedata_BUILD_DEPENDS=${gnomemimedata_DETECT}:${PORTSDIR}/misc/gnomemimedata
gnomemimedata_RUN_DEPENDS=${gnomemimedata_DETECT}:${PORTSDIR}/misc/gnomemimedata
gnomemimedata_USE_GNOME_IMPL=gnomehier pkgconfig

GCONF_CONFIG?=		${X11BASE}/bin/gconf-config
gconf_LIB_DEPENDS=	gconf-1.1:${PORTSDIR}/devel/gconf
gconf_CONFIGURE_ENV=	GCONF_CONFIG="${GCONF_CONFIG}"
gconf_MAKE_ENV=		GCONF_CONFIG="${GCONF_CONFIG}"
gconf_DETECT=		${GCONF_CONFIG}
gconf_USE_GNOME_IMPL=	oaf

GNOME_VFS_CONFIG?=	${X11BASE}/bin/gnome-vfs-config
gnomevfs_LIB_DEPENDS=	gnomevfs.0:${PORTSDIR}/devel/gnomevfs
gnomevfs_CONFIGURE_ENV=	GNOME_VFS_CONFIG="${GNOME_VFS_CONFIG}"
gnomevfs_MAKE_ENV=	GNOME_VFS_CONFIG="${GNOME_VFS_CONFIG}"
gnomevfs_DETECT=	${GNOME_VFS_CONFIG}
gnomevfs_USE_GNOME_IMPL=gnomemimedata gconf gnomelibs

libcapplet_LIB_DEPENDS=	capplet.5:${PORTSDIR}/x11/libcapplet
libcapplet_DETECT=	${X11BASE}/etc/cappletConf.sh
libcapplet_USE_GNOME_IMPL=gnomelibs

gnomeprint_LIB_DEPENDS=	gnomeprint.16:${PORTSDIR}/print/gnomeprint
gnomeprint_DETECT=	${X11BASE}/etc/printConf.sh
gnomeprint_USE_GNOME_IMPL=gnomelibs gnomecanvas

bonobo_LIB_DEPENDS=	bonobo.2:${PORTSDIR}/devel/bonobo
bonobo_DETECT=		${X11BASE}/etc/bonoboConf.sh
bonobo_USE_GNOME_IMPL=	oaf gnomeprint

GDA_CONFIG?=		${X11BASE}/bin/gda-config
libgda_LIB_DEPENDS=	gda-client.0:${PORTSDIR}/databases/libgda
libgda_CONFIGURE_ENV=	GDA_CONFIG="${GDA_CONFIG}"
libgda_MAKE_ENV=	GDA_CONFIG="${GDA_CONFIG}"
libgda_DETECT=		${GDA_CONFIG}
libgda_USE_GNOME_IMPL=	gconf bonobo

GNOMEDB_CONFIG?=	${X11BASE}/bin/gnomedb-config
gnomedb_LIB_DEPENDS=	gnomedb.0:${PORTSDIR}/databases/gnomedb
gnomedb_CONFIGURE_ENV=	GNOMEDB_CONFIG="${GNOMEDB_CONFIG}"
gnomedb_MAKE_ENV=	GNOMEDB_CONFIG="${GNOMEDB_CONFIG}"
gnomedb_DETECT=		${GNOMEDB_CONFIG}
gnomedb_USE_GNOME_IMPL=	libgda

LIBGLADE_CONFIG?=	${X11BASE}/bin/libglade-config
libglade_LIB_DEPENDS=	glade.4:${PORTSDIR}/devel/libglade
libglade_CONFIGURE_ENV=	LIBGLADE_CONFIG="${LIBGLADE_CONFIG}"
libglade_MAKE_ENV=	LIBGLADE_CONFIG="${LIBGLADE_CONFIG}"
libglade_DETECT=	${LIBGLADE_CONFIG}
libglade_USE_GNOME_IMPL=gnomedb

gal_LIB_DEPENDS=	gal.23:${PORTSDIR}/x11-toolkits/gal
gal_DETECT=		${X11BASE}/etc/galConf.sh
gal_USE_GNOME_IMPL=	libglade

glibwww_LIB_DEPENDS=	glibwww.1:${PORTSDIR}/www/glibwww
glibwww_DETECT=		${X11BASE}/etc/glibwwwConf.sh
glibwww_USE_GNOME_IMPL=	gnomelibs

gtkhtml_LIB_DEPENDS=	gtkhtml-1.1.3:${PORTSDIR}/www/gtkhtml
gtkhtml_DETECT=		${X11BASE}/etc/gtkhtmlConf.sh
gtkhtml_USE_GNOME_IMPL=	glibwww gal libghttp libcapplet

pygtk_DETECT=			${LOCALBASE}/bin/pygtk-codegen-1.2
pygtk_BUILD_DEPENDS=	${pygtk_DETECT}:${PORTSDIR}/x11-toolkits/py-gtk
pygtk_RUN_DEPENDS=		${pygtk_DETECT}:${PORTSDIR}/x11-toolkits/py-gtk
pygtk_USE_GNOME_IMPL=	gnomelibs gdkpixbuf libglade

pygnome_DETECT=			${LOCALBASE}/share/pygtk/1.2/defs/applet.defs
pygnome_BUILD_DEPENDS=	${pygnome_DETECT}:${PORTSDIR}/x11-toolkits/py-gnome
pygnome_RUN_DEPENDS=	${pygnome_DETECT}:${PORTSDIR}/x11-toolkits/py-gnome
pygnome_USE_GNOME_IMPL=	gtkhtml pygtk

glib20_LIB_DEPENDS=	glib-2.0.0:${PORTSDIR}/devel/glib20
glib20_DETECT=		${LOCALBASE}/libdata/pkgconfig/glib-2.0.pc
glib20_USE_GNOME_IMPL=gnometarget pkgconfig

atk_LIB_DEPENDS=	atk-1.0.0:${PORTSDIR}/accessibility/atk
atk_DETECT=		${LOCALBASE}/libdata/pkgconfig/atk.pc
atk_USE_GNOME_IMPL=	glib20

pango_LIB_DEPENDS=	pango-1.0.0:${PORTSDIR}/x11-toolkits/pango
pango_DETECT=		${X11BASE}/libdata/pkgconfig/pango.pc
pango_USE_GNOME_IMPL=	glib20

gtk20_LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20
gtk20_DETECT=		${X11BASE}/libdata/pkgconfig/gtk+-x11-2.0.pc
gtk20_USE_GNOME_IMPL=	intltool atk pango

linc_LIB_DEPENDS=	linc.1:${PORTSDIR}/net/linc
linc_DETECT=		${LOCALBASE}/libdata/pkgconfig/linc.pc
linc_USE_GNOME_IMPL=glib20

libidl_LIB_DEPENDS=	IDL-2.0:${PORTSDIR}/devel/libIDL
libidl_DETECT=		${LOCALBASE}/libdata/pkgconfig/libIDL-2.0.pc
libidl_USE_GNOME_IMPL=	glib20

orbit2_LIB_DEPENDS=	ORBit-2.0:${PORTSDIR}/devel/ORBit2
orbit2_DETECT=		${LOCALBASE}/libdata/pkgconfig/ORBit-2.0.pc
orbit2_USE_GNOME_IMPL=	libidl

libglade2_LIB_DEPENDS=	glade-2.0.0:${PORTSDIR}/devel/libglade2
libglade2_DETECT=	${X11BASE}/libdata/pkgconfig/libglade-2.0.pc
libglade2_USE_GNOME_IMPL=libxml2 gtk20

libxml2_LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2
libxml2_DETECT=		${LOCALBASE}/libdata/pkgconfig/libxml-2.0.pc
libxml2_USE_GNOME_IMPL=	pkgconfig

libxslt_LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt
libxslt_DETECT=		${LOCALBASE}/libdata/pkgconfig/libxslt.pc
libxslt_USE_GNOME_IMPL=	libxml2

libbonobo_LIB_DEPENDS=	bonobo-2.0:${PORTSDIR}/devel/libbonobo
libbonobo_DETECT=	${LOCALBASE}/libdata/pkgconfig/libbonobo-2.0.pc
libbonobo_USE_GNOME_IMPL=libxml2 orbit2

gconf2_LIB_DEPENDS=	gconf-2.4:${PORTSDIR}/devel/gconf2
gconf2_DETECT=		${X11BASE}/libdata/pkgconfig/gconf-2.0.pc
gconf2_USE_GNOME_IMPL=	orbit2 libxml2 gtk20 linc

gnomevfs2_LIB_DEPENDS=	gnomevfs-2.0:${PORTSDIR}/devel/gnomevfs2
gnomevfs2_DETECT=	${X11BASE}/libdata/pkgconfig/gnome-vfs-2.0.pc
gnomevfs2_USE_GNOME_IMPL=gconf2 libbonobo gnomemimedata

gail_LIB_DEPENDS=	gailutil.17:${PORTSDIR}/accessibility/gail
gail_DETECT=		${X11BASE}/libdata/pkgconfig/gail.pc
gail_USE_GNOME_IMPL=	libgnomecanvas

libgnomecanvas_LIB_DEPENDS=	gnomecanvas-2.0:${PORTSDIR}/graphics/libgnomecanvas
libgnomecanvas_DETECT=		${X11BASE}/libdata/pkgconfig/libgnomecanvas-2.0.pc
libgnomecanvas_USE_GNOME_IMPL=	libglade2 libartlgpl2

libartlgpl2_LIB_DEPENDS=	art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2
libartlgpl2_DETECT=		${LOCALBASE}/libdata/pkgconfig/libart-2.0.pc
libartlgpl2_USE_GNOME_IMPL=	pkgconfig

libgnomeprint_LIB_DEPENDS=	gnomeprint-2-2.0:${PORTSDIR}/print/libgnomeprint
libgnomeprint_DETECT=		${X11BASE}/libdata/pkgconfig/libgnomeprint-2.2.pc
libgnomeprint_USE_GNOME_IMPL=	libbonobo libartlgpl2 gtk20

libgnomeprintui_LIB_DEPENDS=	gnomeprintui-2-2.0:${PORTSDIR}/x11-toolkits/libgnomeprintui
libgnomeprintui_DETECT=		${X11BASE}/libdata/pkgconfig/libgnomeprintui-2.2.pc
libgnomeprintui_USE_GNOME_IMPL=	libgnomeprint libgnomecanvas

libgnome_LIB_DEPENDS=	gnome-2.0:${PORTSDIR}/x11/libgnome
libgnome_DETECT=	${X11BASE}/libdata/pkgconfig/libgnome-2.0.pc
libgnome_USE_GNOME_IMPL=libxslt gnomevfs2 esound

libbonoboui_LIB_DEPENDS=	bonoboui-2.0:${PORTSDIR}/x11-toolkits/libbonoboui
libbonoboui_DETECT=		${X11BASE}/libdata/pkgconfig/libbonoboui-2.0.pc
libbonoboui_USE_GNOME_IMPL=	libgnomecanvas libgnome

libgnomeui_LIB_DEPENDS=		gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui
libgnomeui_DETECT=		${X11BASE}/libdata/pkgconfig/libgnomeui-2.0.pc
libgnomeui_USE_GNOME_IMPL=	libbonoboui

atspi_LIB_DEPENDS=	spi.10:${PORTSDIR}/accessibility/at-spi
atspi_DETECT=		${X11BASE}/libdata/pkgconfig/cspi-1.0.pc
atspi_USE_GNOME_IMPL=	gail libbonobo

libgailgnome_DETECT=		${X11BASE}/libdata/pkgconfig/libgail-gnome.pc
libgailgnome_RUN_DEPENDS=	${libgailgnome_DETECT}:${PORTSDIR}/x11-toolkits/libgail-gnome
libgailgnome_USE_GNOME_IMPL=	libgnomeui atspi

libgtkhtml_LIB_DEPENDS=	gtkhtml-2.0:${PORTSDIR}/www/libgtkhtml
libgtkhtml_DETECT=	${X11BASE}/libdata/pkgconfig/libgtkhtml-2.0.pc
libgtkhtml_USE_GNOME_IMPL=libxslt gnomevfs2 gail

gnomedesktop_LIB_DEPENDS=	gnome-desktop-2.2:${PORTSDIR}/x11/gnomedesktop
gnomedesktop_DETECT=		${X11BASE}/libdata/pkgconfig/gnome-desktop-2.0.pc
gnomedesktop_USE_GNOME_IMPL=	libgnomeui gnomedocutils
gnomedesktop_GNOME_DESKTOP_VERSION=2

libwnck_LIB_DEPENDS=	wnck-1.18:${PORTSDIR}/x11-toolkits/libwnck
libwnck_DETECT=		${X11BASE}/libdata/pkgconfig/libwnck-1.0.pc
libwnck_USE_GNOME_IMPL=	gtk20

vte_LIB_DEPENDS=	vte.4:${PORTSDIR}/x11-toolkits/vte
vte_DETECT=		${X11BASE}/libdata/pkgconfig/vte.pc
vte_USE_GNOME_IMPL=	gtk20

libzvt_LIB_DEPENDS=	zvt-2.0.0:${PORTSDIR}/x11-toolkits/libzvt
libzvt_DETECT=	${X11BASE}/libdata/pkgconfig/libzvt-2.0.pc
libzvt_USE_GNOME_IMPL=	gtk20

librsvg2_LIB_DEPENDS=	rsvg-2.2:${PORTSDIR}/graphics/librsvg2
librsvg2_DETECT=	${X11BASE}/libdata/pkgconfig/librsvg-2.0.pc
librsvg2_USE_GNOME_IMPL=libgsf gtk20

eel2_LIB_DEPENDS=	eel-2.2:${PORTSDIR}/x11-toolkits/eel
eel2_DETECT=		${X11BASE}/libdata/pkgconfig/eel-2.0.pc
eel2_USE_GNOME_IMPL=	gnomemenus gnomedesktop gail

gnomepanel_LIB_DEPENDS=	panel-applet-2.0:${PORTSDIR}/x11/gnomepanel
gnomepanel_DETECT=	${X11BASE}/libdata/pkgconfig/libpanelapplet-2.0.pc
gnomepanel_USE_GNOME_IMPL=gnomedesktop libwnck gnomemenus gnomedocutils
gnomepanel_GNOME_DESKTOP_VERSION=2

nautilus2_LIB_DEPENDS=	nautilus-extension.1:${PORTSDIR}/x11-fm/nautilus2
nautilus2_DETECT=	${X11BASE}/libdata/pkgconfig/libnautilus-extension.pc
nautilus2_USE_GNOME_IMPL=librsvg2 eel2 gnomedesktop desktopfileutils
nautilus2_GNOME_DESKTOP_VERSION=2

metacity_LIB_DEPENDS=	metacity-private.0:${PORTSDIR}/x11-wm/metacity
metacity_DETECT=	${X11BASE}/libdata/pkgconfig/libmetacity-private.pc
metacity_USE_GNOME_IMPL=gconf2

gal2_LIB_DEPENDS=	gal-2.4.0:${PORTSDIR}/x11-toolkits/gal2
gal2_DETECT=		${X11BASE}/libdata/pkgconfig/gal-2.4.pc
gal2_USE_GNOME_IMPL=gnomeui libgnomeprintui

gnomecontrolcenter2_LIB_DEPENDS=gnome-window-settings.1:${PORTSDIR}/sysutils/gnomecontrolcenter2
gnomecontrolcenter2_DETECT=${X11BASE}/libdata/pkgconfig/gnome-window-settings-2.0.pc
gnomecontrolcenter2_USE_GNOME_IMPL=desktopfileutils gnomedesktop gnomemenus metacity nautilus2 desktopfileutils

libgda2_LIB_DEPENDS=	gda-2.3:${PORTSDIR}/databases/libgda2
libgda2_DETECT=			${X11BASE}/libdata/pkgconfig/libgda.pc
libgda2_USE_GNOME_IMPL=	glib20 libxslt

libgda3_LIB_DEPENDS=	gda-3.3:${PORTSDIR}/databases/libgda3
libgda3_DETECT=			${X11BASE}/libdata/pkgconfig/libgda-2.0.pc
libgda3_USE_GNOME_IMPL=	glib20 libxslt

libgnomedb_LIB_DEPENDS=	gnomedb-3.4:${PORTSDIR}/databases/libgnomedb
libgnomedb_DETECT=		${X11BASE}/libdata/pkgconfig/libgnomedb.pc
libgnomedb_USE_GNOME_IMPL=libgnomeui libgda3

gtksourceview_LIB_DEPENDS=	gtksourceview-1.0.0:${PORTSDIR}/x11-toolkits/gtksourceview
gtksourceview_DETECT=	${X11BASE}/libdata/pkgconfig/gtksourceview-1.0.pc
gtksourceview_USE_GNOME_IMPL=libgnome libgnomeprintui

pkgconfig_DETECT=			${LOCALBASE}/bin/pkg-config
pkgconfig_BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
pkgconfig_RUN_DEPENDS=		pkg-config:${PORTSDIR}/devel/pkgconfig

libgsf_LIB_DEPENDS=			gsf-1.114:${PORTSDIR}/devel/libgsf
libgsf_DETECT=			${X11BASE}/libdata/pkgconfig/libgsf-1.pc
libgsf_USE_GNOME_IMPL=		gconf2 glib20 libxml2

libgsf_gnome_LIB_DEPENDS=	gsf-gnome-1.114:${PORTSDIR}/devel/libgsf-gnome
libgsf_gnome_DETECT=		${X11BASE}/libdata/pkgconfig/libgsf-gnome-1.pc
libgsf_gnome_USE_GNOME_IMPL=	libgsf gnomevfs2

pygtk2_DETECT=			${LOCALBASE}/libdata/pkgconfig/pygtk-2.0.pc
pygtk2_BUILD_DEPENDS=	${pygtk2_DETECT}:${PORTSDIR}/x11-toolkits/py-gtk2
pygtk2_RUN_DEPENDS=		${pygtk2_DETECT}:${PORTSDIR}/x11-toolkits/py-gtk2
pygtk2_USE_GNOME_IMPL=	libglade2

pygnome2_DETECT=		${LOCALBASE}/libdata/pkgconfig/gnome-python-2.0.pc
pygnome2_BUILD_DEPENDS=	${pygnome2_DETECT}:${PORTSDIR}/x11-toolkits/py-gnome2
pygnome2_RUN_DEPENDS=	${pygnome2_DETECT}:${PORTSDIR}/x11-toolkits/py-gnome2
pygnome2_USE_GNOME_IMPL=libgnomeui pygtk2

intltool_DETECT=		${LOCALBASE}/bin/intltool-extract
intltool_BUILD_DEPENDS=	${intltool_DETECT}:${PORTSDIR}/textproc/intltool

intlhack_PRE_PATCH=		${FIND} ${WRKSRC} -name "intltool-merge.in" | ${XARGS} ${REINPLACE_CMD} -e \
				's|mkdir $$lang or|mkdir $$lang, 0777 or| ; \
				 s|^push @INC, "/.*|push @INC, "${LOCALBASE}/share/intltool";| ; \
				 s|/usr/bin/iconv|${LOCALBASE}/bin/iconv|g ; \
				 s|unpack *[(]'"'"'U\*'"'"'|unpack ('"'"'C*'"'"'|'
intlhack_USE_GNOME_IMPL=intltool

gtkhtml3_LIB_DEPENDS=	gtkhtml-3.8.15:${PORTSDIR}/www/gtkhtml3
gtkhtml3_DETECT=		${X11BASE}/libdata/pkgconfig/libgtkhtml-3.8.pc
gtkhtml3_USE_GNOME_IMPL=gail libgnomeui libgnomeprintui

gnomespeech_LIB_DEPENDS=gnomespeech.7:${PORTSDIR}/accessibility/gnomespeech
gnomespeech_DETECT=		${LOCALBASE}/libdata/pkgconfig/gnome-speech-1.0.pc
gnomespeech_USE_GNOME_IMPL=libbonobo

evolutiondataserver_LIB_DEPENDS=edataserver-1.2.7:${PORTSDIR}/databases/evolution-data-server
evolutiondataserver_DETECT=		${X11BASE}/libdata/pkgconfig/evolution-data-server-1.2.pc
evolutiondataserver_USE_GNOME_IMPL=libgnomeui

desktopfileutils_RUN_DEPENDS=update-desktop-database:${PORTSDIR}/devel/desktop-file-utils
desktopfileutils_DETECT=	${LOCALBASE}/bin/update-desktop-database
desktopfileutils_USE_GNOME_IMPL=glib20

nautiluscdburner_LIB_DEPENDS=nautilus-burn.3:${PORTSDIR}/sysutils/nautilus-cd-burner
nautiluscdburner_DETECT=	${X11BASE}/libdata/pkgconfig/libnautilus-burn.pc
nautiluscdburner_USE_GNOME_IMPL=nautilus2

gnomemenus_LIB_DEPENDS=		gnome-menu.2:${PORTSDIR}/x11/gnome-menus
gnomemenus_DETECT=			${X11BASE}/libdata/pkgconfig/libgnome-menu.pc
gnomemenus_USE_GNOME_IMPL=	gnomevfs2

pygnomeextras_DETECT=		${LOCALBASE}/libdata/pkgconfig/gnome-python-extras-2.0.pc
pygnomeextras_BUILD_DEPENDS=	${pygnomeextras_DETECT}:${PORTSDIR}/x11-toolkits/py-gnome-extras
pygnomeextras_RUN_DEPENDS=	${pygnomeextras_DETECT}:${PORTSDIR}/x11-toolkits/py-gnome-extras
pygnomeextras_USE_GNOME_IMPL=pygnome2 libgtkhtml

gnomedocutils_DETECT=	${X11BASE}/libdata/pkgconfig/gnome-doc-utils.pc
gnomedocutils_BUILD_DEPENDS=${gnomedocutils_DETECT}:${PORTSDIR}/textproc/gnomedocutils
gnomedocutils_RUN_DEPENDS=${gnomedocutils_DETECT}:${PORTSDIR}/textproc/gnomedocutils
gnomedocutils_USE_GNOME_IMPL=libxslt

pygnomedesktop_DETECT=		${LOCALBASE}/libdata/pkgconfig/gnome-python-desktop-2.0.pc
pygnomedesktop_BUILD_DEPENDS=	${pygnomedesktop_DETECT}:${PORTSDIR}/x11-toolkits/py-gnome-desktop
pygnomedesktop_RUN_DEPENDS=	${pygnomedesktop_DETECT}:${PORTSDIR}/x11-toolkits/py-gnome-desktop
pygnomedesktop_USE_GNOME_IMPL=pygnome2 libgnomeprintui gtksourceview gnomepanel libwnck nautiluscdburner metacity

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
.if exists(${gnomepanel_DETECT})
GNOME_DESKTOP_VERSION?=	2
#.elif exists(${libpanel_DETECT})
#GNOME_DESKTOP_VERSION?=	1
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

# DO NOT USE THESE MACROS!  They are obsolete, and only provided for
# backward compatibility with old ports that have not converted to the new
# GNOME infrastructure.
.if defined(USE_GTK)
#.warning The USE_GTK macro is deprecated. It should be replaced by USE_GNOME=gtk12.
USE_GNOME+=	gtk12
.endif
# End of obsolete macros

.if defined(USE_GNOME)
# Hack USE_GNOME to the modular infrastructure for port maintainers that
# didn't do so themselves.  New ports should NOT set USE_GNOME=yes.
. if ${USE_GNOME}=="yes"
#.warning The USE_GNOME=yes component is deprecated. It should be replaced by some combination of gnomeprefix, gnomehack, and gtkhtml
USE_GNOME:=	${USE_GNOME:S/yes//}
USE_GNOME+=	gnomeprefix gnomehack gtkhtml
. endif

# First of all expand all USE_GNOME_IMPL recursively
. for component in ${_USE_GNOME_ALL}
.  for subcomponent in ${${component}_USE_GNOME_IMPL}
${component}_USE_GNOME_IMPL+=${${subcomponent}_USE_GNOME_IMPL}
.  endfor
. endfor

# Then use already expanded USE_GNOME_IMPL to expand USE_GNOME.
# Also, check to see if each component has a desktop requirement.  If it does,
# and if the user's chosen desktop is not of the same version, mark the
# port as broken.
. for component in ${USE_GNOME}
.      if defined(GNOME_DESKTOP_VERSION) && \
	defined(${component}_GNOME_DESKTOP_VERSION)
.         if ${GNOME_DESKTOP_VERSION}!=${${component}_GNOME_DESKTOP_VERSION}
BROKEN=	${PORTNAME} wants to use the GNOME
BROKEN+=${${component}_GNOME_DESKTOP_VERSION} desktop, but you wish to use
BROKEN+=the GNOME ${GNOME_DESKTOP_VERSION} desktop
.         endif
.      endif
.  if ${_USE_GNOME_ALL:M${component}}==""
BROKEN=	Unknown component ${component}
.  endif
_USE_GNOME+=	${${component}_USE_GNOME_IMPL} ${component}
. endfor

# Then handle the ltverhack component (it has to be done here, because
# we rely on some bsd.autotools.mk variables, and bsd.autotools.mk is
# included in the post-makefile section).
.if defined(AUTOTOOL_libtool)
ltverhack_PRE_PATCH=	${CP} -pf ${LTMAIN} ${WRKDIR}/gnome-ltmain.sh && \
						${CP} -pf ${LIBTOOL} ${WRKDIR}/gnome-libtool && \
						for file in ${LIBTOOLFILES}; do \
							${REINPLACE_CMD} -e \
								'/^ltmain=/!s|$$ac_aux_dir/ltmain\.sh|${LIBTOOLFLAGS} ${WRKDIR}/gnome-ltmain.sh|g; \
								 /^LIBTOOL=/s|$$(top_builddir)/libtool|${WRKDIR}/gnome-libtool|g' \
								${PATCH_WRKSRC}/$$file; \
						done;
.else
.  if ${USE_GNOME:Mltverhack}!=""
BROKEN=	${PORTNAME} uses the ltverhack GNOME component but does not use libtool
.  endif
.endif

ltverhack_PATCH_DEPENDS=${LIBTOOL_DEPENDS}
ltverhack_PRE_PATCH+=	for file in gnome-ltmain.sh gnome-libtool; do \
							if [ -f ${WRKDIR}/$$file ]; then \
								${REINPLACE_CMD} -e \
									'/freebsd-elf)/,/;;/ s|major="\.$$current"|major=.`expr $$current - $$age`|; \
									 /freebsd-elf)/,/;;/ s|versuffix="\.$$current"|versuffix="$$major"|' \
									${WRKDIR}/$$file; \
							fi; \
						done

# Then traverse through all components, check which of them
# exist in ${_USE_GNOME} and set variables accordingly
. for component in ${_USE_GNOME_ALL}
_COMP_TEST=	${_USE_GNOME:M${component}}
.  if ${_COMP_TEST:S/${component}//}!=${_COMP_TEST:S/  / /g}
PATCH_DEPENDS+=	${${component}_PATCH_DEPENDS}
FETCH_DEPENDS+=	${${component}_FETCH_DEPENDS}
EXTRACT_DEPENDS+=${${component}_EXTRACT_DEPENDS}
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
LIB_DEPENDS+=	${${component}_LIB_DEPENDS}
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}

CONFIGURE_ARGS+=${${component}_CONFIGURE_ARGS}
CONFIGURE_ENV+=	${${component}_CONFIGURE_ENV}
MAKE_ENV+=	${${component}_MAKE_ENV}

.    if !defined(CONFIGURE_TARGET) && defined(${component}_CONFIGURE_TARGET)
CONFIGURE_TARGET=	${${component}_CONFIGURE_TARGET}
.    endif

.    if defined(${component}_PRE_PATCH)
GNOME_PRE_PATCH+=	; ${${component}_PRE_PATCH}
.    endif

.  endif
. endfor
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

.if ${MAINTAINER}=="gnome@FreeBSD.org"
CONFIGURE_FAIL_MESSAGE= "Please run the gnomelogalyzer, available from \"http://www.freebsd.org/gnome/gnomelogalyzer.sh\", which will diagnose the problem and suggest a solution. If - and only if - the gnomelogalyzer cannot solve the problem, report the build failure to the FreeBSD GNOME team at ${MAINTAINER}, and attach (a) \"${CONFIGURE_WRKSRC}/${CONFIGURE_LOG}\", (b) the output of the failed make command, and (c) the gnomelogalyzer output. Also, it might be a good idea to provide an overview of all packages installed on your system (i.e. an \`ls ${PKG_DBDIR}\`). Put your attachment up on any website, copy-and-paste into http://freebsd-gnome.pastebin.com, or use send-pr(1) with the attachment. Try to avoid sending any attachments to the mailing list (${MAINTAINER}), because attachments sent to FreeBSD mailing lists are usually discarded by the mailing list software."
.endif


.if defined(GCONF_SCHEMAS) || defined(INSTALLS_OMF) || defined(INSTALLS_ICONS) \
	|| (defined(_USE_GNOME) && ${_USE_GNOME:Mgnomeprefix}!="")
pre-su-install: gnome-pre-su-install
post-install: gnome-post-install

gnome-pre-su-install:
.if defined(_USE_GNOME) && ${_USE_GNOME:Mgnomeprefix}!="" && !defined(NO_MTREE)
	@${MTREE_CMD} ${MTREE_ARGS:S/${MTREE_FILE}/${GNOME_MTREE_FILE}/} ${PREFIX}/ >/dev/null
.endif
.if defined(GCONF_SCHEMAS)
	@${MKDIR} ${PREFIX}/etc/gconf/gconf.xml.defaults/
.else
	@${DO_NADA}
.endif

gnome-post-install:
.  if defined(GCONF_SCHEMAS)
	@for i in ${GCONF_SCHEMAS}; do \
		${ECHO_CMD} "@unexec env GCONF_CONFIG_SOURCE=xml:${GCONF_CONFIG_OPTIONS}:%D/${GCONF_CONFIG_DIRECTORY} gconftool-2 --makefile-uninstall-rule %D/etc/gconf/schemas/$${i} > /dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
		${ECHO_CMD} "etc/gconf/schemas/$${i}" >> ${TMPPLIST}; \
		${ECHO_CMD} "@exec env GCONF_CONFIG_SOURCE=xml:${GCONF_CONFIG_OPTIONS}:%D/${GCONF_CONFIG_DIRECTORY} gconftool-2 --makefile-install-rule %D/etc/gconf/schemas/$${i} > /dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
	done
.  endif

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
		${ECHO_CMD} "@unexec /bin/rm %D/$${i}/icon-theme.cache 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}.icons1; \
		${ECHO_CMD} "@exec ${X11BASE}/bin/gtk-update-icon-cache -q -f %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
		${ECHO_CMD} "@unexec ${X11BASE}/bin/gtk-update-icon-cache -q -f %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
		${X11BASE}/bin/gtk-update-icon-cache -q -f ${PREFIX}/$${i} 2>/dev/null || ${TRUE}; \
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
