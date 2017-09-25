# $FreeBSD$

PORTNAME=	libftdi1
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.intra2net.com/en/developer/libftdi/download/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Library (using libusb) to talk to FTDI chips

LICENSE=	GPLv2

LIB_DEPENDS=	libconfuse.so:devel/libconfuse

OPTIONS_DEFINE=		PYTHON BOOST DOCS EXAMPLES
OPTIONS_DEFAULT=	PYTHON BOOST
OPTIONS_SUB=		yes

BOOST_DESC=	Build with boost
PYTHON_DESC=	Build Python bindings

BROKEN_sparc64=		Does not build: fails to link

USES=		cmake gettext-runtime pkgconfig tar:bzip2
USE_LDCONFIG=	yes

PORTDOCS=	COPYING.LIB ChangeLog README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=	-DDOCUMENTATION:BOOL=true
.else
CMAKE_ARGS+=	-DDOCUMENTATION:BOOL=false
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
CMAKE_ARGS+=	-DEXAMPLES:BOOL=true
.else
CMAKE_ARGS+=	-DEXAMPLES:BOOL=false
.endif

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python:2
CMAKE_ARGS+=	-DPYTHON_BINDINGS:BOOL=true
BUILD_DEPENDS+=	swig2.0:devel/swig20
.else
CMAKE_ARGS+=	-DPYTHON_BINDINGS:BOOL=false
.endif

.if ${PORT_OPTIONS:MBOOST}
CMAKE_ARGS+=		-DFTDIPP:BOOL=true
LIB_DEPENDS+=	libboost_system.so:devel/boost-libs
.else
CMAKE_ARGS+=		-DFTDIPP:BOOL=false
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
.for fname in baud_test bitbang bitbang2 bitbang_cbus bitbang_ft2232 eeprom find_all serial_test simple stream_test
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${fname} ${STAGEDIR}${PREFIX}/bin/ftdi1_${fname}_example
.endfor
.if ${PORT_OPTIONS:MBOOST}
.for fname in find_all_pp
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${fname} ${STAGEDIR}${PREFIX}/bin/ftdi1_${fname}_example
.endfor
.endif
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
