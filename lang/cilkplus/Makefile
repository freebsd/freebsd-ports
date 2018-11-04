# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	cilkplus
PORTVERSION=	20160603
PORTREVISION=	4
CATEGORIES=	lang devel
MASTER_SITES=	https://www.cilkplus.org/sites/default/files/runtime_source/
PKGNAMESUFFIX=	-rtl
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${HG_REVISION}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Intel Cilk Runtime

LICENSE=	BSD3CLAUSE

DEPRECATED=	Cilk Plus is on its way out (both in GCC and the Intel compilers)
EXPIRATION_DATE=2019-01-04

ONLY_FOR_ARCHS=		amd64 i386 sparc64

HG_REVISION=	004467

USE_GCC=	7	# GCC 8 removed CilkPlus support

USE_LDCONFIG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-src-${HG_REVISION}

USES=		tar:tgz cmake

.include <bsd.port.mk>
