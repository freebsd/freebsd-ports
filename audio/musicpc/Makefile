PORTNAME=	musicpc
DISTVERSION=	0.34
CATEGORIES=	audio
MASTER_SITES=	http://www.musicpd.org/download/mpc/0/
DISTNAME=	mpc-${PORTVERSION}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Command line client for the musicpd

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rsync>0:net/rsync
LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient

USES=		meson pkgconfig tar:xz

MESON_ARGS=	--mandir=${MANPREFIX}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS ICONV
OPTIONS_DEFAULT=	DOCS ICONV

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_USES=	python:env
DOCS_MESON_ENABLED=	documentation

ICONV_USES=	iconv
ICONV_MESON_ENABLED=	iconv
ICONV_LDFLAGS=	-L${ICONV_PREFIX}/lib ${ICONV_LIB}

.include <bsd.port.mk>
