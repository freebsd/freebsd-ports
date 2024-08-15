PORTNAME=	pocketsphinx
PORTVERSION=	0.1.15
PORTREVISION=	3
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Python interface to CMU Sphinxbase and Pocketsphinx libraries
WWW=	https://github.com/bambocher/pocketsphinx-python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	swig40>0:devel/swig40
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libpulse-simple.so:audio/pulseaudio \
		libpulse.so:audio/pulseaudio

USES=	python
USE_PYTHON=	distutils

BINARY_ALIAS=	swig=swig40
CFLAGS+=	-I${LOCALBASE}/include

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pocketsphinx/_pocketsphinx${PYTHON_EXT_SUFFIX}.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/sphinxbase/_ad_alsa${PYTHON_EXT_SUFFIX}.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/sphinxbase/_ad_pulse${PYTHON_EXT_SUFFIX}.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/sphinxbase/_sphinxbase${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
