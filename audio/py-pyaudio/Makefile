PORTNAME=	pyaudio
PORTVERSION=	0.2.13
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyAudio-${PORTVERSION}

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Portaudio toolkit bindings for Python
WWW=		https://people.csail.mit.edu/hubert/pyaudio/

LICENSE=	MIT

LIB_DEPENDS=	libportaudio.so:audio/portaudio

USES=		gmake python
USE_PYTHON=	autoplist concurrent distutils

MAKE_ENV=	PYTHON=${PYTHON_CMD} \
		SPHINX=sphinx-build-${PYTHON_VER}

WRKSRC=		${WRKDIR}/PyAudio-${PORTVERSION}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/setup.py

post-build-DOCS-on:
	(cd ${BUILD_WRKSRC} && \
		${DO_MAKE_BUILD} docs)

post-install-DOCS-on:
	(cd ${WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -path *doctrees*")

.include <bsd.port.mk>
