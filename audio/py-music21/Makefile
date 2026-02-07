PORTNAME=	music21
DISTVERSION=	9.7.1
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Toolkit for computer-aided musical analysis
WWW=		https://web.mit.edu/music21/ \
		https://github.com/cuthbertLab/music21

LICENSE=	BSD3CLAUSE LGPL3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpickle>0:devel/py-jsonpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webcolors>=1.5:graphics/py-webcolors@${PY_FLAVOR} \
		lilypond:print/lilypond \
		mscore:audio/musescore \
		xdg-open:devel/xdg-utils

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e " \
		s|/usr/bin/lilypond|${LOCALBASE}/bin/lilypond|; \
		s|/usr/bin/mscore3|${LOCALBASE}/bin/mscore|; \
		s|/usr/bin/xdg-open|${LOCALBASE}/bin/xdg-open|" \
		${WRKSRC}/music21/environment.py

# tests as of 9.7.1: 542 passed, 4 warnings in 79.82s (0:01:19)

.include <bsd.port.mk>
