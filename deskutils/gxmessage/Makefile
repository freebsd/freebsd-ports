# New ports collection makefile for:	gxmessage
# Date created:				9 March 2005
# Whom:					Andriy Gapon <avg@icyb.net.ua>
#
# $FreeBSD$
#

PORTNAME=	gxmessage
PORTVERSION=	2.12.4
CATEGORIES=	deskutils
MASTER_SITES=	http://homepages.ihug.co.nz/~trmusson/stuff/ \
		LOCAL/martymac

MAINTAINER=	avg@icyb.net.ua
COMMENT=	GTK2 substitute for xmessage

USE_GNOME=	gtk20 gnomeprefix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

MAKE_ARGS+=	INSTALL="${INSTALL_PROGRAM}"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
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
