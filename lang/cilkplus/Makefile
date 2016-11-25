# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	cilkplus
PORTVERSION=	20160603
CATEGORIES=	lang devel
MASTER_SITES=	https://www.cilkplus.org/sites/default/files/runtime_source/
PKGNAMESUFFIX=	-rtl
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${HG_REVISION}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Intel Cilk Runtime

LICENSE=	BSD3CLAUSE

HG_REVISION=	004467

USE_GCC=	yes

ONLY_FOR_ARCHS=	i386 amd64 sparc64

USE_LDCONFIG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-src-${HG_REVISION}

USES=		tar:tgz cmake

.include <bsd.port.mk>
