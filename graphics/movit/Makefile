# $FreeBSD$

PORTNAME=	movit
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://${PORTNAME}.sesse.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance video filters for the GPU

LICENSE=	GPLv2+

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libfftw3.so:math/fftw3

USES=		autoreconf compiler:c++11-lang gmake eigen:3,build,run libtool \
		pathfix pkgconfig
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
