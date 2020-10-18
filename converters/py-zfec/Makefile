# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zfec
PORTVERSION=	1.5.4
CATEGORIES=	converters python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Efficient, portable erasure coding tool

LICENSE=	GPLv2+ TGGPL
LICENSE_COMB=	dual
LICENSE_NAME_TGGPL=	Transitive Grace Period Public Licence 1.0
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_TGGPL=	${WRKSRC}/COPYING.TGPPL.rst
LICENSE_PERMS_TGGPL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>=0.8:devel/py-argparse@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/zfec/_fec.so

.include <bsd.port.mk>
