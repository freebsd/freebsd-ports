# Created by: Carl Johan Gustavsson <cjg@bsdmail.org>
# $FreeBSD$

PORTNAME=	speex
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://freenet.mcnabhosting.com/python/pySpeex/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pySpeex-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
DIST_SUBDIR=	python

MAINTAINER=	cjg@bsdmail.org
COMMENT=	Python bindings for the Speex compressor/decompressor audio codec

BUILD_DEPENDS=	pyrex>=0.9.6.2:${PORTSDIR}/devel/pyrex
LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex

USES=		python
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
