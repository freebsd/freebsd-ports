#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#	$NetBSD: $
#
# Please view me with 4 column tabs!

# ======================= USERS =================================
#
# There are no significant user-definable settings in here.
# This file is a framework to make it easier to create GNOME ports.
#
# ======================= /USERS ================================

# Please make sure all changes to this file are passed through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).

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
# MAINTAINER: gnome@FreeBSD.org

.if !defined(_INCLUDE_USES_GNOME_MK)
_INCLUDE_USES_GNOME_MK=        yes

_USES_POST+=	gnome

.if !empty(gnome_ARGS)
IGNORE=	USES=gnome takes no arguments
.endif

# non-version specific components
_USE_GNOME_ALL= intlhack intltool introspection \
		referencehack gnomemimedata \
		gnomeprefix

# GNOME 2 components
_USE_GNOME_ALL+= atk cairo \
		gdkpixbuf2 gconf2 glib20 \
		gnomedocutils gnomesharp20 \
		gnomevfs2 gtk-update-icon-cache gtk20 gtkhtml3 \
		gtksharp20 gtksourceview2 gvfs libartlgpl2 libbonobo \
		libbonoboui libglade2 libgnome \
		libgnomecanvas libgnomekbd \
		libgnomeui libgsf libgtkhtml libidl librsvg2 libwnck \
		libxml2 libxslt \
		orbit2 pango pangox-compat pygnome2 pygobject pygtk2 \
		pygtksourceview vte

# GNOME 3 components
_USE_GNOME_ALL+=dconf evolutiondataserver3 gnomecontrolcenter3 gnomedesktop3 \
		gnomemenus3 gsound gtk30 gtkhtml4 gtksourceview3 \
		gtksourceview4 libgda5 \
		libgda5-ui libwnck3 metacity nautilus3 \
		pygobject3 vte3

# C++ bindings
_USE_GNOME_ALL+=atkmm cairomm gconfmm26 glibmm gtkmm20 gtkmm24 \
		gtkmm30 gtksourceviewmm3 libgdamm5 \
		libgtksourceviewmm libxml++26 libsigc++12 libsigc++20 \
		pangomm

# glib-mkenums often fails with C locale
# https://gitlab.gnome.org/GNOME/glib/issues/1430
USE_LOCALE?=	en_US.UTF-8

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

atkmm_LIB_DEPENDS=	libatkmm-1.6.so:accessibility/atkmm
atkmm_USE_GNOME_IMPL=	glibmm atk

libxml++26_LIB_DEPENDS=		libxml++-2.6.so:textproc/libxml++26
libxml++26_USE_GNOME_IMPL=	glibmm libxml2

cairo_LIB_DEPENDS=	libcairo.so:graphics/cairo

cairomm_LIB_DEPENDS=	libcairomm-1.0.so:graphics/cairomm
cairomm_USE_GNOME_IMPL=	cairo libxml++26

gconfmm26_LIB_DEPENDS=		libgconfmm-2.6.so:devel/gconfmm26
gconfmm26_USE_GNOME_IMPL=	glibmm gconf2

glibmm_LIB_DEPENDS=	libglibmm-2.4.so:devel/glibmm
glibmm_USE_GNOME_IMPL=	libsigc++20 glib20

gsound_BUILD_DEPENDS=	gsound-play:audio/gsound
gsound_LIB_DEPENDS=	libgsound.so:audio/gsound
gsound_RUN_DEPENDS=	gsound-play:audio/gsound
gsound_USE_GNOME_IMPL=	glib20

gtkmm20_LIB_DEPENDS=	libgtkmm-2.0.so:x11-toolkits/gtkmm20
gtkmm20_USE_GNOME_IMPL=	libsigc++12 gtk20

gtkmm24_LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24
gtkmm24_USE_GNOME_IMPL=	glibmm cairomm atkmm pangomm gtk20

gtkmm30_LIB_DEPENDS=	libgtkmm-3.0.so:x11-toolkits/gtkmm30
gtkmm30_USE_GNOME_IMPL=	glibmm cairomm atkmm pangomm gtk30

gtksourceviewmm3_LIB_DEPENDS=		libgtksourceviewmm-3.0.so:x11-toolkits/gtksourceviewmm3
gtksourceviewmm3_USE_GNOME_IMPL=	gtkmm30 gtksourceview3

libgdamm5_LIB_DEPENDS=		libgdamm-5.0.so:databases/libgdamm5
libgdamm5_USE_GNOME_IMPL=	libgda5 glibmm

libgtksourceviewmm_LIB_DEPENDS=		libgtksourceviewmm-2.0.so:x11-toolkits/libgtksourceviewmm
libgtksourceviewmm_USE_GNOME_IMPL=	gtksourceview2 gtkmm24

libsigc++12_LIB_DEPENDS=	libsigc-1.2.so:devel/libsigc++12

libsigc++20_LIB_DEPENDS=	libsigc-2.0.so:devel/libsigc++20

pangomm_LIB_DEPENDS=	libpangomm-1.4.so:x11-toolkits/pangomm
pangomm_USE_GNOME_IMPL=	pango glibmm cairomm

gnomemimedata_BUILD_DEPENDS=${LOCALBASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc:misc/gnome-mime-data
gnomemimedata_RUN_DEPENDS=${LOCALBASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc:misc/gnome-mime-data

glib20_LIB_DEPENDS=	libglib-2.0.so:devel/glib20 \
					libintl.so:devel/gettext-runtime

atk_LIB_DEPENDS=	libatk-1.0.so:accessibility/atk
atk_USE_GNOME_IMPL=	glib20

dconf_BUILD_DEPENDS=	dconf:devel/dconf
dconf_LIB_DEPENDS=	libdconf.so:devel/dconf
dconf_RUN_DEPENDS=	dconf:devel/dconf
dconf_USE_GNOME_IMPL=	glib20

pango_LIB_DEPENDS=	libpango-1.0.so:x11-toolkits/pango
pango_USE_GNOME_IMPL=	glib20

pangox-compat_LIB_DEPENDS=	libpangox-1.0.so:x11-toolkits/pangox-compat
pangox-compat_USE_GNOME_IMPL=	glib20 pango

gdkpixbuf2_LIB_DEPENDS=	libgdk_pixbuf-2.0.so:graphics/gdk-pixbuf2
gdkpixbuf2_USE_GNOME_IMPL=glib20

gtk-update-icon-cache_BUILD_DEPENDS=	gtk-update-icon-cache:graphics/gtk-update-icon-cache
gtk-update-icon-cache_RUN_DEPENDS=	gtk-update-icon-cache:graphics/gtk-update-icon-cache
gtk-update-icon-cache_USE_GNOME_IMPL=	atk pango gdkpixbuf2

gtk20_LIB_DEPENDS=	libgtk-x11-2.0.so:x11-toolkits/gtk20
gtk20_USE_GNOME_IMPL=	atk pango
GTK2_VERSION=		2.10.0

gtk30_LIB_DEPENDS=	libgtk-3.so:x11-toolkits/gtk30
gtk30_USE_GNOME_IMPL=	atk pango
GTK3_VERSION=		3.0.0

libidl_LIB_DEPENDS=	libIDL-2.so:devel/libIDL
libidl_USE_GNOME_IMPL=	glib20

orbit2_LIB_DEPENDS=	libORBit-2.so:devel/ORBit2
orbit2_USE_GNOME_IMPL=	libidl

libglade2_LIB_DEPENDS=	libglade-2.0.so:devel/libglade2
libglade2_USE_GNOME_IMPL=libxml2 gtk20

libxml2_BUILD_DEPENDS=	xml2-config:textproc/libxml2
libxml2_LIB_DEPENDS=	libxml2.so:textproc/libxml2
libxml2_RUN_DEPENDS=	xml2-config:textproc/libxml2

libxslt_BUILD_DEPENDS=	xsltproc:textproc/libxslt
libxslt_LIB_DEPENDS=	libxslt.so:textproc/libxslt
libxslt_RUN_DEPENDS=	${libxslt_BUILD_DEPENDS}
libxslt_USE_GNOME_IMPL=	libxml2

libbonobo_LIB_DEPENDS=	libbonobo-2.so:devel/libbonobo
libbonobo_USE_GNOME_IMPL=libxml2 orbit2

introspection_BUILD_DEPENDS=	g-ir-scanner:devel/gobject-introspection
introspection_LIB_DEPENDS=	libgirepository-1.0.so:devel/gobject-introspection
introspection_RUN_DEPENDS=	g-ir-scanner:devel/gobject-introspection
introspection_USE_GNOME_IMPL=	glib20
introspection_MAKE_ENV=		GI_SCANNER_DISABLE_CACHE=1 XDG_CACHE_HOME=${WRKDIR}

gconf2_LIB_DEPENDS=	libgconf-2.so:devel/gconf2
gconf2_USE_GNOME_IMPL=	orbit2 libxml2 gtk20

gnomevfs2_LIB_DEPENDS=	libgnomevfs-2.so:devel/gnome-vfs
gnomevfs2_USE_GNOME_IMPL=gconf2 gnomemimedata

libgnomecanvas_LIB_DEPENDS=	libgnomecanvas-2.so:graphics/libgnomecanvas
libgnomecanvas_USE_GNOME_IMPL=	libglade2 libartlgpl2

libartlgpl2_LIB_DEPENDS=	libart_lgpl_2.so:graphics/libart_lgpl

libgnome_LIB_DEPENDS=	libgnome-2.so:x11/libgnome
libgnome_USE_GNOME_IMPL=gnomevfs2 libbonobo

libbonoboui_LIB_DEPENDS=	libbonoboui-2.so:x11-toolkits/libbonoboui
libbonoboui_USE_GNOME_IMPL=	libgnomecanvas libgnome

libgnomeui_LIB_DEPENDS=		libgnomeui-2.so:x11-toolkits/libgnomeui
libgnomeui_USE_GNOME_IMPL=	libbonoboui

libgtkhtml_LIB_DEPENDS=	libgtkhtml-2.so:www/libgtkhtml
libgtkhtml_USE_GNOME_IMPL=libxslt gnomevfs2

gnomedesktop3_LIB_DEPENDS=	libgnome-desktop-3.so:x11/gnome-desktop
gnomedesktop3_USE_GNOME_IMPL=	gtk30

libwnck_LIB_DEPENDS=	libwnck-1.so:x11-toolkits/libwnck
libwnck_USE_GNOME_IMPL=	gtk20

libwnck3_LIB_DEPENDS=	libwnck-3.so:x11-toolkits/libwnck3
libwnck3_USE_GNOME_IMPL=gtk30

vte_LIB_DEPENDS=	libvte.so:x11-toolkits/vte
vte_USE_GNOME_IMPL=	gtk20

vte3_LIB_DEPENDS=	libvte-2.91.so:x11-toolkits/vte3
vte3_USE_GNOME_IMPL=	gtk30

librsvg2_LIB_DEPENDS=	librsvg-2.so:graphics/librsvg2
librsvg2_USE_GNOME_IMPL=libgsf gdkpixbuf2 pango

nautilus3_LIB_DEPENDS=	libnautilus-extension.so:x11-fm/nautilus
nautilus3_USE_GNOME_IMPL=gnomedesktop3 gvfs libxml2

metacity_LIB_DEPENDS=	libmetacity-private.so:x11-wm/metacity

gnomecontrolcenter3_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-keybindings.pc:sysutils/gnome-control-center
gnomecontrolcenter3_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-keybindings.pc:sysutils/gnome-control-center
gnomecontrolcenter3_USE_GNOME_IMPL=	gnomedesktop3

libgda5_LIB_DEPENDS=	libgda-5.0.so:databases/libgda5
libgda5_USE_GNOME_IMPL=	glib20 libxslt

libgda5-ui_LIB_DEPENDS=	libgda-ui-5.0.so:databases/libgda5-ui
libgda5-ui_USE_GNOME_IMPL=glib20 libxslt libgda5

gtksourceview2_LIB_DEPENDS=	libgtksourceview-2.0.so:x11-toolkits/gtksourceview2
gtksourceview2_USE_GNOME_IMPL=gtk20 libxml2

gtksourceview3_LIB_DEPENDS=	libgtksourceview-3.0.so:x11-toolkits/gtksourceview3
gtksourceview3_USE_GNOME_IMPL=gtk30 libxml2

gtksourceview4_LIB_DEPENDS=	libgtksourceview-4.so:x11-toolkits/gtksourceview4
gtksourceview4_USE_GNOME_IMPL=gtk30 libxml2

libgsf_LIB_DEPENDS=	libgsf-1.so:devel/libgsf
libgsf_USE_GNOME_IMPL=	glib20 libxml2

pygobject_BUILD_DEPENDS=	pygobject-codegen-2.0:devel/py-gobject
pygobject_RUN_DEPENDS=		pygobject-codegen-2.0:devel/py-gobject
pygobject_USE_GNOME_IMPL=	glib20

pygobject3_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>=0:devel/py-gobject3@${PY_FLAVOR}
pygobject3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}gobject3>=0:devel/py-gobject3@${PY_FLAVOR}
pygobject3_USE_GNOME_IMPL=	glib20

pygtk2_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pygtk-2.0.pc:x11-toolkits/py-gtk2
pygtk2_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pygtk-2.0.pc:x11-toolkits/py-gtk2
pygtk2_USE_GNOME_IMPL=	libglade2 pygobject

pygnome2_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-python-2.0.pc:x11-toolkits/py-gnome2
pygnome2_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-python-2.0.pc:x11-toolkits/py-gnome2
pygnome2_USE_GNOME_IMPL=libgnomeui pygtk2

intltool_BUILD_DEPENDS=	${LOCALBASE}/bin/intltool-extract:textproc/intltool

intlhack_PRE_PATCH=	${FIND} ${WRKSRC} -name "intltool-merge.in" | ${XARGS} ${REINPLACE_CMD} \
			's|mkdir $$lang or|mkdir $$lang, 0777 or| ; \
			 s|^push @INC, "/.*|push @INC, "${LOCALBASE}/share/intltool";| ; \
			 s|/usr/bin/iconv|${ICONV_CMD}|g ; \
			 s|unpack *[(]'"'"'U\*'"'"'|unpack ('"'"'C*'"'"'|' ; \
			${FIND} ${WRKSRC} -name configure | ${XARGS} ${REINPLACE_CMD} \
			's/DATADIRNAME=lib/DATADIRNAME=share/'
intlhack_USE_GNOME_IMPL=intltool

gtkhtml3_LIB_DEPENDS=	libgtkhtml-3.14.so:www/gtkhtml3
gtkhtml3_USE_GNOME_IMPL=libglade2

gtkhtml4_LIB_DEPENDS=	libgtkhtml-4.0.so:www/gtkhtml4
gtkhtml4_USE_GNOME_IMPL=gtk30 libxml2

evolutiondataserver3_LIB_DEPENDS=	libedataserver-1.2.so:databases/evolution-data-server
evolutiondataserver3_USE_GNOME_IMPL=	libxml2 gtk30

gnomemenus3_BUILD_DEPENDS=	gnome-menus>=3.2.0:x11/gnome-menus
gnomemenus3_RUN_DEPENDS=	gnome-menus>=3.2.0:x11/gnome-menus
gnomemenus3_USE_GNOME_IMPL=	glib20

gnomedocutils_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-doc-utils.pc:textproc/gnome-doc-utils
gnomedocutils_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-doc-utils.pc:textproc/gnome-doc-utils
gnomedocutils_USE_GNOME_IMPL=	libxslt

gtksharp10_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-sharp.pc:x11-toolkits/gtk-sharp10
gtksharp10_RUN_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/gtk-sharp.pc:x11-toolkits/gtk-sharp10
gtksharp10_USE_GNOME_IMPL=	gtk20

gtksharp20_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-sharp-2.0.pc:x11-toolkits/gtk-sharp20
gtksharp20_RUN_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/gtk-sharp-2.0.pc:x11-toolkits/gtk-sharp20
gtksharp20_USE_GNOME_IMPL=	gtk20

gnomesharp20_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-sharp-2.0.pc:x11-toolkits/gnome-sharp20
gnomesharp20_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-sharp-2.0.pc:x11-toolkits/gnome-sharp20
gnomesharp20_USE_GNOME_IMPL=	gnomevfs2 gtkhtml3 gtksharp20 librsvg2 vte

libgnomekbd_LIB_DEPENDS=	libgnomekbd.so:x11/libgnomekbd
libgnomekbd_USE_GNOME_IMPL=	gtk30 libxml2

pygtksourceview_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pygtksourceview-2.0.pc:x11-toolkits/py-gtksourceview
pygtksourceview_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pygtksourceview-2.0.pc:x11-toolkits/py-gtksourceview
pygtksourceview_USE_GNOME_IMPL=	gtksourceview2 pygtk2

gvfs_BUILD_DEPENDS=	gvfs>=0:devel/gvfs
gvfs_RUN_DEPENDS=	gvfs>=0:devel/gvfs
gvfs_USE_GNOME_IMPL=	glib20

.if defined(INSTALLS_ICONS)
USE_GNOME+=	gtk-update-icon-cache
.endif

# End component definition section

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
.  if ${_USE_GNOME_ALL:M${component}}==""
IGNORE=	cannot install: Unknown component ${component}
.  endif
_USE_GNOME+=	${${component}_USE_GNOME_IMPL} ${component}
. endfor

# Setup the GTK+ API version for pixbuf loaders, input method modules,
# and theme engines.
PLIST_SUB+=			GTK2_VERSION="${GTK2_VERSION}" \
				GTK3_VERSION="${GTK3_VERSION}"

.if defined(_USE_GNOME) && empty(_USE_GNOME:Mglib20:u) && defined(GLIB_SCHEMAS)
IGNORE=		GLIB_SCHEMAS is set, but needs USE_GNOME=glib20 to work
.endif

.if defined(_USE_GNOME) && empty(_USE_GNOME:Mgconf2:u) && defined(GCONF_SCHEMAS)
IGNORE=		GCONF_SCHEMAS is set, but needs USE_GNOME=gconf2 to work
.endif

# Then traverse through all components, check which of them
# exist in ${_USE_GNOME} and set variables accordingly
.ifdef _USE_GNOME

. for component in ${_USE_GNOME:O:u}
.  if defined(${component}_PATCH_DEPENDS)
PATCH_DEPENDS+=	${${component}_PATCH_DEPENDS}
.  endif

.  if ${USE_GNOME:M${component}\:build} && defined(${component}_BUILD_DEPENDS)
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
.  elif ${USE_GNOME:M${component}\:run} && defined(${component}_RUN_DEPENDS)
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}
.  else
.   if defined(${component}_LIB_DEPENDS)
LIB_DEPENDS+=	${${component}_LIB_DEPENDS}
.   else
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}
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

.if defined(USE_GNOME_SUBR)
GNOME_SUBR=		${LOCALBASE}/etc/gnome.subr
RUN_DEPENDS+=	${GNOME_SUBR}:sysutils/gnome_subr
SUB_LIST+=		GNOME_SUBR=${GNOME_SUBR}
.endif

.endif
# end of the part

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_GNOME_POST_MK)
_INCLUDE_USES_GNOME_POST_MK=     yes

.if defined(GNOME_PRE_PATCH)
_USES_patch+=	290:gnome-pre-patch
gnome-pre-patch:
	@${GNOME_PRE_PATCH:C/^;//1}
.endif

.if defined(GCONF_SCHEMAS)
_USES_install+=	690:gnome-post-gconf-schemas
gnome-post-gconf-schemas:
	@for i in ${GCONF_SCHEMAS}; do \
		${ECHO_CMD} "@postunexec env GCONF_CONFIG_SOURCE=xml:${GCONF_CONFIG_OPTIONS}:%D/${GCONF_CONFIG_DIRECTORY} HOME=${WRKDIR} gconftool-2 --makefile-uninstall-rule %D/etc/gconf/schemas/$${i} > /dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
		${ECHO_CMD} "etc/gconf/schemas/$${i}" >> ${TMPPLIST}; \
		${ECHO_CMD} "@postexec env GCONF_CONFIG_SOURCE=xml:${GCONF_CONFIG_OPTIONS}:%D/${GCONF_CONFIG_DIRECTORY} HOME=${WRKDIR} gconftool-2 --makefile-install-rule %D/etc/gconf/schemas/$${i} > /dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
	done
.endif

# we put the @unexec behind the plist schema entry, because it compiles files 
# in the directory. So we should remove the port file first before recompiling.
.if defined(GLIB_SCHEMAS)
_USES_install+=	690:gnome-post-glib-schemas
gnome-post-glib-schemas:
	@for i in ${GLIB_SCHEMAS}; do \
		${ECHO_CMD} "share/glib-2.0/schemas/$${i}" >> ${TMPPLIST}; \
	done
	@${ECHO_CMD} "@glib-schemas" >> ${TMPPLIST};
.endif

.if defined(INSTALLS_OMF)
_USES_install+=	690:gnome-post-omf
gnome-post-omf:
	@for i in `${GREP} "\.omf$$" ${TMPPLIST}`; do \
		${ECHO_CMD} "@postexec scrollkeeper-install -q %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
		${ECHO_CMD} "@postunexec scrollkeeper-uninstall -q %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
	done
.endif

.if defined(INSTALLS_ICONS)
_USES_install+=	690:gnome-post-icons
gnome-post-icons:
	@${RM} ${TMPPLIST}.icons1
	@for i in `${GREP} "^share/icons/.*/" ${TMPPLIST} | ${CUT} -d / -f 1-3 | ${SORT} -u`; do \
		${ECHO_CMD} "@rmtry $${i}/icon-theme.cache" \
			>> ${TMPPLIST}.icons1; \
		${ECHO_CMD} "@postexec ${LOCALBASE}/bin/gtk-update-icon-cache -q -f %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
		${ECHO_CMD} "@postunexec ${LOCALBASE}/bin/gtk-update-icon-cache -q -f %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
	done
	@if test -f ${TMPPLIST}.icons1; then \
		${CAT} ${TMPPLIST}.icons1 ${TMPPLIST} > ${TMPPLIST}.icons2; \
		${RM} ${TMPPLIST}.icons1; \
		${MV} -f ${TMPPLIST}.icons2 ${TMPPLIST}; \
	fi
.endif

.endif
# End of use part.
