# Created by: Mark Reidel <ports@mark.reidle.info>
# $FreeBSD$

PORTNAME=	musicpc
DISTVERSION=	0.29
PORTREVISION=	1
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

PLIST_FILES=	bin/mpc

OPTIONS_DEFINE=	DOCS EXAMPLES MANPAGES ICONV
OPTIONS_DEFAULT=	MANPAGES ICONV

MANPAGES_USES=	python:env
MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}
MANPAGES_MESON_TRUE=	use_sphinx
MANPAGES_PLIST_FILES=	man/man1/mpc.1.gz

ICONV_USES=	iconv
ICONV_LDFLAGS=	-L${ICONV_PREFIX}/lib ${ICONV_LIB}
ICONV_MESON_TRUE=	iconv

PORTDOCS=	AUTHORS README.rst NEWS
PORTEXAMPLES=	*

.include <bsd.port.mk>
