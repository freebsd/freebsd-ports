# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	gxmessage
PORTVERSION=	2.12.4
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	GNU \
		LOCAL/martymac

MAINTAINER=	avg@icyb.net.ua
COMMENT=	GTK2 substitute for xmessage

USE_GNOME=	gtk20 gnomeprefix
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

MAKE_ARGS+=	INSTALL="${INSTALL_PROGRAM}"

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MANCOMPRESSED=	no
MAN1=		gxmessage.1
INFO=		${PORTNAME}

.include <bsd.port.mk>
