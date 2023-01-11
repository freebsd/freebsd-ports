PORTNAME=	platformdirs
PORTVERSION=	2.5.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module for determining appropriate platform-specific dirs
WWW=		https://github.com/platformdirs/platformdirs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/pyproject.toml
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.mk>
