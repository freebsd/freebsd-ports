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
USE_PYTHON=	distutils noflavors
SHEBANG_FILES=	${PORTNAME}

OPTIONS_DEFINE=	PDF
OPTIONS_DEFAULT=PDF
PDF_DESC=	Exporting to PDF
PDF_RUN_DEPENDS=pdflatex:print/tex-formats

NO_ARCH=	yes

.include <bsd.port.pre.mk>

# ronn is broken on 11.x => do not build manpages
.if ${OSVERSION} < 1200000
PLIST_SUB+=	MAN="@comment "
.else
BUILD_DEPENDS+=	ronn:textproc/rubygem-ronn
PLIST_SUB+=	MAN=""
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|' ${WRKSRC}/Makefile
.if ${OSVERSION} < 1200000
	${REINPLACE_CMD} -e 's|i18n manpages|manpages|' ${WRKSRC}/Makefile
.else

post-build:
	(cd ${WRKSRC} && LC_ALL=C.UTF-8 ${MAKE} manpages)
.endif

do-test: install
	#(cd ${WRKSRC} && ${MAKE} test)
	${DO_NADA} # It uses unittest-data-provider which is deprecated

.include <bsd.port.post.mk>
