# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	cilkplus
PORTVERSION=	20160603
PORTREVISION=	2
CATEGORIES=	lang devel
MASTER_SITES=	https://www.cilkplus.org/sites/default/files/runtime_source/
PKGNAMESUFFIX=	-rtl
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${HG_REVISION}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Intel Cilk Runtime

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=		amd64 i386 sparc64

HG_REVISION=	004467

USE_GCC=	yes

USE_LDCONFIG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-src-${HG_REVISION}

USES=		tar:tgz cmake

.include <bsd.port.mk>
