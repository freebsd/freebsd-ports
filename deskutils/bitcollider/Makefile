# New ports collection makefile for:	bitcollider
# Date created:		7 January 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitcollider
PORTVERSION=	0.6.0
CATEGORIES=	deskutils multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A Bitzi metadata generator

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

HAS_CONFIGURE=	yes
CFLAGS+=	-lm
INSTALLS_SHLIB=	yes

.include <bsd.port.post.mk>
