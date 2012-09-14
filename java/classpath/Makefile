# ex:ts=8
# Ports collection makefile for:	classpath
# Date created:			Sep 1, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	classpath
PORTVERSION=	0.99
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	java@FreeBSD.org
COMMENT=	A GNU project to create a free Java class library

LICENSE=	GPLv2

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		${JAVALIBDIR}/antlr.jar:${PORTSDIR}/devel/antlr

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_LDCONFIG=	yes
USE_PERL5_BUILD=yes
USE_PKGCONFIG=	build
USE_XORG=	x11 ice xtst xaw xproto xext
WANT_GNOME=	yes

CXXFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-jni --disable-alsa --disable-dssi --disable-plugin
CONFIGURE_ARGS+=--with-antlr-jar=${JAVALIBDIR}/antlr.jar
CONFIGURE_ARGS+=--with-jar=${JAR}

MAN1=		gappletviewer.1 \
		gcjh.1 \
		gjar.1 \
		gjarsigner.1 \
		gjavah.1 \
		gjdoc.1 \
		gkeytool.1 \
		gnative2ascii.1 \
		gorbd.1 \
		grmid.1 \
		grmiregistry.1 \
		gserialver.1 \
		gtnameserv.1

INFO=		cp-hacking cp-tools cp-vmintegration

CONFLICTS=	sablevm-classpath-*

OPTIONS_DEFINE=	CAIRO GCONF GTK2 QT4
OPTIONS_DEFAULT=GTK2
CAIRO_DESC=	Use Gtk+ Cairo based Graphics2D
GTK2_DESC=	Enable Gtk+ AWT peer
QT4_DESC=	Enable Qt AWT peer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=		gconf2
CONFIGURE_ARGS+=	--enable-default-preferences-peer=gconf
PLIST_SUB+=		GCONF=""
.else
CONFIGURE_ARGS+=	--enable-default-preferences-peer=file --disable-gconf-peer
PLIST_SUB+=		GCONF="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=		gtk20
PLIST_SUB+=		GTK2=""
.if ${PORT_OPTIONS:MCAIRO}
CONFIGURE_ARGS+=	--enable-gtk-cairo
.endif
.else
CONFIGURE_ARGS+=	--disable-gtk-peer
PLIST_SUB+=		GTK2="@comment "
.if ${PORT_OPTIONS:MCAIRO}
IGNORE=you need to enable the Gtk+ AWT peer in order to use Cairo based Graphics2D.
.endif
.endif

.if ${PORT_OPTIONS:MQT4}
CONFIGURE_ARGS+=	--enable-qt-peer
.if empty(PORT_OPTIONS:MGTK2)
CONFIGURE_ARGS+=	--enable-default-toolkit=gnu.java.awt.peer.qt.QtToolkit
.endif
CONFIGURE_ENV+=		MOC="${LOCALBASE}/bin/moc-qt4"
USE_QT4=		moc_build corelib gui
PLIST_SUB+=		QT4=""
.else
PLIST_SUB+=		QT4="@comment "
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
EXAMPLESDIR=		${DATADIR}/examples
.else
CONFIGURE_ARGS+=	--disable-examples
.endif

.include <bsd.port.mk>
