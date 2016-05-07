# Created by: Carl Johan Gustavsson <cjg@bsdmail.org>
# $FreeBSD$

PORTNAME=	speex
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://freenet.mcnabhosting.com/python/pySpeex/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pySpeex-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for the Speex compressor/decompressor audio codec

BUILD_DEPENDS=	pyrex>=0.9.6.2:devel/pyrex
LIB_DEPENDS=	libspeex.so:audio/speex

USES=		python
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/speex.so

.include <bsd.port.mk>
