# New ports collection makefile for:	intercal
# Date created:        20 March 1998
# Whom:                Matthew Hunt <mph@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	intercal
PORTVERSION=	0.24
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	The C-INTERCAL compiler, ick, and supporting libraries

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -D_POSIX_SOURCE"

.include <bsd.port.mk>
