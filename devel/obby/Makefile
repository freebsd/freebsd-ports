# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	obby
PORTVERSION=	0.4.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://releases.0x539.de/obby/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for synced document buffers

LICENSE=	GPLv2

LIB_DEPENDS=	libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		libnet6.so:${PORTSDIR}/net/net6

USES=		pathfix pkgconfig libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
