# New ports collection makefile for:	Nickle
# Date created:				16 April 2001
# Whom:				Christopher Elkins <chrise@scardini.com>
#
# $FreeBSD$
#

PORTNAME=	nickle
PORTVERSION=	2.70
CATEGORIES=	lang
MASTER_SITES=	http://www.nickle.org/release/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A numeric oriented programming language

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

# Nickle now has bindings which are likely to pull in libraries that need
# libpthread.  Link to it now, since it wouldn't work at runtime.
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"

MAN1=		nickle.1

.include <bsd.port.mk>
