# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	pyaudio
PORTVERSION=	0.2.7
CATEGORIES=	audio python
MASTER_SITES=	http://people.csail.mit.edu/hubert/pyaudio/packages/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Portaudio toolkit bindings for Python

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS=	libportaudio.so:${PORTSDIR}/audio/portaudio2

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

WRKSRC=		${WRKDIR}/PyAudio-${PORTVERSION}

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.js ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.inv ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} _static ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} _sources ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
