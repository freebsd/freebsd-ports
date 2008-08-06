# New ports collection makefile for:   nickle
# Date created:        16 April 2001
# Whom:                Christopher Elkins <chrise@scardini.com>
#
# $FreeBSD$
#

PORTNAME=	nickle
PORTVERSION=	2.56
CATEGORIES=	lang
MASTER_SITES=	http://www.nickle.org/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A desk calculator language

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget

# Nickle now has bindings which are likely to pull in libraries that need
# libpthread.  Link to it now, since it wouldn't work at runtime.
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		nickle.1

.include <bsd.port.mk>
