# Created by: Björn König <bkoenig@alpha-tierchen.de>
# $FreeBSD$

PORTNAME=	sablevm-classpath
PORTVERSION=	1.13
PORTREVISION=	11
CATEGORIES=	java devel
MASTER_SITES=	SF/sablevm/sablevm/${PORTVERSION}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Classpath of SableVM

LICENSE=	GPLv2

BUILD_DEPENDS=	jikes:java/jikes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pkgconfig
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_XORG=	x11 ice xtst sm

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

CONFIGURE_ARGS=	--disable-alsa --disable-dssi
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CAIRO GTK2 ZIP
OPTIONS_DEFAULT=GTK2 ZIP
CAIRO_DESC=	Use Cairo based Graphics2D
GTK2_DESC=	Enable Gtk+ AWT peer
ZIP_DESC=	Compress class library

.include <bsd.port.options.mk>

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

.if ${PORT_OPTIONS:MZIP}
CONFIGURE_ARGS+=	--with-compressed-classes=zip
BUILD_DEPENDS+=		zip:archivers/zip
PLIST_SUB+=		WITHOUT_ZIP="@comment " WITH_ZIP=""
.else
CONFIGURE_ARGS+=	--with-compressed-classes=no
PLIST_SUB+=		WITHOUT_ZIP="" WITH_ZIP="@comment "
.endif

post-patch:
	@${CP} -f ${WRKSRC}/resource/java/security/classpath.security \
	    ${WRKSRC}/resource/java/security/SableVM.security

.include <bsd.port.mk>
