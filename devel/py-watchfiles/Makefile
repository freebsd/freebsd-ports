PORTNAME=	watchfiles
PORTVERSION=	0.18.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, modern and high performance file watching and code reload in python
WWW=		https://github.com/samuelcolvin/watchfiles

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.0.0:devel/py-anyio@${PY_FLAVOR}

USES=		dos2unix python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/pyproject.toml
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.mk>
