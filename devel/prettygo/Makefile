# New ports collection makefile for:	pretty.go
# Date created:				4 Nov, 2010
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	prettygo
PORTVERSION=	20110611
CATEGORIES=	devel
MASTER_SITES=	http://files.roorback.net/
DISTNAME=	pretty.go-${PORTVERSION}

MAINTAINER=	magik@roorback.net
COMMENT=	Pretty-printing package for go values

FETCH_ARGS=	-Fpr
WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GO=		yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
