PORTNAME=	donut-shellcode
DISTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	donut shellcode Python C extension
WWW=		https://github.com/TheWover/donut

LICENSE=	BSD3CLAUSE

USES=		dos2unix python
USE_PYTHON=	distutils autoplist

DOS2UNIX_GLOB=	*.py

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
