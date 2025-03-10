PORTNAME=	donut-shellcode
DISTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	donut shellcode Python C extension
WWW=		https://github.com/TheWover/donut

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	ships precompiled libraries for these two only

USES=		dos2unix python
USE_PYTHON=	distutils autoplist

DOS2UNIX_GLOB=	*.py

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
