# Created by: r.neese
# $FreeBSD$

PORTNAME=	sphinxbase
PORTVERSION=	0.7
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmusphinx/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CMU Sphinx Speech recognition system base

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison 

USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool

CONFIGURE_ARGS+=	--without-python --without-lapack
CONFIGURE_ENV+=	HAVE_DOXYGEN=no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION}

OPTIONS_DEFINE=	SNDFILE THREADS
OPTIONS_DEFAULT=	THREADS

SNDFILE_DESC=	libsndfile support
THREADS_DESC=	Build with thread safety support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSNDFILE}
USE_PKGCONFIG=	build
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
.else
CONFIGURE_ENV+=	HAVE_PKGCONFIG=no
.endif

.if ${PORT_OPTIONS:MTHREADS}
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
