# New ports collection makefile for:	xscorch
# Date created:				19 Apr 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	xscorch
PORTVERSION=	0.2.0
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xscorch/ \
		http://mirror.dok.org/xscorch/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Multiplayer tank shoot-em-up

LIB_DEPENDS=	mikmod.2:${PORTSDIR}/audio/libmikmod

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk

MAN6=		xscorch.6
NOMANCOMPRESS=	yes

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomeprefix gnomelibs
PKGNAMESUFFIX=	-gnome
PLIST_SUB+=	GNOME="gnome"
.else
CONFIGURE_ARGS+=	--without-gnome
PLIST_SUB+=	GNOME=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,MSG_NOSIGNAL,0,' \
		${WRKSRC}/snet/tcpnet/tn_internal.c \
		${WRKSRC}/snet/tcpnet/tn_read.c

.include <bsd.port.post.mk>
