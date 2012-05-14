# New ports collection makefile for:   pcmanx
# Date created:                2005/07/16
# Whom:                        chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pcmanx
PORTVERSION=	1.1
CATEGORIES=	chinese net gnome
MASTER_SITES=	http://pcmanx-gtk2.googlecode.com/files/
DISTNAME=	${PORTNAME}-gtk2-${PORTVERSION}

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	BBS client using GTK+ 2.x

LICENSE=	GPLv2

USE_XZ=		yes
USE_GNOME=	gtk20 intlhack
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS=	NLS		"Use Native Language Support"		on  \
		DEBUG		"Build with debugging support"		off \
		DOCKLET		"Docklet / system tray support"		on  \
		NOTIFIER	"Popup notifier support"		on  \
		LIBNOTIFY	"Popup notifier support by libnotify"	off \
		NANCY		"Nancy bot support"			on  \
		MOUSE		"Mouse click and wheel support"		on  \
		EXTERNAL	"Eexternal SSH/Telnet support"		on  \
		IPLOOKUP	"IP location lookup support"		off \
		PROXY		"Proxy support"				off

MAN1=		pcmanx.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

.if defined(WITHOUT_DOCKLET)
CONFIGURE_ARGS+=--disable-docklet
.endif

.if defined(WITHOUT_NOTIFIER)
CONFIGURE_ARGS+=--disable-notifier
.endif

.if defined(WITH_LIBNOTIFY)
CONFIGURE_ARGS+=--enable-libnotify
.endif

.if defined(WITHOUT_NANCY)
CONFIGURE_ARGS+=--disable-nancy
.endif

.if defined(WITHOUT_MOUSE)
CONFIGURE_ARGS+=--disable-mouse
.endif

.if defined(WITHOUT_EXTERNAL)
CONFIGURE_ARGS+=--disable-external
.endif

.if defined(WITH_IPLOOKUP)
CONFIGURE_ARGS+=--enable-iplookup
.endif

.if defined(WITH_PROXY)
CONFIGURE_ARGS+=--enable-proxy
.endif

.include <bsd.port.post.mk>
