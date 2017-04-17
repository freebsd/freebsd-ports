# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	pyaudio
PORTVERSION=	0.2.11
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyAudio-${PORTVERSION}

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Portaudio toolkit bindings for Python

LICENSE=	MIT

LIB_DEPENDS=	libportaudio.so:audio/portaudio
BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

USES=		python gmake
USE_PYTHON=	distutils autoplist

WRKSRC=		${WRKDIR}/PyAudio-${PORTVERSION}

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/setup.py

pre-install:
	(cd ${BUILD_WRKSRC} && ${MAKE_CMD} PYTHON=${PYTHON_CMD} docs)

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.js ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.inv ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} _static ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} _sources ${STAGEDIR}${DOCSDIR}/
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_portaudio.so

.include <bsd.port.mk>
