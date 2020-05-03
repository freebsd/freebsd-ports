# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ruamel.yaml.clib
PORTVERSION=	0.2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C version of reader, parser and emitter for ruamel.yaml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_ruamel_yaml.so
	${RM} -fr ${STAGEDIR}${PYTHON_SITELIBDIR}/ruamel
	${REINPLACE_CMD} -e '/LICENSE/d; /__init__.py/d' ${_PYTHONPKGLIST}

.include <bsd.port.mk>
