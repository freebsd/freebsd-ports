# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	oxim
PORTVERSION=	1.2.2
PORTREVISION=	6
CATEGORIES=	chinese textproc
MASTER_SITES=	ftp://ftp.opendesktop.org.tw/odp/OXIM/Source/ \
		ftp://140.111.128.66/odp/OXIM/Source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open X Input Method server

LIB_DEPENDS=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/share/fonts/TrueType/fireflysung.ttf:${PORTSDIR}/chinese/fireflyttf

OPTIONS_DEFINE=	GTK2 CHEWING UNICODE
OPTIONS_DEFAULT=	GTK2 CHEWING UNICODE
OPTIONS_SUB=	yes
GTK2_DESC=	 GTK2 input method module
CHEWING_DESC=	 Chewing input module
UNICODE_DESC=	 Unicode input module

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
USES=		iconv libtool pkgconfig
USE_XORG=	x11 xft xpm xtst xext
WANT_GNOME=	yes

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB} -lfontconfig -lXext
CONFIGURE_ARGS+=--disable-bimsphone-module \
		--disable-static \
		--with-conf-dir=${PREFIX}/etc/${PORTNAME} \
		--enable-setup-tool=no
# oxim requires qinputcontextplugin.h which only exists in Debian package
CONFIGURE_ARGS+=--disable-qt-immodule

GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_ENABLE=	gtk-immodule

# make sure we have the required libchewing
CHEWING_BUILD_DEPENDS=	zh-libchewing>=0.3.2:${PORTSDIR}/chinese/libchewing
CHEWING_RUN_DEPENDS=	${CHEWING_BUILD_DEPENDS}
CHEWING_CONFIGURE_ENABLE=	chewing-module
CHEWING_CONFIGURE_ENV=	CHEWING_CFLAGS=-I${LOCALBASE}/include

UNICODE_CONFIGURE_ENABLE=	unicode-module

# TODO WITHOUT_NLS knob
#.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
LDFLAGS+=	-lintl
#.else
#CONFIGURE_ARGS+=--disable-nls
#PLIST_SUB+=	NLS="@comment "
#.endif

post-patch:
	${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' \
			${WRKSRC}/src/gtk-immodule/gtkintl.h

.include <bsd.port.mk>
