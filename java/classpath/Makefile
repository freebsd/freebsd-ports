# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	classpath
PORTVERSION=	0.99
PORTREVISION=	4
CATEGORIES=	java devel
MASTER_SITES=	GNU \
		SAVANNAH
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	java@FreeBSD.org
COMMENT=	GNU project to create a free Java class library

LICENSE=	GPLv2

BROKEN_aarch64=		fails to configure: error: The jar tool /usr/local/bin/gjar5 was not found
BROKEN_armv6=		fails to configure: error: The jar tool /usr/local/bin/gjar5 was not found
BROKEN_powerpc64=	fails to configure: error: The jar tool /usr/local/bin/gjar5 was not found

GNU_CONFIGURE=	yes
USES=		gmake iconv libtool perl5 pkgconfig
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XORG=	x11 ice xtst xaw xproto xext
WANT_GNOME=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--enable-jni --disable-alsa --disable-dssi --disable-plugin
CONFIGURE_ARGS+=--with-jar=${JAR}
CONFIGURE_ENV=	JAVA="${JAVA}" JAVAC="${JAVAC}"
CONFIGURE_ENV+=	JAVACFLAGS="${JAVACFLAGS}"
MAKE_ENV+=	JAVACFLAGS="${JAVACFLAGS}"

INFO=		cp-hacking cp-tools cp-vmintegration

CONFLICTS=	sablevm-classpath-1.13 sablevm-classpath-1.13_[1-9]

OPTIONS_DEFINE=	CAIRO ECJ GCONF GJDOC GMP GTK2 QT4 EXAMPLES
OPTIONS_DEFAULT=GMP GJDOC GTK2
CAIRO_DESC=	Use Gtk+ Cairo based Graphics2D
ECJ_DESC=	Embed ECJ as com.sun.tools.javac
GJDOC_DESC=	Build javadoc replacement
GMP_DESC=	Enable native java.math.BigInteger
GTK2_DESC=	Enable Gtk+ AWT peer
QT4_DESC=	Enable Qt AWT peer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MECJ}
MASTER_SITES+=		ECLIPSE/R-${ECJ_VERSION}-${ECJ_DROPDATE}:ecj
DISTFILES+=		${ECJ_JAR}:ecj
ECJ_VERSION=		3.8.1
ECJ_DROPDATE=		201209141540
ECJ_JAR=		ecj-${ECJ_VERSION}.jar
CONFIGURE_ARGS+=	--with-ecj-jar=${DISTDIR}/${ECJ_JAR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
EXAMPLESDIR=		${DATADIR}/examples
.else
CONFIGURE_ARGS+=	--disable-examples
.endif

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=		gconf2
CONFIGURE_ARGS+=	--enable-default-preferences-peer=gconf
PLIST_SUB+=		GCONF=""
.else
CONFIGURE_ARGS+=	--enable-default-preferences-peer=file \
			--disable-gconf-peer
PLIST_SUB+=		GCONF="@comment "
.endif

.if ${PORT_OPTIONS:MGJDOC}
ANTLR_JAR=		antlr-2.7.7.jar
MASTER_SITES+=		http://www.antlr2.org/download/:antlr
DISTFILES+=		${ANTLR_JAR}:antlr
CONFIGURE_ARGS+=	--with-antlr-jar=${DISTDIR}/${ANTLR_JAR}
PLIST_SUB+=		GJDOC=""
.else
CONFIGURE_ARGS+=	--disable-gjdoc
PLIST_SUB+=		GJDOC="@comment "
.endif

.if ${PORT_OPTIONS:MGMP}
LIB_DEPENDS+=		libgmp.so:math/gmp
CONFIGURE_ARGS+=	--with-gmp=${LOCALBASE}
PLIST_SUB+=		GMP=""
.else
CONFIGURE_ARGS+=	--disable-gmp
PLIST_SUB+=		GMP="@comment "
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

.if !defined(WITH_GCJ) && (${ARCH} == "amd64" || ${ARCH} == "i386")
BUILD_DEPENDS+=		${LOCALBASE}/bootstrap-openjdk/bin/javac:java/bootstrap-openjdk
JAR?=			${LOCALBASE}/bootstrap-openjdk/bin/jar
JAVA?=			${LOCALBASE}/bootstrap-openjdk/bin/java
JAVAC?=			${LOCALBASE}/bootstrap-openjdk/bin/javac
.else
USE_BINUTILS=		yes
USE_GCC=		yes
GCC_SUFX=		${_USE_GCC:S/.//}
JAR?=			${LOCALBASE}/bin/gjar${GCC_SUFX}
JAVA?=			${LOCALBASE}/bin/gij${GCC_SUFX}
JAVAC?=			${LOCALBASE}/bin/gcj${GCC_SUFX}
JAVACFLAGS?=		-C
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@JAVA@|$${JAVACMD:-java}|g' \
	    ${WRKSRC}/tools/g*.in

.include <bsd.port.mk>
