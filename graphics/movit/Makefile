PORTNAME=	movit
PORTVERSION=	1.7.2
CATEGORIES=	graphics
MASTER_SITES=	http://${PORTNAME}.sesse.net/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	High-performance video filters for the GPU
WWW=		https://movit.sesse.net

LICENSE=	GPLv2+

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libfftw3.so:math/fftw3

USES=		autoreconf compiler:c++14-lang gmake eigen:3 libtool \
		pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS TEST

TEST_BUILD_DEPENDS=	benchmark>0:devel/benchmark \
			${NONEXISTENT}:devel/googletest:patch \
			${LOCALBASE}/bin/sdl2-config:devel/sdl20
TEST_MAKE_ENV=		GTEST_DIR="`${MAKE} -C ${PORTSDIR}/devel/googletest -VWRKSRC`/googletest"
TEST_ALL_TARGET_OFF=	libmovit.la
TEST_TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} -e '/AC_INIT/ s|git|${PORTVERSION}|' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|-lepoxy|@epoxy_LIBS@|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/features\.h/ d' \
		${WRKSRC}/demo.cpp

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.*

.include <bsd.port.mk>
