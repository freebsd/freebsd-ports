# New ports collection makefile for:	xscorch
# Date created:				19 Apr 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	xscorch
PORTVERSION=	0.1.14
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xscorch/ \
		http://mirror.dok.org/xscorch/

MAINTAINER=	petef@FreeBSD.org

LIB_DEPENDS=	mikmod.2:${PORTSDIR}/audio/libmikmod

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_GTK=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk

MAN6=		xscorch.6

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.else
CONFIGURE_ARGS+=	--without-gnome
.endif

post-patch:
	@${PERL} -pi -e 's,MSG_NOSIGNAL,0,' \
		${WRKSRC}/snet/tcpnet/tn_internal.c \
		${WRKSRC}/snet/tcpnet/tn_read.c

.include <bsd.port.post.mk>
