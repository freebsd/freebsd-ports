# New ports collection makefile for:	oxim
# Date created:				Mar 19 2006
# Whom:					Rong-En Fan <rafan@infor.org>
#
# $FreeBSD$
#

PORTNAME=	oxim
PORTVERSION=	1.2.2
PORTREVISION=	3
CATEGORIES=	chinese textproc
MASTER_SITES=	ftp://ftp.opendesktop.org.tw/odp/OXIM/Source/ \
		ftp://140.111.128.66/odp/OXIM/Source/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Open X Input Method server

RUN_DEPENDS=	${LOCALBASE}/share/fonts/TrueType/fireflysung.ttf:${PORTSDIR}/chinese/fireflyttf

OPTIONS=	GTK2 "Enable GTK2 input method module" On \
		CHEWING "Enable Chewing input module" On \
		UNICODE "Enable Unicode input module" On

USE_ICONV=	yes
USE_XORG=	x11 xft xpm xtst
WANT_GNOME=	yes

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -liconv
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--disable-bimsphone-module \
		--disable-static \
		--with-conf-dir=${PREFIX}/etc/${PORTNAME} \
		--enable-setup-tool=no
# oxim requires qinputcontextplugin.h which only exists in Debian package
CONFIGURE_ARGS+=--disable-qt-immodule

MAN1=		oxim.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GTK2)
CONFIGURE_ARGS+=	--disable-gtk-immodule
PLIST_SUB+=	GTK2="@comment "
.else
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--enable-gtk-immodule
PLIST_SUB+=	GTK2=""
.endif

.if !defined(WITHOUT_CHEWING)
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

.if !defined(WITHOUT_UNICODE)
CONFIGURE_ARGS+=	--enable-unicode-module
PLIST_SUB+=	UNICODE=""
.else
CONFIGURE_ARGS+=	--disable-unicode-module
PLIST_SUB+=	UNICODE="@comment "
.endif

# TODO WITHOUT_NLS knob
#.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -lintl"
PLIST_SUB+=	NLS=""
#.else
#CONFIGURE_ARGS+=--disable-nls
#PLIST_SUB+=	NLS="@comment "
#.endif

post-patch:
	${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' \
			${WRKSRC}/src/gtk-immodule/gtkintl.h

post-install:
.if !defined(WITHOUT_GTK2)
	@gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules
.endif
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.post.mk>
