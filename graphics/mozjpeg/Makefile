# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	mozjpeg
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Advanced JPEG encoder for the Web

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	mozilla
GH_TAGNAME=	594b725

USES=		autoreconf libtool
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${PREFIX}/share/doc/${PORTNAME} \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--libdir=${PREFIX}/lib/${PORTNAME} \
		--with-jpeg8
INSTALL_TARGET=	install-strip

PLIST_SUB=	PORTNAME=${PORTNAME}

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}/doc/html
DOCSDIR1=	${DOCSDIR}/html

DOCSRCDIR2=	${DOCSRCDIR1}/search
DOCSDIR2=	${DOCSDIR1}/search

DOC_FILES=	*.css *.html *.js *.png

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES GCC SIMD TURBOJPEG

OPTIONS_MULTI=	LIBRARIES
OPTIONS_MULTI_LIBRARIES=	SHARED STATIC

OPTIONS_DEFAULT=GCC SHARED TURBOJPEG

OPTIONS_SUB=	yes

GCC_DESC=	Use the GNU Compiler Collection (GCC) for best performance
SIMD_DESC=	Include SIMD extensions (MMX, SSE2, NEON)
TURBOJPEG_DESC=	Include the TurboJPEG wrapper library and associated tests

STATIC_DESC=	Build static libraries
SHARED_DESC=	Build shared libraries

GCC_USE=	GCC=yes
SIMD_CONFIGURE_WITH=	simd
SIMD_BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm
TURBOJPEG_CONFIGURE_WITH=	turbojpeg

STATIC_CONFIGURE_ENABLE=	static
SHARED_CONFIGURE_ENABLE=	shared

post-patch:
	@${REINPLACE_CMD} -e 's|docdir = $$(datadir)/doc|&/mozjpeg|; \
		/^exampledir/s|=.*|= ${EXAMPLESDIR}|' \
			${WRKSRC}/Makefile.am

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR1}
	${INSTALL_DATA} ${DOC_FILES:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
