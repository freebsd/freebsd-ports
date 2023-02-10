PORTNAME=	idna
PORTVERSION=	3.4
CATEGORIES=	dns python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Internationalized Domain Names in Applications (IDNA)
WWW=		https://github.com/kjd/idna

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils unittest

NO_ARCH=	yes

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.mk>
