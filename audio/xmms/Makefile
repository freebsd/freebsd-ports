# New ports collection makefile for:	xmms
# Date created:			3 July 1999
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	xmms
PORTVERSION=	1.2.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.xmms.org/xmms/1.2.x/ \
		ftp://ftp.uk.xmms.org/xmms/1.2.x/ \
		ftp://ftp.us.xmms.org/xmms/1.2.x/ \
		ftp://ftp.ca.us.xmms.org/xmms/1.2.x/ \
		ftp://ftp.md.us.xmms.org/xmms/1.2.x/ \
		ftp://ftp.nl.xmms.org/xmms/1.2.x/ \
		ftp://ftp.de.xmms.org/xmms/1.2.x/

MAINTAINER=	esk@ira.uka.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		glib12.3:${PORTSDIR}/devel/glib12 \
		xml.5:${PORTSDIR}/textproc/libxml

USE_X_PREFIX=   yes
USE_LIBTOOL=    yes
INSTALLS_SHLIB= yes

.if !defined(WITHOUT_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
HAVE_MIKMOD_OVERRIDE=
PLIST_SUB+=	MIKMODPLUGIN:=""
.else
HAVE_MIKMOD_OVERRIDE=	yes
PLIST_SUB+=	MIKMODPLUGIN:="@comment "
.endif

.if !defined(WITHOUT_ESD)
LIB_DEPENDS+=	esd.2:${PORTSDIR}/audio/esound
HAVE_ESD_OVERRIDE=
PLIST_SUB+=	ESDPLUGIN:=""
.else
HAVE_ESD_OVERRIDE=	yes
PLIST_SUB+=	ESDPLUGIN:="@comment "
.endif

.if defined(WITH_GNOME)
LIB_DEPENDS+=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		panel_applet.4:${PORTSDIR}/x11/gnomecore
CONFIGURE_ARGS+=	--with-gnome
PLIST_SUB+=	GNOME:=""
.else
CONFIGURE_ARGS+=	--without-gnome
PLIST_SUB+=	GNOME:="@comment "
.endif

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

CONFIGURE_ENV+=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		HAVE_ESD_OVERRIDE="${HAVE_ESD_OVERRIDE}" \
		HAVE_MIKMOD_OVERRIDE="${HAVE_MIKMOD_OVERRIDE}"

pre-extract:
.if !defined(WITH_GNOME) || !defined(WITHOUT_ESD) || !defined(WITHOUT_MIKMOD)
	@${ECHO_MSG}
.endif
.if !defined(WITH_GNOME)
	@${ECHO_MSG} "You can add support for GNOME by defining WITH_GNOME."
.endif
.if !defined(WITHOUT_ESD)
	@${ECHO_MSG} "You can disable support for ESD sound daemon by defining WITHOUT_ESD."
.endif
.if !defined(WITHOUT_MIKMOD)
	@${ECHO_MSG} "You can disable support for mikmod by defining WITHOUT_MIKMOD."
.endif
.if !defined(WITH_GNOME) || !defined(WITHOUT_ESD) || !defined(WITHOUT_MIKMOD)
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
