# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	oxim
PORTVERSION=	1.2.2
PORTREVISION=	4
CATEGORIES=	chinese textproc
MASTER_SITES=	ftp://ftp.opendesktop.org.tw/odp/OXIM/Source/ \
		ftp://140.111.128.66/odp/OXIM/Source/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Open X Input Method server

RUN_DEPENDS=	${LOCALBASE}/share/fonts/TrueType/fireflysung.ttf:${PORTSDIR}/chinese/fireflyttf

OPTIONS_DEFINE=	GTK2 CHEWING UNICODE
OPTIONS_DEFAULT=	GTK2 CHEWING UNICODE
GTK2_DESC=	 GTK2 input method module
CHEWING_DESC=	 Chewing input module
UNICODE_DESC=	 Unicode input module

USES=		iconv pkgconfig
USE_XORG=	x11 xft xpm xtst
WANT_GNOME=	yes

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=--disable-bimsphone-module \
		--disable-static \
		--with-conf-dir=${PREFIX}/etc/${PORTNAME} \
		--enable-setup-tool=no
# oxim requires qinputcontextplugin.h which only exists in Debian package
CONFIGURE_ARGS+=--disable-qt-immodule

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--enable-gtk-immodule
PLIST_SUB+=	GTK2=""
.else
CONFIGURE_ARGS+=	--disable-gtk-immodule
PLIST_SUB+=	GTK2="@comment "
.endif

.if ${PORT_OPTIONS:MCHEWING}
# make sure we have the required libchewing
BUILD_DEPENDS+=	zh-libchewing>=0.3.2:${PORTSDIR}/chinese/libchewing
RUN_DEPENDS+=	zh-libchewing>=0.3.2:${PORTSDIR}/chinese/libchewing

CONFIGURE_ARGS+=	--enable-chewing-module
CONFIGURE_ENV+=	CHEWING_CFLAGS=-I${LOCALBASE}/include
PLIST_SUB+=	CHEWING=""
.else
CONFIGURE_ARGS+=	--disable-chewing-module
PLIST_SUB+=	CHEWING="@comment "
.endif

.if ${PORT_OPTIONS:MUNICODE}
CONFIGURE_ARGS+=	--enable-unicode-module
PLIST_SUB+=	UNICODE=""
.else
CONFIGURE_ARGS+=	--disable-unicode-module
PLIST_SUB+=	UNICODE="@comment "
.endif

# TODO WITHOUT_NLS knob
#.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
LDFLAGS+=	-lintl
PLIST_SUB+=	NLS=""
#.else
#CONFIGURE_ARGS+=--disable-nls
#PLIST_SUB+=	NLS="@comment "
#.endif

post-patch:
	${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' \
			${WRKSRC}/src/gtk-immodule/gtkintl.h

.include <bsd.port.mk>
