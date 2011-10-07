# New ports collection makefile for:	godis
# Date created:				20 June , 2011
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	godis
PORTVERSION=	20110803
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	LOCAL/jlaffaye

MAINTAINER=	magik@roorback.net
COMMENT=	A Redis client library written in Go

PLIST_FILES=	${GO_LIBDIR}/godis.a

USE_GO=		yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
