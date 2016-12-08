# Created by: giffunip
# $FreeBSD$
#    $MCom: ports/devel/lasi/Makefile,v 1.1 2006/10/04 20:25:40 ahze Exp $

PORTNAME=	lasi
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20Source
DISTNAME=	libLASi-${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	C++ stream output interface for creating Postscript documents

LIB_DEPENDS=	libltdl.so:devel/libltdl

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		cmake pathfix pkgconfig
PATHFIX_CMAKELISTSTXT=	pkg-config.cmake
USE_GNOME=	pango
PKG_CONFIG_PATH=	${PREFIX}/libdata/pkgconfig
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${PKG_CONFIG_PATH}

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_INSTALL_DATADIR:PATH=${DATADIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${LOCALBASE}/bin/doxygen:devel/doxygen
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-cmake+modules+lasi.cmake
.endif

pre-install:
.if ! ${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} 's/^\(add_subdirectory(examples)\)/#\1/' \
		${WRKSRC}/CMakeLists.txt
.endif

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/lib/libLASi.so.1.0.0 \
		${STAGEDIR}${PREFIX}/lib/libLASi.so.1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MV} ${STAGEDIR}${DATADIR}/doc/* ${STAGEDIR}${DOCSDIR}/
	@${RMDIR} ${STAGEDIR}${DATADIR}/doc
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${MV} ${STAGEDIR}${DATADIR}/examples/* ${STAGEDIR}${EXAMPLESDIR}/
	@${RMDIR} ${STAGEDIR}${DATADIR}/examples
.endif
.if ! ${PORT_OPTIONS:MDOCS} && ! ${PORT_OPTIONS:MEXAMPLES}
	@${RM} -r ${STAGEDIR}${DATADIR}/*
.endif
	@${TEST} -d ${STAGEDIR}${DATADIR} && \
		${RMDIR} ${STAGEDIR}${DATADIR} || ${TRUE}

.include <bsd.port.mk>
