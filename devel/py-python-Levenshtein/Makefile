PORTNAME=	python-Levenshtein
PORTVERSION=	0.12.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Fast computation of Levenshtein distance and string similarity
WWW=		https://github.com/ztane/python-Levenshtein

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/Levenshtein/_levenshtein*.so

.include <bsd.port.mk>
