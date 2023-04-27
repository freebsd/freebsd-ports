PORTNAME=	unpaper
DISTVERSION=	7.0.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/ \
		https://www.flameeyes.eu/files/

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Post-processing tool for scanned sheets of paper
WWW=		https://www.flameeyes.eu/projects/unpaper

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-only.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg

USES=		meson pkgconfig python:build tar:xz

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
