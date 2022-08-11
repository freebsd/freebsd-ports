PORTNAME=	pysam
DISTVERSION=	0.19.1
PORTREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/pysam-developers/pysam/commit/
PATCHFILES=	064c8024395a15024fd590bd90f55f918e15545f.patch:-p1 # backport of symbols failure fix for arm and risc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for reading, manipulating and writing genomic data sets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake python:3.6-3.9
USE_PYTHON=	autoplist distutils cython cython_run

.include <bsd.port.mk>
