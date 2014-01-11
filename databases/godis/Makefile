# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	godis
PORTVERSION=	20120405
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	LOCAL/jlaffaye

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	A Redis client library written in Go

GO_PKGNAME=	github.com/simonz05/${PORTNAME}

pre-install:
	@${RM} ${WRKSRC}/fmt.sh

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
