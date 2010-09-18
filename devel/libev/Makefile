# New ports collection makefile for:	libev
# Date created:							18 Dec 2007
# Whom:									vsevolod
#
# $FreeBSD$
#

PORTNAME=	libev
PORTVERSION=	3.9
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://dist.schmorp.de/libev/ \
		http://dist.schmorp.de/libev/Attic/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	A full-featured and high-performance event loop library

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN3=		ev.3

post-patch:
	@${REINPLACE_CMD} -e 's/if EV_MINIMAL/if defined(EV_MINIMAL) \&\& EV_MINIMAL/g' \
		${WRKSRC}/ev.h \
		${WRKSRC}/ev.c \
		${WRKSRC}/ev++.h

.include <bsd.port.mk>
