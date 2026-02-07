PORTNAME=	kosmorrolib
PORTVERSION=	1.0.10
PORTREVISION=	2
CATEGORIES=	astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Library that computes the ephemerides
WWW=		https://kosmorro.space/

LICENSE=	CeCILL-C
LICENSE_NAME=	${LICENSE}
LICENSE_TEXT=	CeCILL-C Free Software License Agreement
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}skyfield>0:astro/py-skyfield@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}skyfield_data>0:astro/py-skyfield-data@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}skyfield>0:astro/py-skyfield@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}skyfield_data>0:astro/py-skyfield-data@${PY_FLAVOR}

#USE_GITHUB=	yes
#GH_ACCOUNT=	Kosmorro
#GH_PROJECT=	lib

USES=		python
USE_PYTHON=	pep517

PLIST_SUB=	VE=${PORTVERSION}

NO_ARCH=	yes

.include <bsd.port.mk>
