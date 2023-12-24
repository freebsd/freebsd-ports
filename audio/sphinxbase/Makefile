PORTNAME=	sphinxbase
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmusphinx/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CMU Sphinx Speech recognition system base
WWW=		http://www.speech.cs.cmu.edu/sphinx/

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Upstream last release was in 2012
EXPIRATION_DATE=	2024-01-25

USES=		bison:alias gmake pathfix libtool localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-python --without-lapack
CONFIGURE_ENV+=	HAVE_DOXYGEN=no

MAKE_ENV=	MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION}

OPTIONS_DEFINE=	SNDFILE THREADS
OPTIONS_DEFAULT=	THREADS

SNDFILE_DESC=	libsndfile support
THREADS_DESC=	Build with thread safety support

SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_USES=		pkgconfig
SNDFILE_CONFIGURE_ENV_OFF=	HAVE_PKGCONFIG=no
THREADS_CONFIGURE_ENABLE=	threads
THREADS_LDFLAGS=		-lpthread

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsphinx*.so

.include <bsd.port.mk>
