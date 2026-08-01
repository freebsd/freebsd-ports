PORTNAME=	types-retry
DISTVERSION=	0.9.9.20260408
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	types_retry-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Typing stubs for retry
WWW=		https://github.com/python/typeshed

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# Use generated setup.py because upstream PEP 621 license metadata is incompatible with the ports setuptools version.
post-extract:
	@${ECHO} "from setuptools import setup" > ${WRKSRC}/setup.py
	@${ECHO} "setup(" >> ${WRKSRC}/setup.py
	@${ECHO} "    name='types-retry'," >> ${WRKSRC}/setup.py
	@${ECHO} "    version='${DISTVERSION}'," >> ${WRKSRC}/setup.py
	@${ECHO} "    packages=['retry-stubs']," >> ${WRKSRC}/setup.py
	@${ECHO} "    package_data={'retry-stubs': ['__init__.pyi', 'api.pyi', 'METADATA.toml', 'py.typed']}," >> ${WRKSRC}/setup.py
	@${ECHO} "    include_package_data=False," >> ${WRKSRC}/setup.py
	@${ECHO} ")" >> ${WRKSRC}/setup.py

.include <bsd.port.mk>
