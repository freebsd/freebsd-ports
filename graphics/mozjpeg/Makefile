# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	mozjpeg
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Advanced JPEG encoder for the Web

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	mozilla
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	594b725

USES=		libtool:oldver
USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
USE_LDCONFIG=	${PREFIX}/include/${PORTNAME} ${PREFIX}/lib/${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${PREFIX}/share/doc/${PORTNAME} \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--libdir=${PREFIX}/lib/${PORTNAME}
AUTOMAKE_ARGS+=	-fiv --add-missing
LDFLAGS+=	-L${PREFIX}/lib/${PORTNAME}

PLIST_SUB=	PORTNAME=${PORTNAME} \
		VER=${VER}

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}/doc/html
DOCSDIR1=	${DOCSDIR}/html

DOCSRCDIR2=	${DOCSRCDIR1}/search
DOCSDIR2=	${DOCSDIR1}/search

DOC_FILES=	*.css *.html *.js *.png

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES GCC SIMD TURBOJPEG

OPTIONS_GROUP=	ARITHMETIC_CODING
OPTIONS_GROUP_ARITHMETIC_CODING=	DECODING ENCODING

OPTIONS_MULTI=	LIBRARIES
OPTIONS_MULTI_LIBRARIES=	SHARED STATIC

OPTIONS_SINGLE=	API_ABI_EMULATION
OPTIONS_SINGLE_API_ABI_EMULATION=	JPEG6B JPEG7 JPEG8

OPTIONS_DEFAULT=	DECODING ENCODING GCC JPEG8 SHARED TURBOJPEG

OPTIONS_SUB=	yes

GCC_DESC=	Use the GNU Compiler Collection (GCC) for best performance
SIMD_DESC=	Include SIMD extensions (MMX, SSE2, NEON)
TURBOJPEG_DESC=	Include the TurboJPEG wrapper library and associated tests

ENCODING_DESC=	Enable arithmetic encoding
DECODING_DESC=	Enable arithmetic decoding

STATIC_DESC=	Build static libraries
SHARED_DESC=	Build shared libraries

JPEG6B_DESC=	API/ABI-compatible with libjpeg v6b
JPEG7_DESC=	API/ABI-compatible with libjpeg v7 (implies arith-coding)
JPEG8_DESC=	API/ABI-compatible with libjpeg v8 (implies arith-coding)

GCC_USE=	GCC=yes
SIMD_CONFIGURE_WITH=	simd
SIMD_BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm
TURBOJPEG_CONFIGURE_WITH=	turbojpeg

JPEG7_CONFIGURE_WITH=	jpeg7
JPEG8_CONFIGURE_WITH=	jpeg8

STATIC_CONFIGURE_ENABLE=	static
SHARED_CONFIGURE_ENABLE=	shared

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJPEG6B}
. if ! ${PORT_OPTIONS:MENCODING}
CONFIGURE_ARGS+=	--without-arith-enc
. endif
. if ! ${PORT_OPTIONS:MDECODING}
CONFIGURE_ARGS+=	--without-arith-dec
. endif
VER=	63
.else
VER=	8
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|docdir = $$(datadir)/doc|&/mozjpeg|; \
		/^exampledir/s|=.*|= ${EXAMPLESDIR}|' \
			${WRKSRC}/Makefile.am

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR1}
	${INSTALL_DATA} ${DOC_FILES:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.if ${PORT_OPTIONS:MSHARED}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/libjpeg.so.${VER}
.endif

.if ${PORT_OPTIONS:MSHARED} && ${PORT_OPTIONS:MTURBOJPEG}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/libturbojpeg.so.1
.endif

.include <bsd.port.mk>
