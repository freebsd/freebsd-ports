# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	PyOgg
DISTVERSION=	0.6.14a1
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Xiph.org's Ogg Vorbis, Opus, and FLAC for Python

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libogg.so:audio/libogg \
		libopusfile.so:audio/opusfile \
		libvorbis.so:audio/libvorbis

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
