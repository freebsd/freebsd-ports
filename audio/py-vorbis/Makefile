# Created by: makeport.pl
# $FreeBSD$

PORTNAME=	vorbis
PORTVERSION=	1.4
PORTREVISION=	6
CATEGORIES=	audio python
MASTER_SITES=	http://ekyo.nerim.net/software/pyogg/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyvorbis-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-oriented Python bindings for the vorbis library

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-03-19

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/ogg/_ogg.so:audio/py-ogg@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ogg/_ogg.so:audio/py-ogg@${PY_FLAVOR}
LIB_DEPENDS=	libvorbis.so:audio/libvorbis

USES=		python:2.7
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
	${WRKSRC}/config_unix.py

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} config_unix.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ogg/vorbis.so

.include <bsd.port.mk>
