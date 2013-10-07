# $FreeBSD$

PORTNAME=	dxirc
PORTVERSION=	1.10.0
PORTREVISION=	2
CATEGORIES=	irc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	arch_dvx@users.sourceforge.net
COMMENT=	Simple IRC client written using the FOX toolkit

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16

USE_XORG=	xft
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_DEFINE=	NLS TRAY IPV6 SSL LUA ENCHANT NOTIFY
OPTIONS_DEFAULT=	TRAY SSL LUA

TRAY_DESC=	Trayicon
ENCHANT_DESC=	Spellchecking support
NOTIFY_DESC=	Libnotify support

PORTDOCS=	README

NO_STAGE=	yes
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
USE_LUA=	5.1+
WANT_LUA_VER=	5.1
CONFIGURE_ENV+=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua"
CONFIGURE_ARGS+=	--enable-lua
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

.if ${PORT_OPTIONS:MENCHANT}
LIB_DEPENDS+=	enchant:${PORTSDIR}/textproc/enchant
CONFIGURE_ARGS+=	--enable-enchant
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=	--enable-libnotify
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
