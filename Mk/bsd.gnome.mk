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
Gnome_Include_MAINTAINER=	gnome@FreeBSD.org

# This section keeps tests for optional software.  These work off four
# types of of variables.  WANT_, WITH_, HAVE_ and USE_.  The logic of
# this is that a port can WANT support for a package, a user specifies
# if they want ports compiles WITH certain features.  This section tests
# if we HAVE these features, and the port is then free to USE them.

# The logic of this section is like this:
#
# .if defined(WANT_FOO)
#   .if defined(WITH_FOO)
#     HAVE_FOO=yes
#   .elif defined(WITHOUT_FOO)
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
#	- Only set by the user, indicates that they always want
#	  this setting.
# WITHOUT_GLIB, WITHOUT_GTK, WITHOUT_ESOUND, WITHOUT_IMLIB, WITHOUT_GNOME:
#	- Only set by the user, indicates that they never want
#	  this setting.
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
#	yes		- either found GNOME or WITH_GNOME set to yes.

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
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with ESound support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_ESOUND=yes\""
	@${ECHO_MSG}
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
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with GLib support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_GLIB=yes\""
	@${ECHO_MSG}
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
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with GTK+ support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_GTK=yes\""
	@${ECHO_MSG}
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
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Imlib support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_IMLIB=yes\""
	@${ECHO_MSG}
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
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with GNOME support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_GNOME=yes\""
	@${ECHO_MSG}
.endif
.endif
.endif

.endif
# End of optional part.

.if defined(_POSTMKINCLUDED)
# This section contains the USE_ definitions.  These also pass any HAVE_
# options through to the build process so that ports can use them for
# conditional building of components.  Also, if optional support has been
# requested, add a packagename suffix, to indicate the change in the port's
# behaviour.

# USE_ESOUND	- Says that the port uses ESound.
# USE_GLIB		- Says that the port uses the GLib package.
# USE_GTK		- Says that the port uses the GTK+ toolkit.
# USE_IMLIB		- Says that the port uses the Imlib library.
# USE_GNOMELIBS	- Says that the port uses the GNOME libraries.
# USE_GNOMECTRL	- Says that the port uses the GNOME control center.
# USE_GNOME		- Says that the port uses the GNOME desktop environment.

# These are the only "entry points" into the GNOME distribution that will
# be supported.  If you need to use a port that is (say) part of
# the controlcenter metaport, then simply request USE_GNOMECTRL=YES.
#
# Any explicit depends on any of the ports that make up the x11/gnome
# metaport will be periodically eradicated by marking the port BROKEN.
# Please use the guidelines above to help everybody maintain a cohesive
# FreeBSD/GNOME environment.
#
# Unless you're experienced with the GNOME system, we highly recommend
# simply using USE_GNOME=yes if you have GNOME related ports you wish
# to commit.  This will certainly be a *guaranteed* interface that won't
# be broken without significant warning.  Practically all of your target
# audience will already have the x11/gnome metaport installed, so there
# will be minimal inconvenience in terms of excessive downloads.
#
# Ports using GNOME should also have USE_X_PREFIX defined.
# (Perhaps we should add it??  XXX: aDe)
 
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

# Ports which optionally depend on GNOME can add '--datadir=${PREFIX}/share'
# to CONFIGURE_ARGS before including <bsd.port.post.mk> if they do not wish
# to install their data files in /usr/X11R6/share/gnome.  Please be aware
# that you will need to make non standard patches to get the rest of the
# files into the correct places.  Specifically, the help files and pixmaps
# must still go into /usr/X11R6/share/gnome/help and
# /usr/X11R6/share/gnome/pixmaps respectively.  %%DATADIR%% will still be
# defined for you to use.

.if defined(USE_GNOMELIBS)
CONFIGURE_ARGS+=--with-gnome=${PREFIX}
.if ${CONFIGURE_ARGS:S/--localstatedir=//} == ${CONFIGURE_ARGS:S/  / /g}
CONFIGURE_ARGS+=--localstatedir=${PREFIX}/share/gnome
.endif
.if ${CONFIGURE_ARGS:S/--datadir=//} == ${CONFIGURE_ARGS:S/  / /g}
CONFIGURE_ARGS+=--datadir=${PREFIX}/share/gnome
.endif
LIB_DEPENDS+=	gnome.5:${PORTSDIR}/x11/gnomelibs
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
LIB_DEPENDS+=	capplet.5:${PORTSDIR}/sysutils/gnomecontrolcenter
.endif
.if defined(USE_GNOME)
LIB_DEPENDS+=	panel_applet.5:${PORTSDIR}/x11/gnomecore
.endif
.if defined(WANT_GNOME) && !defined(HAVE_GNOME)
PLIST_SUB+=		GNOME:="@comment " NOGNOME:="" DATADIR="share"
.endif

# Start of GNOME_VALIDATE_DEPS_CHAIN part.
.if defined(USE_GNOMELIBS) && defined(GNOME_VALIDATE_DEPS_CHAIN)
BUILD_DEPENDS+=	python:${PORTSDIR}/lang/python
CHKDPCHN_CMD?=	${PORTSDIR}/Tools/scripts/chkdepschain.py
CHKDPCHN_CACHE=	.chkdpchn.cache.${PKGNAME}

.if !target(pre-extract)
pre-extract::
	@${ECHO_MSG} "===>  Validating build-time dependency chain for ${PKGNAME}"
	@${MKDIR} ${WRKDIR}
	@${CHKDPCHN_CMD} -b -s ${WRKDIR}/${CHKDPCHN_CACHE}
.endif

.if !target(pre-install)
pre-install::
	@${ECHO_MSG} "===>  Validating run-time dependency chain for ${PKGNAME}"
	@${CHKDPCHN_CMD} -r -L ${WRKDIR}/${CHKDPCHN_CACHE}
.endif
.endif
# End of GNOME_VALIDATE_DEPS_CHAIN part.

.endif
# End of use part.
