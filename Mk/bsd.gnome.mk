#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#	$NetBSD: $
#
# Please view me with 4 column tabs!

.if !defined(_POSTMKINCLUDED)

# Please make sure all changes to this file are past through the maintainer. 
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Gnome_Include_MAINTAINER=	reg@FreeBSD.org

# This section keeps tests for optional software.  These work off four
# types of of variables.  WANT_, WITH_, HAVE_ and USE_.  The logic of
# this is that a port can WANT support for a package, a user specifies
# if they want ports compiles WITH certain features.  This section tests
# if we HAVE these features, and the port is then free to USE them.

# The logic of this section is like this:
#
# .if defined(WANT_FOO)
#   .if ${WITH_FOO} == "yes"
#     HAVE_FOO=yes
#   .elif ${WITH_FOO} == "no"
#     .undef HAVE_FOO
#   .elif (if FOO installed)
#     HAVE_FOO=yes
#   .else
#     Print option message
#   .endif
# .endif
#
# Although it apears a little more convoluted in the tests.

# Ports can make use of this like so:
#
# WANT_FOO=		yes
#
# .include <bsd.port.pre.mk>
#
# .if defined(HAVE_FOO)
# ... Do some things ...
# USE_FOO=		yes
# .else
# ... Do some other things ...
# .endif
 
# The following defines are for the various levels of libraries in the
# GLib/GTK+/GNOME group of software. There are the following options:
#
# WITH_GLIB, WITH_GTK, WITH_ESOUND, WITH_IMLIB, WITH_GNOME:
#	yes		- Only set by the user, indicates that they always want
#			  this setting.
#	no		- Only set by the user, indicates that they never want
#			  this setting.
#
# The following variables might be set:
#
# HAVE_GLIB, HAVE_GTK:
#	yes		- found GLib/GTK+ 1.2.x or WITH_GLIB/WITH_GTK set to yes.
# HAVE_ESOUND:
#	yes		- either found ESound or WITH_ESOUND set to yes.
# HAVE_IMLIB:
#	yes		- either found Imlib or WITH_IMLIB set to yes.
# HAVE_GNOME:
#	yes		- either found Gnome or WITH_GNOME set to yes.

.if defined(PACKAGE_BUILDING) && !defined(WITH_ALL)
WITHOUT_ALL=	yes
.endif

.if defined(WANT_ESOUND) && !defined(WITHOUT_ESOUND) && !defined(WITHOUT_ALL)
.if defined(HAVE_ESOUND)
.undef HAVE_ESOUND
.endif
.if defined(WITH_ESOUND) || defined(WITH_ALL)
HAVE_ESOUND=	yes
.else
ESD_CONFIG?=	${LOCALBASE}/bin/esd-config
.if exists(${ESD_CONFIG})
HAVE_ESOUND=	yes
.else
GNOME_OPTION_MSG+= "" "If you want to compile with ESound support," \
			 "hit Ctrl-C right now and use \"make WITH_ESOUND=yes\"" ""
.endif
.endif
.endif

.if defined(WANT_GLIB) && !defined(WITHOUT_GLIB) && !defined(WITHOUT_ALL)
.if defined(HAVE_GLIB)
.undef HAVE_GLIB
.endif
.if defined(WITH_GLIB) || defined(WITH_ALL)
HAVE_GLIB=	yes
.else
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
.if exists(${GLIB_CONFIG})
HAVE_GLIB=	yes
.else
GNOME_OPTION_MSG+= "" "If you want to compile with GLib support," \
			 "hit Ctrl-C right now and use \"make WITH_GLIB=yes\"" ""
.endif
.endif
.endif

.if defined(WANT_GTK) && !defined(WITHOUT_GTK) && !defined(WITHOUT_ALL)
.if defined(HAVE_GTK)
.undef HAVE_GTK
.endif
.if defined(WITH_GTK) || defined(WITH_ALL)
HAVE_GTK=	yes
.else
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
.if exists(${GTK_CONFIG})
HAVE_GTK=	yes
.else
GNOME_OPTION_MSG+= "" "If you want to compile with GTK+ support," \
			 "hit Ctrl-C right now and use \"make WITH_GTK=yes\"" ""
.endif
.endif
.endif

.if defined(WANT_IMLIB) && !defined(WITHOUT_IMLIB) && !defined(WITHOUT_ALL)
.if defined(HAVE_IMLIB)
.undef HAVE_IMLIB
.endif
.if defined(WITH_IMLIB) || defined(WITH_ALL)
HAVE_IMLIB=	yes
.else
IMLIB_CONFIG?=	${X11BASE}/bin/imlib-config
.if exists(${IMLIB_CONFIG})
HAVE_IMLIB=	yes
.else
GNOME_OPTION_MSG+= "" "If you want to compile with Imlib support," \
			 "hit Ctrl-C right now and use \"make WITH_IMLIB=yes\"" ""
.endif
.endif
.endif

.if defined(WANT_GNOME) && !defined(WITHOUT_GNOME) && !defined(WITHOUT_ALL)
.if defined(HAVE_GNOME)
.undef HAVE_GNOME
.endif
.if defined(WITH_GNOME) || defined (WITH_ALL)
HAVE_GNOME=	yes
.else
GNOME_CONFIG?=	${X11BASE}/bin/gnome-config
.if exists(${GNOME_CONFIG})
HAVE_GNOME=	yes
.else
GNOME_OPTION_MSG+= "" "If you want to compile with GNOME support," \
			 "hit Ctrl-C right now and use \"make WITH_GNOME=yes\"" ""
.endif
.endif
.endif

.endif
# End of optional part.

.if defined(_POSTMKINCLUDED)
# This section includes the USE_* definitions for bsd.port.mk, to allow them to
# be updated outside of bsd.port.mk.

# USE_ESOUND	- Says that the port uses ESound.
# USE_GLIB		- Says that the port uses the GLib package.
# USE_GTK		- Says that the port uses the GTK+ toolkit.
# USE_IMLIB		- Says that the port uses the Imlib library.
# USE_GNOMELIBS	- Says that the port uses the GNOME libraries.
# USE_GNOMECTRL	- Says that the port uses the GNOME control center.
# USE_GNOME		- Says that the port uses the GNOME desktop environment.
 
.if defined(USE_GNOME)
USE_GNOMECTRL=	yes
.endif
.if defined(USE_GNOMECTRL)
USE_GNOMELIBS=	yes
.endif
.if defined(USE_GNOMELIBS)
USE_IMLIB=	yes
USE_ESOUND=	yes
.endif
.if defined(USE_IMLIB)
USE_GTK=	yes
.endif
.if defined(USE_GTK)
USE_GLIB=	yes
.endif

.if defined(USE_ESOUND)
LIB_DEPENDS+=	esd.2:${PORTSDIR}/audio/esound
ESD_CONFIG?=	${LOCALBASE}/bin/esd-config
CONFIGURE_ENV+=	ESD_CONFIG="${ESD_CONFIG}"
MAKE_ENV+=		ESD_CONFIG="${ESD_CONFIG}"
.if defined(HAVE_ESOUND)
PKGNAMESUFFIX=	-esound
CONFIGURE_ENV+=	HAVE_ESOUND=${HAVE_ESOUND}
MAKE_ENV+=		HAVE_ESOUND=${HAVE_ESOUND}
.endif
.endif

.if defined(USE_GLIB)
LIB_DEPENDS+=	glib12.3:${PORTSDIR}/devel/glib12
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
CONFIGURE_ENV+=	GLIB_CONFIG="${GLIB_CONFIG}"
MAKE_ENV+=		GLIB_CONFIG="${GLIB_CONFIG}"
.if defined(HAVE_GLIB)
PKGNAMESUFFIX=	-glib
CONFIGURE_ENV+=	HAVE_GLIB=${HAVE_GLIB}
MAKE_ENV+=		HAVE_GLIB=${HAVE_GLIB}
.endif
.endif

.if defined(USE_GTK)
LIB_DEPENDS+=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
CONFIGURE_ENV+=	GTK_CONFIG="${GTK_CONFIG}"
MAKE_ENV+=		GTK_CONFIG="${GTK_CONFIG}"
.if defined(HAVE_GTK)
PKGNAMESUFFIX=	-gtk
CONFIGURE_ENV+=	HAVE_GTK=${HAVE_GTK}
MAKE_ENV+=		HAVE_GTK=${HAVE_GTK}
.endif
.endif

.if defined(USE_IMLIB)
LIB_DEPENDS+=	Imlib.5:${PORTSDIR}/graphics/imlib
IMLIB_CONFIG?=	${X11BASE}/bin/imlib-config
CONFIGURE_ENV+=	IMLIB_CONFIG="${IMLIB_CONFIG}"
MAKE_ENV+=		IMLIB_CONFIG="${IMLIB_CONFIG}"
.if defined(HAVE_IMLIB)
PKGNAMESUFFIX=	-imlib
CONFIGURE_ENV+=	HAVE_IMLIB=${HAVE_IMLIB}
MAKE_ENV+=		HAVE_IMLIB=${HAVE_IMLIB}
.endif
.endif

.if defined(USE_GNOMELIBS)
CONFIGURE_ARGS+=--localstatedir=${PREFIX}/share/gnome \
				--datadir=${PREFIX}/share/gnome \
				--with-gnome=${PREFIX}
LIB_DEPENDS+=	gnome.4:${PORTSDIR}/x11/gnomelibs
GNOME_CONFIG?=	${X11BASE}/bin/gnome-config
CONFIGURE_ENV+=	GNOME_CONFIG="${GNOME_CONFIG}"
MAKE_ENV+=		GNOME_CONFIG="${GNOME_CONFIG}"
.if defined(HAVE_GNOME)
PKGNAMESUFFIX=	-gnome
CONFIGURE_ENV+=	HAVE_GNOME=${HAVE_GNOME}
MAKE_ENV+=		HAVE_GNOME=${HAVE_GNOME}
PLIST_SUB+=		GNOME:="" NOGNOME:="@comment " DATADIR="share/gnome"
.endif
.endif
.if defined(USE_GNOMECTRL)
LIB_DEPENDS+=	capplet.4:${PORTSDIR}/sysutils/gnomecontrolcenter
.endif
.if defined(USE_GNOME)
LIB_DEPENDS+=	panel_applet.4:${PORTSDIR}/x11/gnomecore
.endif
.if defined(WANT_GNOME) && !defined(HAVE_GNOME)
PLIST_SUB+=		GNOME:="@comment " NOGNOME:="" DATADIR="share"
.endif

.endif
# End of use part.
