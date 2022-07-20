PORTNAME=	ruamel.yaml.clib
PORTVERSION=	0.2.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C version of reader, parser and emitter for ruamel.yaml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +
	${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/ruamel
	${REINPLACE_CMD} -e '/LICENSE/d; /__init__/d' ${_PYTHONPKGLIST}

.include <bsd.port.mk>
