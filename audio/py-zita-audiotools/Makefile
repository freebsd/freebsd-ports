PORTNAME=	zita-audiotools
DISTVERSION=	1.0.0
CATEGORIES=	audio python
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tools for audio processing

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libzita-resampler.so:audio/zita-resampler

USES=		localbase python:3.6+ tar:bz2
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}fmoo-audiotools

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/audiotools/*.so

.include <bsd.port.mk>
