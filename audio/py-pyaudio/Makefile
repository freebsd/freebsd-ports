# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	pyaudio
PORTVERSION=	0.2.8
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://people.csail.mit.edu/hubert/pyaudio/packages/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Portaudio toolkit bindings for Python

LICENSE=	MIT

LIB_DEPENDS=	libportaudio.so:audio/portaudio

USES=		python
USE_PYTHON=	distutils autoplist

WRKSRC=		${WRKDIR}/PyAudio-${PORTVERSION}

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.js ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.inv ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} _static ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} _sources ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
