#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED)

# Please make sure all changes to this file are past through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Gnome_Include_MAINTAINER=	gnome@FreeBSD.org

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

_USE_GNOME_ALL=	gnomehack gnomeprefix gnomehier gnomeaudio esound libghttp \
		glib12 gtk12 libxml gdkpixbuf imlib orbit gnomelibs \
		gnomecanvas oaf gnomemimedata gconf gnomevfs libcapplet \
		gnomeprint bonobo libgda gnomedb libglade gal glibwww gtkhtml \
		libpanel

gnomehack_PRE_PATCH=	${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
				's|[(]GNOME_datadir[)]/gnome/|(datadir)/|g ; \
				 s|[(]GNOME_datadir[)]/locale|(prefix)/share/locale|g ; \
				 s|[(]datadir[)]/locale|(prefix)/share/locale|g ; \
				 s|[(]gnomedatadir[)]/gnome|(gnomedatadir)|g ; \
				 s|[(]datadir[)]/aclocal|(prefix)/share/aclocal|g ; \
				 s|[(]datadir[)]/gnome/|(datadir)/|g ; \
				 s|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
				 s|[(]libdir[)]/bonobo/servers|(prefix)/libdata/bonobo/servers|g'

gnomehier_RUN_DEPENDS=	${X11BASE}/share/gnome/.keep_me:${PORTSDIR}/misc/gnomehier
gnomehier_DETECT=	${X11BASE}/share/gnome/.keep_me

GNOME_HTML_DIR?=	${PREFIX}/share/doc
gnomeprefix_CONFIGURE_ENV=GTKDOC="false"
gnomeprefix_CONFIGURE_ARGS=--localstatedir=${PREFIX}/share/gnome \
			   --datadir=${PREFIX}/share/gnome \
			   --with-html-dir=${GNOME_HTML_DIR} \
			   --disable-gtk-doc \
			   --with-gconf-source=xml::${PREFIX}/etc/gconf/gconf.xml.defaults
gnomeprefix_USE_GNOME_IMPL=gnomehier

gnomeaudio_RUN_DEPENDS=	${X11BASE}/share/gnome/sounds/login.wav:${PORTSDIR}/audio/gnomeaudio
gnomeaudio_DETECT=	${X11BASE}/share/gnome/sounds/login.wav

ESD_CONFIG?=		${LOCALBASE}/bin/esd-config
esound_LIB_DEPENDS=	esd.2:${PORTSDIR}/audio/esound
esound_CONFIGURE_ENV=	ESD_CONFIG="${ESD_CONFIG}"
esound_MAKE_ENV=	ESD_CONFIG="${ESD_CONFIG}"
esound_DETECT=		${ESD_CONFIG}

libghttp_LIB_DEPENDS=	ghttp.1:${PORTSDIR}/www/libghttp
libghttp_DETECT=	${LOCALBASE}/etc/ghttpConf.sh

GLIB_CONFIG?=		${LOCALBASE}/bin/glib12-config
glib12_LIB_DEPENDS=	glib12.3:${PORTSDIR}/devel/glib12
glib12_CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}"
glib12_MAKE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}"
glib12_DETECT=		${GLIB_CONFIG}

GTK_CONFIG?=		${X11BASE}/bin/gtk12-config
gtk12_LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
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

gnomemimedata_BUILD_DEPENDS=${X11BASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc:${PORTSDIR}/misc/gnomemimedata
gnomemimedata_RUN_DEPENDS=${X11BASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc:${PORTSDIR}/misc/gnomemimedata
gnomemimedata_DETECT=	${X11BASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc
gnomemimedata_USE_GNOME_IMPL=gnomehier

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

gal_LIB_DEPENDS=	gal.21:${PORTSDIR}/x11-toolkits/gal
gal_DETECT=		${X11BASE}/etc/galConf.sh
gal_USE_GNOME_IMPL=	libglade

glibwww_LIB_DEPENDS=	glibwww.1:${PORTSDIR}/www/glibwww
glibwww_DETECT=		${X11BASE}/etc/glibwwwConf.sh
glibwww_USE_GNOME_IMPL=	gnomelibs

gtkhtml_LIB_DEPENDS=	gtkhtml-1.1.3:${PORTSDIR}/www/gtkhtml
gtkhtml_DETECT=		${X11BASE}/etc/gtkhtmlConf.sh
gtkhtml_USE_GNOME_IMPL=	glibwww gal libghttp libcapplet

libpanel_LIB_DEPENDS=	panel_applet.5:${PORTSDIR}/x11/libpanel
libpanel_DETECT=	${X11BASE}/etc/appletsConf.sh
libpanel_USE_GNOME_IMPL=gnomelibs

# This section keeps tests for optional software.  These work off four
# types of of variables.  WANT_GNOME, WITH_GNOME, HAVE_GNOME and USE_GNOME.
# The logic of this is that a port can WANT support for a package, a user
# specifies if they want ports compiles WITH certain features.  This section
# tests if we HAVE these features, and the port is then free to USE them.

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
# Although it apears a little more convoluted in the tests.

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

_USE_GNOME_SAVED:=${USE_GNOME}
HAVE_GNOME?=
.if (defined(WANT_GNOME) && !defined(WITHOUT_GNOME))
. for component in ${_USE_GNOME_ALL}
.    if exists(${${component}_DETECT})
HAVE_GNOME+=	${component}
.    elif defined(WITH_GNOME)
.      if ${WITH_GNOME}=="yes" || ${WITH_GNOME:M${component}}!="" || \
         ${WITH_GNOME}=="1"
HAVE_GNOME+=	${component}
.      endif
.    endif
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

.if defined(_POSTMKINCLUDED)

.if defined(USE_GNOME)
# First of all expand all USE_GNOME_IMPL recursively
. for component in ${_USE_GNOME_ALL}
.  for subcomponent in ${${component}_USE_GNOME_IMPL}
${component}_USE_GNOME_IMPL+=${${subcomponent}_USE_GNOME_IMPL}
.  endfor
. endfor

# Then use already expanded USE_GNOME_IMPL to expand USE_GNOME
. for component in ${USE_GNOME}
.  if ${_USE_GNOME_ALL:M${component}}==""
BROKEN=	"Unknown component ${component}"
.  endif
_USE_GNOME+=	${${component}_USE_GNOME_IMPL} ${component}
. endfor

# Then traverse through all possible components, check which of them
# exist in ${_USE_GNOME} and set variables accordingly
. for component in ${_USE_GNOME_ALL}
.  if ${_USE_GNOME:S/${component}//}!=${_USE_GNOME:S/  / /g}
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
LIB_DEPENDS+=	${${component}_LIB_DEPENDS}
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}

CONFIGURE_ARGS+=${${component}_CONFIGURE_ARGS}
CONFIGURE_ENV+=	${${component}_CONFIGURE_ENV}
MAKE_ENV+=	${${component}_MAKE_ENV}

.   if defined(${component}_PRE_PATCH)
GNOME_PRE_PATCH+=	${${component}_PRE_PATCH}
.   endif

.  endif
. endfor
.endif

.if defined(GNOME_PRE_PATCH) && !target(pre-patch)
USE_REINPLACE=	yes

pre-patch:
	@${GNOME_PRE_PATCH}
.endif

.if defined(WANT_GNOME)
USE_GNOME?=
.if ${_USE_GNOME_SAVED}==${USE_GNOME}
PLIST_SUB+=	GNOME:="@comment " NOGNOME:=""
.else
PLIST_SUB+=	GNOME:="" NOGNOME:="@comment "
.endif
.endif

.endif
# End of use part.
