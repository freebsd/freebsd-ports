# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	kosmorro
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	astro python

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Ephemerides computation

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYNUMPY}	\
		ronn:textproc/rubygem-ronn	\
		${PYTHON_PKGNAMEPREFIX}skyfield>0:astro/py-skyfield@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}termcolor>0:devel/py-termcolor@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}skyfield>0:astro/py-skyfield@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}termcolor>0:devel/py-termcolor@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pipenv>0:devel/py-pipenv@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}unittest2>0:devel/py-unittest2@${PY_FLAVOR}

USE_GITHUB=	yes

USES=		python:3.7+ shebangfix
USE_PYTHON=	distutils
SHEBANG_FILES=	${PORTNAME}

OPTIONS_DEFINE=	PDF
OPTIONS_DEFAULT=PDF
PDF_DESC=	Exporting to PDF
PDF_RUN_DEPENDS=pdflatex:print/tex-formats

NO_ARCH=	yes

pre-configure:
	${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|' ${WRKSRC}/Makefile

post-build:
	(cd ${WRKSRC} && LC_ALL=C.UTF-8 ${MAKE} manpages)

do-test: install
	#(cd ${WRKSRC} && ${MAKE} test)
	${DO_NADA} # It uses unittest-data-provider which is deprecated

.include <bsd.port.mk>
