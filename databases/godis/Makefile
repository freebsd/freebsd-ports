# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	godis
PORTVERSION=	20120405
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	LOCAL/jlaffaye

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Redis client library written in Go

USES=		go
GO_PKGNAME=	github.com/simonz05/${PORTNAME}

pre-install:
	@${RM} ${WRKSRC}/fmt.sh

.include <bsd.port.mk>
