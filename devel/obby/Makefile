# Ports collection makefile for:	obby
# Date created:				2005-10-14
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	obby
PORTVERSION=	0.4.8
CATEGORIES=	devel
MASTER_SITES=	http://releases.0x539.de/obby/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for synced document buffers

LICENSE=	GPLv2

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20 \
		net6:${PORTSDIR}/net/net6

USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.if !defined(WITHOUT_NLS)
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
