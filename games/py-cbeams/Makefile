# Created by: Mateusz Piotrowski <0mp@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cbeams
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0rc3-52
DISTVERSIONSUFFIX=	-gda823c2
CATEGORIES=	games python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
# Loosen for the dependencies.
PATCHFILES=	422477bc4c21a0e8ea95549e699edd0c94faa78d.patch:-p1

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Draw pretty animated colored circles in the terminal

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blessings>=1.6:devel/py-blessings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docopt>=0.6.1:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	tartley
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
