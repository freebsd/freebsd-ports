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

DEPRECATED=	Go libraries should not be packaged
EXPIRATION_DATE=	2017-04-08

pre-install:
	@${RM} ${WRKSRC}/fmt.sh

.include <bsd.port.mk>
