PORTNAME=	pysam
DISTVERSION=	0.19.1
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for reading, manipulating and writing genomic data sets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_arm64=	conflicting symbol (libchtslib libcsamtools ...) : $d.6
BROKEN_riscv6=	conflicting symbol (libchtslib libcsamtools ...): .Lline_table_start0

USES=		gmake python:3.6-3.9
USE_PYTHON=	autoplist distutils cython cython_run

.include <bsd.port.mk>
