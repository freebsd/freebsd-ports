# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	gxmessage
PORTVERSION=	3.4.3
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	GNU \
		LOCAL/martymac

MAINTAINER=	avg@icyb.net.ua
COMMENT=	GTK3 substitute for xmessage

USE_GNOME=	gtk30 gnomeprefix intltool
USES=		gmake gnome pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

MAKE_ARGS+=	INSTALL="${INSTALL_PROGRAM}"

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

INFO=		${PORTNAME}

.include <bsd.port.mk>
