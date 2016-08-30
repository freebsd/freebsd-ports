# Created by: ijliao
# $FreeBSD$

PORTNAME=	ptypes
PORTVERSION=	2.1.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Portable Types Library

SHLIB_VER=	21

USE_LDCONFIG=	yes
PLIST_SUB+=	SHLIB_VER=${SHLIB_VER}
PTYPES_CFLAGS=	${CFLAGS}
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DEBUG OPTIMIZED_CFLAGS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
DEBUG_FLAGS=	"-DDEBUG -g"
.endif
.if ${PORT_OPTIONS:MOPTIMIZED}
PTYPES_CFLAGS+=-O2
.endif

MAKE_ARGS+=	DEBUG_FLAGS="${DEBUG_FLAGS}" PTYPES_CFLAGS="${PTYPES_CFLAGS}"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/ptypes
	${RM} -f ${WRKSRC}/include/*.orig
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/include/ptypes
	${MKDIR} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/so/libptypes.so.${SHLIB_VER} \
		${STAGEDIR}${PREFIX}/lib
	cd ${STAGEDIR}${PREFIX}/lib; ${LN} -sf libptypes.so.${SHLIB_VER} libptypes.so
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${PREFIX}/lib
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/wshare
	-${RM} -f ${WRKSRC}/wshare/*.o ${WRKSRC}/wshare/*.orig
	${INSTALL_DATA} ${WRKSRC}/wshare/*.* ${STAGEDIR}${EXAMPLESDIR}/wshare
	${INSTALL_PROGRAM} ${WRKSRC}/wshare/wshare ${STAGEDIR}${EXAMPLESDIR}/wshare
	${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${WRKSRC}/index.html ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc; ${TAR} cf - *| ${TAR} xf - -C ${STAGEDIR}${DOCSDIR}/doc
.endif

.include <bsd.port.mk>
