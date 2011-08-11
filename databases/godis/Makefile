# New ports collection makefile for:	godis
# Date created:				20 June , 2011
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	godis
PORTVERSION=	20110527
CATEGORIES=	databases
MASTER_SITES=	https://github.com/downloads/Roorback/mgk_ports/

MAINTAINER=	magik@roorback.net
COMMENT=	A Redis client library written in Go

FETCH_ARGS=	-Fpr
WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST_FILES=	${GO_LIBDIR}/godis.a

USE_GO=		yes

.include <bsd.port.pre.mk>
.include "../../lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
