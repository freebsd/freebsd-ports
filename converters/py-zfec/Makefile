# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zfec
DISTVERSION=	1.5.3
CATEGORIES=	converters python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast erasure codec for Python

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>=0:devel/py-argparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyutil>=0:devel/py-pyutil@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist concurrent

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	COPYING.TGPPL.rst README.rst TODO

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/zfec/_fec.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DOC in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
