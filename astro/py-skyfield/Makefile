PORTNAME=	skyfield
PORTVERSION=	1.53
PORTREVISION=	1
CATEGORIES=	astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Elegant astronomy for Python
WWW=		https://rhodesmill.org/skyfield/

LICENSE=	MIT

BUILD_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}sgp4>0:astro/py-sgp4@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}jplephem>0:astro/py-jplephem@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}sgp4>0:astro/py-sgp4@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}astropy>0:astro/py-astropy@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}jplephem>0:astro/py-jplephem@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pyflakes>0:devel/py-pyflakes@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}spktype21>0:astro/py-spktype21@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}termcolor>0:devel/py-termcolor@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils
NO_ARCH=	yes

do-test: install
	${CP} ${FILESDIR}/test-skyfield.py ${WRKSRC}
	(cd ${WRKSRC} && ${PYTHON_CMD} test-skyfield.py)

.include <bsd.port.mk>
