# $FreeBSD$

PORTNAME=	dxirc
PORTVERSION=	1.10.0
PORTREVISION=	3
CATEGORIES=	irc
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	arch_dvx@users.sourceforge.net
COMMENT=	Simple IRC client written using the FOX toolkit

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFOX-1.6.so:x11-toolkits/fox16

USE_XORG=	xft
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS TRAY IPV6 SSL LUA ENCHANT NOTIFY DOCS
OPTIONS_DEFAULT=	TRAY SSL LUA

TRAY_DESC=	Trayicon
ENCHANT_DESC=	Spellchecking support
NOTIFY_DESC=	Libnotify support

PORTDOCS=	README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USES+=		gettext
PLIST_SUB+=	NLS=""
.endif

.if ! ${PORT_OPTIONS:MTRAY}
CONFIGURE_ARGS+=	--disable-tray
.endif

.if ! ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if ${PORT_OPTIONS:MLUA}
USES+=		lua:51
CONFIGURE_ENV+=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}"
CONFIGURE_ARGS+=	--enable-lua
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

.if ${PORT_OPTIONS:MENCHANT}
LIB_DEPENDS+=	libenchant.so:textproc/enchant
CONFIGURE_ARGS+=	--enable-enchant
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:devel/libnotify
CONFIGURE_ARGS+=	--enable-libnotify
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
