PORTNAME=	zita-audiotools
DISTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tools for audio processing
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libzita-resampler.so:audio/zita-resampler

USES=		localbase python tar:bz2
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}fmoo-audiotools

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zita_audiotools/*.so

.include <bsd.port.mk>
