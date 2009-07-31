# ex:ts=8
# Ports collection makefile for:	classpath
# Date created:			Sep 1, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	classpath
PORTVERSION=	0.97.2
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	A GNU project to create a free Java class library

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_XORG=	x11 ice xtst xaw xproto xext
USE_LDCONFIG=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ARGS=	--enable-jni --disable-alsa --disable-dssi --disable-plugin
USE_GMAKE=	yes

MAN1=		gappletviewer.1 \
		gjar.1 \
		gjarsigner.1 \
		gjavah.1 \
		gcjh.1 \
		gkeytool.1 \
		gnative2ascii.1 \
		gorbd.1 \
		grmid.1 \
		grmiregistry.1 \
		gserialver.1 \
		gtnameserv.1

INFO=		cp-hacking cp-tools cp-vmintegration

CONFLICTS=	sablevm-classpath-*

OPTIONS=	GCONF "Use GConf based preferences backend" OFF \
		GTK2 "Enable Gtk+ AWT peer" ON \
		CAIRO "Use Gtk+ Cairo based Graphics2D" OFF \
		QT4 "Enable Qt AWT peer" OFF

.include <bsd.port.pre.mk>

.if defined(WITH_GCONF)
USE_GNOME+=		gconf2
CONFIGURE_ARGS+=	--enable-default-preferences-peer=gconf
PLIST_SUB+=		GCONF=""
.else
CONFIGURE_ARGS+=	--enable-default-preferences-peer=file --disable-gconf-peer
PLIST_SUB+=		GCONF="@comment "
.endif

.if defined(WITHOUT_GTK2)
CONFIGURE_ARGS+=	--disable-gtk-peer
PLIST_SUB+=		GTK2="@comment "
.if defined(WITH_CAIRO)
IGNORE=you need to enable the Gtk+ AWT peer in order to use Cairo based Graphics2D.
.endif
.else
USE_GNOME+=		gtk20
PLIST_SUB+=		GTK2=""
.if defined(WITH_CAIRO)
CONFIGURE_ARGS+=	--enable-gtk-cairo
.endif
.endif

.if defined(WITH_QT4)
CONFIGURE_ARGS+=	--enable-qt-peer
.if defined(WITHOUT_GTK2)
CONFIGURE_ARGS+=	--enable-default-toolkit=gnu.java.awt.peer.qt.QtToolkit
.endif
CONFIGURE_ENV+=		MOC="${LOCALBASE}/bin/moc-qt4"
USE_QT_VER=		4
QT_COMPONENTS=		moc_build corelib gui
PLIST_SUB+=		QT4=""
.else
PLIST_SUB+=		QT4="@comment "
.endif

.include <bsd.port.post.mk>
