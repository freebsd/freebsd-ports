# New ports collection makefile for:	bpl+
# Date created:			22 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bpl+
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	max
DISTNAME=	${PORTNAME}

MAINTAINER=	max@FreeBSD.org
COMMENT=	B Plus file transfer protocol

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bpl ${PREFIX}/bin
	@${LN} -fs ${PREFIX}/bin/bpl ${PREFIX}/bin/bp

.include <bsd.port.mk>
