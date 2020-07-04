# Created by: Christoph Kick
# $FreeBSD$

PORTNAME=	ffi
PORTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	110

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Extension for dynamic libraries & binding functions

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libffi.so:devel/libffi

USES=		gem
USE_RUBY=	yes

PORTSCOUT=	limit:^1\.10\.

.include <bsd.port.mk>
