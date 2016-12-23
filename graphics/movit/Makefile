# $FreeBSD$

PORTNAME=	movit
PORTVERSION=	1.4.0
CATEGORIES=	graphics
MASTER_SITES=	http://${PORTNAME}.sesse.net/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	High-performance video filters for the GPU

LICENSE=	GPLv2+

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libfftw3.so:math/fftw3
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen3.pc:math/eigen3
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		autoreconf gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/AC_INIT/ s/git/${PORTVERSION}/' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/^all/ s/$$(TESTS)//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/features\.h/ d' \
		${WRKSRC}/demo.cpp

post-install:
.if ${PORT_OPTIONS:MDOCS}
. for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${DOCSDIR}
. endfor
.endif
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.*

.include <bsd.port.mk>
