# Created by: Mark Reidel <ports@mark.reidle.info>
# $FreeBSD$

PORTNAME=	musicpc
DISTVERSION=	0.31
CATEGORIES=	audio ipv6
MASTER_SITES=	http://www.musicpd.org/download/mpc/0/
DISTNAME=	mpc-${PORTVERSION}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Command line client for the musicpd

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient

USES=		meson pkgconfig tar:xz
MESON_ARGS=	--mandir=${MANPREFIX}

OPTIONS_DEFINE=	DOCS ICONV
OPTIONS_DEFAULT=	DOCS ICONV

DOCS_USES=	python:env
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}
DOCS_MESON_ENABLED=	documentation

ICONV_USES=	iconv
ICONV_LDFLAGS=	-L${ICONV_PREFIX}/lib ${ICONV_LIB}
ICONV_MESON_ENABLED=	iconv

PORTDOCS=	AUTHORS README.rst NEWS

.include <bsd.port.mk>
