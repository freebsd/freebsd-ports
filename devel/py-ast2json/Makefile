PORTNAME=	ast2json
DISTVERSION=	0.3
CATEGORIES=	devel science
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convert a python source code into json-dumpable AST data
WWW=		https://github.com/YoloSwagTeam/ast2json

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	distutils # autoplist: autoplist contains the 'test' folder that is removed

NO_ARCH=	yes

post-install: # see https://github.com/YoloSwagTeam/ast2json/issues/10
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/test

.include <bsd.port.mk>
