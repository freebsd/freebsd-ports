# New ports collection makefile for:	tdl
# Date created:				30 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	tdl
PORTVERSION=	0.6
CATEGORIES=	devel
MASTER_SITES=	http://www.rrbcurnow.freeuk.com/tdl/

MAINTAINER=	petef@FreeBSD.org

ALL_TARGET=	tdl

post-patch:
	@${PERL} -pi -e 's,/usr/local,${PREFIX},; s,gcc,${CC},; \
		s,-O2,${CFLAGS},' ${WRKSRC}/Makefile

.include <bsd.port.mk>
