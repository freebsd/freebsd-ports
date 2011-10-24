# New ports collection makefile for:	intercal
# Date created:        20 March 1998
# Whom:                Matthew Hunt <mph@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	intercal
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The C-INTERCAL compiler, ick, and supporting libraries

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CFLAGS+=	-D_POSIX_SOURCE

post-patch:
#
# Respect PREFIX
#
	@${REINPLACE_CMD} -E -e "s,/usr/local,${PREFIX},g" \
		${WRKSRC}/perpetrate.c

.include <bsd.port.mk>
