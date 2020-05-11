# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	pyaudio
PORTVERSION=	0.2.11
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyAudio-${PORTVERSION}

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Portaudio toolkit bindings for Python

LICENSE=	MIT

LIB_DEPENDS=	libportaudio.so:audio/portaudio

USES=		python gmake
USE_PYTHON=	distutils concurrent autoplist

MAKE_ENV=	PYTHON=${PYTHON_CMD} \
		SPHINX=sphinx-build-${PYTHON_VER}
PORTDOCS=	*
WRKSRC=		${WRKDIR}/PyAudio-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PY_SPHINX}

post-patch:
	@${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/setup.py

post-build-DOCS-on:
	(cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD} docs)

post-install-DOCS-on:
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -path *doctrees*")

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_portaudio.so

.include <bsd.port.mk>
