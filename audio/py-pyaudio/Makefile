# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	pyaudio
PORTVERSION=	0.2.7
CATEGORIES=	audio python
MASTER_SITES=	http://people.csail.mit.edu/hubert/pyaudio/packages/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Portaudio toolkit bindings for Python

LIB_DEPENDS=	libportaudio.so:${PORTSDIR}/audio/portaudio2

USE_PYTHON=		yes
NO_STAGE=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyAudio

WRKSRC=		${WRKDIR}/PyAudio-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/*.js ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/*.inv ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} _static ${DOCSDIR}/
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} _sources ${DOCSDIR}/
.endif

.include <bsd.port.mk>
