# New ports collection makefile for:	zed
# Date created:        4 June 2002
# Whom:                Sten Poldma
#
# $FreeBSD$
#

PORTNAME=	zed
PORTVERSION=	1.0.5
CATEGORIES=	editors
MASTER_SITES=	http://zed.c3po.it/

MAINTAINER=	exile@chamber.ee

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/zed

.include <bsd.port.mk>
