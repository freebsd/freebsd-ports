# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	attic
PORTVERSION=	0.16
PORTREVISION=	2
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Attic-${PORTVERSION}

MAINTAINER=	tom@hur.st
COMMENT=	Deduplicating backup program

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Unsupported by upstream, please migrate to archivers/py-borg. \
		See https://borgbackup.readthedocs.io/en/stable/usage/upgrade.html\#borg-upgrade
EXPIRATION_DATE=	2019-09-01

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0.1.10:devel/py-msgpack@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0.1.10:devel/py-msgpack@${PY_FLAVOR}

USES=		python:3.3-3.6 ssl
USE_PYTHON=	autoplist cython distutils

PYDISTUTILS_BUILDPATH=${BUILD_WRKSRC}/build/lib.${OPSYS:tl}-${UNAMER}-${ARCH}-${PYTHON_VER}
REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e 's|msgpack-python|msgpack|' ${WRKSRC}/setup.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/attic/*.so

do-test:
	cd ${WRKDIR} && ${SETENV} PYTHONPATH="${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}:${PYTHONPATH}" \
		${PYTHON_CMD} -m attic.testsuite.run

.include <bsd.port.mk>
