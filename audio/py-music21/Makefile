# $FreeBSD$

PORTNAME=	music21
DISTVERSION=	6.7.1
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Toolkit for computer-aided musical analysis

LICENSE=	BSD3CLAUSE LGPL3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpickle>0:devel/py-jsonpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webcolors>0:graphics/py-webcolors@${PY_FLAVOR} \
		lilypond:print/lilypond \
		mscore:audio/musescore \
		xdg-open:devel/xdg-utils

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e " \
		s|/usr/bin/lilypond|${LOCALBASE}/bin/lilypond|; \
		s|/usr/bin/mscore3|${LOCALBASE}/bin/mscore|; \
		s|/usr/bin/xdg-open|${LOCALBASE}/bin/xdg-open|" \
		${WRKSRC}/music21/environment.py

.include <bsd.port.mk>
