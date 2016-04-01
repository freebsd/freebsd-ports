# Created by: r.neese
# $FreeBSD$

PORTNAME=	sphinxbase
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmusphinx/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CMU Sphinx Speech recognition system base

USES=		bison gmake pathfix libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-python --without-lapack
CONFIGURE_ENV+=	HAVE_DOXYGEN=no
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION}

OPTIONS_DEFINE=	SNDFILE THREADS
OPTIONS_DEFAULT=	THREADS

SNDFILE_DESC=	libsndfile support
THREADS_DESC=	Build with thread safety support

SNDFILE_USES=		pkgconfig
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_ENV_OFF=	HAVE_PKGCONFIG=no

THREADS_LDFLAGS=		-lpthread
THREADS_CONFIGURE_ENABLE=	threads

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsphinx*.so

.include <bsd.port.mk>
