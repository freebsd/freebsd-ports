#-*- tab-width: 4; -*-
# ex:ts=4
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
#				file and add apropriate @postexec/@postunexec directives for
#				each .omf file found to track OMF registration database.
#
# MAINTAINER: gnome@FreeBSD.org

.if !defined(_INCLUDE_USES_GNOME_MK)
_INCLUDE_USES_GNOME_MK=        yes

_USES_POST+=	gnome

.  if !empty(gnome_ARGS)
IGNORE=	USES=gnome takes no arguments
.  endif

# non-version specific components
_USE_GNOME_ALL= intlhack intltool introspection \
		gnomemimedata gnomeprefix

# GNOME 2 components
_USE_GNOME_ALL+= atk cairo \
		gdkpixbuf gdkpixbuf2xlib gdkpixbufextra gconf2 glib20 \
		gtk-update-icon-cache gtk20 \
		gtksharp20 gtksourceview2 gvfs libartlgpl2 \
		libglade2 libgnomecanvas \
		libgsf libidl librsvg2 \
		libxml2 libxslt \
		pango pangoft2 pangox-compat \
		vte

# GNOME 3 components
_USE_GNOME_ALL+=dconf evolutiondataserver3 gnomecontrolcenter3 gnomedesktop3 \
		gnomemenus3 gsound gtk30 gtkhtml4 gtksourceview3 \
		gtksourceview4 libgda5 \
		libgda5-ui libgda6 libgnomekbd libwnck3 \
		pygobject3 vte3

# GNOME 40 components
_USE_GNOME_ALL+=gtk40 libadwaita gtksourceview5 gnomedesktop4 nautilus4

# C++ bindings
_USE_GNOME_ALL+=atkmm cairomm cairomm11 glibmm glibmm26 gtkmm24 \
		gtkmm30 gtkmm40 gtksourceviewmm3 libxml++26 libsigc++20 \
		libsigc++30 pangomm pangomm24

# glib-mkenums often fails with C locale
# https://gitlab.gnome.org/GNOME/glib/issues/1430
USE_LOCALE?=	en_US.UTF-8

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
cairomm_USE_GNOME_IMPL=	cairo libsigc++20

cairomm11_LIB_DEPENDS=	libcairomm-1.16.so:graphics/cairomm11
cairomm11_USE_GNOME_IMPL=	cairo libsigc++30

glibmm_LIB_DEPENDS=	libglibmm-2.4.so:devel/glibmm
glibmm_USE_GNOME_IMPL=	libsigc++20 glib20

glibmm26_LIB_DEPENDS=	libglibmm-2.68.so:devel/glibmm26
glibmm26_USE_GNOME_IMPL=	libsigc++30 glib20

gsound_BUILD_DEPENDS=	gsound-play:audio/gsound
gsound_LIB_DEPENDS=	libgsound.so:audio/gsound
gsound_RUN_DEPENDS=	gsound-play:audio/gsound
gsound_USE_GNOME_IMPL=	glib20

gtkmm24_LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24
gtkmm24_USE_GNOME_IMPL=	glibmm cairomm atkmm pangomm gtk20

gtkmm30_LIB_DEPENDS=	libgtkmm-3.0.so:x11-toolkits/gtkmm30
gtkmm30_USE_GNOME_IMPL=	atkmm cairomm gdkpixbuf glibmm gtk30 pangomm

gtkmm40_LIB_DEPENDS=	libgtkmm-4.0.so:x11-toolkits/gtkmm40
gtkmm40_USE_GNOME_IMPL=	cairomm11 gdkpixbuf glibmm26 gtk40 pangomm24

gtksourceviewmm3_LIB_DEPENDS=		libgtksourceviewmm-3.0.so:x11-toolkits/gtksourceviewmm3
gtksourceviewmm3_USE_GNOME_IMPL=	gtkmm30 gtksourceview3

libsigc++20_LIB_DEPENDS=	libsigc-2.0.so:devel/libsigc++20

libsigc++30_LIB_DEPENDS=	libsigc-3.0.so:devel/libsigc++30

pangomm_LIB_DEPENDS=	libpangomm-1.4.so:x11-toolkits/pangomm
pangomm_USE_GNOME_IMPL=	pango glibmm cairomm

pangomm24_LIB_DEPENDS=	libpangomm-2.48.so:x11-toolkits/pangomm24
pangomm24_USE_GNOME_IMPL=	pango glibmm26 cairomm11

gnomemimedata_BUILD_DEPENDS=${LOCALBASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc:misc/gnome-mime-data
gnomemimedata_RUN_DEPENDS=${LOCALBASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc:misc/gnome-mime-data

glib20_LIB_DEPENDS=	libglib-2.0.so:devel/glib20 \
					libintl.so:devel/gettext-runtime

atk_LIB_DEPENDS=	libatk-1.0.so:accessibility/at-spi2-core
atk_USE_GNOME_IMPL=	glib20

dconf_BUILD_DEPENDS=	dconf:devel/dconf
dconf_LIB_DEPENDS=	libdconf.so:devel/dconf
dconf_RUN_DEPENDS=	dconf:devel/dconf
dconf_USE_GNOME_IMPL=	glib20

pango_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
			libpango-1.0.so:x11-toolkits/pango
pango_USE_GNOME_IMPL=	glib20

pangoft2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
pangoft2_USE_GNOME_IMPL=pango

pangox-compat_LIB_DEPENDS=	libpangox-1.0.so:x11-toolkits/pangox-compat
pangox-compat_USE_GNOME_IMPL=	glib20 pango

gdkpixbuf_LIB_DEPENDS=	libgdk_pixbuf-2.0.so:graphics/gdk-pixbuf2
gdkpixbuf_USE_GNOME_IMPL=glib20

gdkpixbuf2xlib_LIB_DEPENDS=	libgdk_pixbuf_xlib-2.0.so:graphics/gdk-pixbuf2-xlib
gdkpixbuf2xlib_USE_GNOME_IMPL=	glib20 gdkpixbuf

gdkpixbufextra_BUILD_DEPENDS=	gdk-pixbuf-extra>=0.1.0:graphics/gdk-pixbuf-extra
gdkpixbufextra_RUN_DEPENDS=	gdk-pixbuf-extra>=0.1.0:graphics/gdk-pixbuf-extra
gdkpixbufextra_USE_GNOME_IMPL=	glib20 gdkpixbuf

gtk-update-icon-cache_RUN_DEPENDS=	gtk-update-icon-cache:graphics/gtk-update-icon-cache

gtk20_LIB_DEPENDS=	libgtk-x11-2.0.so:x11-toolkits/gtk20
gtk20_USE_GNOME_IMPL=	atk cairo gdkpixbuf pangoft2
GTK2_VERSION=		2.10.0

gtk30_LIB_DEPENDS=	libgtk-3.so:x11-toolkits/gtk30
gtk30_USE_GNOME_IMPL=	atk cairo gdkpixbuf pango
GTK3_VERSION=		3.0.0

gtk40_LIB_DEPENDS=	libgtk-4.so:x11-toolkits/gtk40
gtk40_USE_GNOME_IMPL=	atk pango
GTK4_VERSION=		4.0.0

libidl_LIB_DEPENDS=	libIDL-2.so:devel/libIDL
libidl_USE_GNOME_IMPL=	glib20

libglade2_LIB_DEPENDS=	libglade-2.0.so:devel/libglade2
libglade2_USE_GNOME_IMPL=libxml2 gtk20

libxml2_BUILD_DEPENDS=	xml2-config:textproc/libxml2
libxml2_LIB_DEPENDS=	libxml2.so:textproc/libxml2
libxml2_RUN_DEPENDS=	xml2-config:textproc/libxml2

libxslt_BUILD_DEPENDS=	xsltproc:textproc/libxslt
libxslt_LIB_DEPENDS=	libxslt.so:textproc/libxslt
libxslt_RUN_DEPENDS=	${libxslt_BUILD_DEPENDS}
libxslt_USE_GNOME_IMPL=	libxml2

introspection_BUILD_DEPENDS=	g-ir-scanner:devel/gobject-introspection
introspection_LIB_DEPENDS=	libgirepository-1.0.so:devel/gobject-introspection
introspection_RUN_DEPENDS=	g-ir-scanner:devel/gobject-introspection
introspection_USE_GNOME_IMPL=	glib20
introspection_MAKE_ENV=		GI_SCANNER_DISABLE_CACHE=1

gconf2_LIB_DEPENDS=	libgconf-2.so:devel/gconf2
gconf2_USE_GNOME_IMPL=	libxml2

libgnomecanvas_LIB_DEPENDS=	libgnomecanvas-2.so:graphics/libgnomecanvas
libgnomecanvas_USE_GNOME_IMPL=	libglade2 libartlgpl2

libartlgpl2_LIB_DEPENDS=	libart_lgpl_2.so:graphics/libart_lgpl

gnomedesktop3_LIB_DEPENDS=	libgnome-desktop-3.so:x11/gnome-desktop
gnomedesktop3_USE_GNOME_IMPL=	gtk30

gnomedesktop4_LIB_DEPENDS=	libgnome-desktop-4.so:x11/gnome-desktop
gnomedesktop4_USE_GNOME_IMPL=	gtk40

libwnck3_LIB_DEPENDS=	libwnck-3.so:x11-toolkits/libwnck3
libwnck3_USE_GNOME_IMPL=gtk30

vte_LIB_DEPENDS=	libvte.so:x11-toolkits/vte
vte_USE_GNOME_IMPL=	gtk20

vte3_LIB_DEPENDS=	libvte-2.91.so:x11-toolkits/vte3
vte3_USE_GNOME_IMPL=	gtk30

libadwaita_LIB_DEPENDS=		libadwaita-1.so:x11-toolkits/libadwaita
libadwaita_USE_GNOME_IMPL=	gtk40

# Use librsvg2-rust where lang/rust is available
.  if ${LIBRSVG2_DEFAULT:Mrust}
librsvg2_BUILD_DEPENDS=	librsvg2-rust>=0:graphics/librsvg2-rust
librsvg2_LIB_DEPENDS=	librsvg-2.so:graphics/librsvg2-rust
librsvg2_RUN_DEPENDS=	librsvg2-rust>=0:graphics/librsvg2-rust
.  else
librsvg2_BUILD_DEPENDS=	librsvg2>=0:graphics/librsvg2
librsvg2_LIB_DEPENDS=	librsvg-2.so:graphics/librsvg2
librsvg2_RUN_DEPENDS=	librsvg2>=0:graphics/librsvg2
.  endif
librsvg2_USE_GNOME_IMPL=cairo gdkpixbuf

nautilus4_LIB_DEPENDS=	libnautilus-extension.so:x11-fm/nautilus
nautilus4_USE_GNOME_IMPL=glib20

gnomecontrolcenter3_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-keybindings.pc:sysutils/gnome-control-center
gnomecontrolcenter3_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-keybindings.pc:sysutils/gnome-control-center
gnomecontrolcenter3_USE_GNOME_IMPL=	gnomedesktop4

libgda5_LIB_DEPENDS=	libgda-5.0.so:databases/libgda5
libgda5_USE_GNOME_IMPL=	glib20 libxslt

libgda5-ui_LIB_DEPENDS=	libgda-ui-5.0.so:databases/libgda5-ui
libgda5-ui_USE_GNOME_IMPL=glib20 libxslt libgda5

libgda6_LIB_DEPENDS=	libgda-6.0.so:databases/libgda6
libgda6_USE_GNOME_IMPL=	glib20 libxml2

gtksourceview2_LIB_DEPENDS=	libgtksourceview-2.0.so:x11-toolkits/gtksourceview2
gtksourceview2_USE_GNOME_IMPL=gtk20 libxml2

gtksourceview3_LIB_DEPENDS=	libgtksourceview-3.0.so:x11-toolkits/gtksourceview3
gtksourceview3_USE_GNOME_IMPL=gtk30 libxml2

gtksourceview4_LIB_DEPENDS=	libgtksourceview-4.so:x11-toolkits/gtksourceview4
gtksourceview4_USE_GNOME_IMPL=gtk30 libxml2

gtksourceview5_LIB_DEPENDS=	libgtksourceview-5.so:x11-toolkits/gtksourceview5
gtksourceview5_USE_GNOME_IMPL=gtk40 libxml2

libgsf_LIB_DEPENDS=	libgsf-1.so:devel/libgsf
libgsf_USE_GNOME_IMPL=	glib20 libxml2

pygobject3_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygobject>=0:devel/py-pygobject@${PY_FLAVOR}
pygobject3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pygobject>=0:devel/py-pygobject@${PY_FLAVOR}
pygobject3_USE_GNOME_IMPL=	glib20

intltool_BUILD_DEPENDS=	${LOCALBASE}/bin/intltool-extract:textproc/intltool

intlhack_PRE_PATCH=	${FIND} ${WRKSRC} -name "intltool-merge.in" | ${XARGS} ${FRAMEWORK_REINPLACE_CMD} \
			's|mkdir $$lang or|mkdir $$lang, 0777 or| ; \
			 s|^push @INC, "/.*|push @INC, "${LOCALBASE}/share/intltool";| ; \
			 s|/usr/bin/iconv|${ICONV_CMD}|g ; \
			 s|unpack *[(]'"'"'U\*'"'"'|unpack ('"'"'C*'"'"'|' ; \
			${FIND} ${WRKSRC} -name configure | ${XARGS} ${FRAMEWORK_REINPLACE_CMD} \
			's/DATADIRNAME=lib/DATADIRNAME=share/'
intlhack_USE_GNOME_IMPL=intltool

gtkhtml4_LIB_DEPENDS=	libgtkhtml-4.0.so:www/gtkhtml4
gtkhtml4_USE_GNOME_IMPL=gtk30 libxml2

evolutiondataserver3_LIB_DEPENDS=	libedataserver-1.2.so:databases/evolution-data-server
evolutiondataserver3_USE_GNOME_IMPL=	libxml2 gtk30

gnomemenus3_BUILD_DEPENDS=	gnome-menus>=3.2.0:x11/gnome-menus
gnomemenus3_RUN_DEPENDS=	gnome-menus>=3.2.0:x11/gnome-menus
gnomemenus3_USE_GNOME_IMPL=	glib20

gtksharp20_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-sharp-2.0.pc:x11-toolkits/gtk-sharp20
gtksharp20_RUN_DEPENDS=		${LOCALBASE}/libdata/pkgconfig/gtk-sharp-2.0.pc:x11-toolkits/gtk-sharp20
gtksharp20_USE_GNOME_IMPL=	gtk20

libgnomekbd_LIB_DEPENDS=	libgnomekbd.so:x11/libgnomekbd
libgnomekbd_USE_GNOME_IMPL=	gtk30 libxml2

gvfs_BUILD_DEPENDS=	gvfs>=0:filesystems/gvfs
gvfs_RUN_DEPENDS=	gvfs>=0:filesystems/gvfs

# End component definition section

.  if defined(USE_GNOME)
# First of all expand all USE_GNOME_IMPL recursively
.    for component in ${_USE_GNOME_ALL}
.      for subcomponent in ${${component}_USE_GNOME_IMPL}
${component}_USE_GNOME_IMPL+=${${subcomponent}_USE_GNOME_IMPL}
.      endfor
.    endfor

# Then use already expanded USE_GNOME_IMPL to expand USE_GNOME.
# Also, check to see if each component has a desktop requirement.  If it does,
# and if the user's chosen desktop is not of the same version, mark the
# port as IGNORE.
.    for component in ${USE_GNOME:C/^([^:]+).*/\1/}
.      if ${_USE_GNOME_ALL:M${component}}==""
IGNORE=	cannot install: Unknown component ${component}
.      endif
_USE_GNOME+=	${${component}_USE_GNOME_IMPL} ${component}
.    endfor

# Setup the GTK API version for pixbuf loaders, input method modules,
# and theme engines.
PLIST_SUB+=			GTK2_VERSION="${GTK2_VERSION}" \
				GTK3_VERSION="${GTK3_VERSION}" \
				GTK4_VERSION="${GTK4_VERSION}"

.    if defined(_USE_GNOME) && empty(_USE_GNOME:Mglib20:u) && defined(GLIB_SCHEMAS)
IGNORE=		GLIB_SCHEMAS is set, but needs USE_GNOME=glib20 to work
.    endif

.    if defined(_USE_GNOME) && empty(_USE_GNOME:Mgconf2:u) && defined(GCONF_SCHEMAS)
IGNORE=		GCONF_SCHEMAS is set, but needs USE_GNOME=gconf2 to work
.    endif

# Then traverse through all components, check which of them
# exist in ${_USE_GNOME} and set variables accordingly
.    ifdef _USE_GNOME

.      for component in ${_USE_GNOME:O:u}
.        if defined(${component}_PATCH_DEPENDS)
PATCH_DEPENDS+=	${${component}_PATCH_DEPENDS}
.        endif

.        if ${USE_GNOME:M${component}\:build} && defined(${component}_BUILD_DEPENDS)
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
.        elif ${USE_GNOME:M${component}\:run} && defined(${component}_RUN_DEPENDS)
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}
.        else
.          if defined(${component}_LIB_DEPENDS)
LIB_DEPENDS+=	${${component}_LIB_DEPENDS}
.          else
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}
.          endif
.        endif

.        if defined(${component}_CONFIGURE_ARGS)
CONFIGURE_ARGS+=${${component}_CONFIGURE_ARGS}
.        endif

.        if defined(${component}_CONFIGURE_ENV)
CONFIGURE_ENV+=	${${component}_CONFIGURE_ENV}
.        endif

.        if defined(${component}_MAKE_ENV)
MAKE_ENV+=	${${component}_MAKE_ENV}
.        endif

.        if !defined(CONFIGURE_TARGET) && defined(${component}_CONFIGURE_TARGET)
CONFIGURE_TARGET=	${${component}_CONFIGURE_TARGET}
.        endif

.        if defined(${component}_PRE_PATCH)
GNOME_PRE_PATCH+=	; ${${component}_PRE_PATCH}
.        endif
.      endfor
.    endif

.    if defined(GCONF_SCHEMAS)
MAKE_ENV+=	GCONF_DISABLE_MAKEFILE_SCHEMA_INSTALL=1
.    endif
.  endif

.  if defined(USE_GNOME_SUBR)
GNOME_SUBR=		${LOCALBASE}/etc/gnome.subr
RUN_DEPENDS+=	${GNOME_SUBR}:sysutils/gnome_subr
SUB_LIST+=		GNOME_SUBR=${GNOME_SUBR}
.  endif

.endif
# end of the part

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_GNOME_POST_MK)
_INCLUDE_USES_GNOME_POST_MK=     yes

.  if defined(GNOME_PRE_PATCH)
_USES_patch+=	290:gnome-pre-patch
gnome-pre-patch:
	@${GNOME_PRE_PATCH:C/^;//1}
.  endif

.  if defined(GCONF_SCHEMAS)
_USES_install+=	690:gnome-post-gconf-schemas
gnome-post-gconf-schemas:
	@for i in ${GCONF_SCHEMAS}; do \
		${ECHO_CMD} "@preunexec env GCONF_CONFIG_SOURCE=xml:${GCONF_CONFIG_OPTIONS}:%D/${GCONF_CONFIG_DIRECTORY} HOME=${WRKDIR} gconftool-2 --makefile-uninstall-rule %D/etc/gconf/schemas/$${i} > /dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
		${ECHO_CMD} "etc/gconf/schemas/$${i}" >> ${TMPPLIST}; \
		${ECHO_CMD} "@postexec env GCONF_CONFIG_SOURCE=xml:${GCONF_CONFIG_OPTIONS}:%D/${GCONF_CONFIG_DIRECTORY} HOME=${WRKDIR} gconftool-2 --makefile-install-rule %D/etc/gconf/schemas/$${i} > /dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
	done
.  endif

.  if defined(GLIB_SCHEMAS)
PLIST_FILES+=	${GLIB_SCHEMAS:C,^,share/glib-2.0/schemas/,}
.  endif

.  if defined(INSTALLS_OMF)
_USES_install+=	690:gnome-post-omf
gnome-post-omf:
	@for i in `${GREP} "\.omf$$" ${TMPPLIST}`; do \
		${ECHO_CMD} "@postexec scrollkeeper-install -q %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
		${ECHO_CMD} "@postunexec scrollkeeper-uninstall -q %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
	done
.  endif

.endif
# End of use part.
