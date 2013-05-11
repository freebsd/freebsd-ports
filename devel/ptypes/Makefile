# Created by: ijliao
# $FreeBSD$

PORTNAME=	ptypes
PORTVERSION=	2.1.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	C++ Portable Types Library

SHLIB_VER=	21

USE_LDCONFIG=	yes
PLIST_SUB+=	SHLIB_VER=${SHLIB_VER}
PTYPES_CFLAGS=	${CFLAGS}
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DEBUG OPTIMIZED_CFLAGS DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not install on powerpc
.endif

.if ${PORT_OPTIONS:MDEBUG}
DEBUG_FLAGS=	"-DDEBUG -g"
.endif
.if ${PORT_OPTIONS:MOPTIMIZED}
PTYPES_CFLAGS+=-O2
.endif

MAKE_ARGS+=	DEBUG_FLAGS="${DEBUG_FLAGS}" PTYPES_CFLAGS="${PTYPES_CFLAGS}"

do-install:
	${MKDIR} ${PREFIX}/include/ptypes
	${RM} -f ${WRKSRC}/include/*.orig
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/ptypes
	${MKDIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/so/libptypes.so.${SHLIB_VER} \
		${PREFIX}/lib
	cd ${PREFIX}/lib; ${LN} -sf libptypes.so.${SHLIB_VER} libptypes.so
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/lib
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${EXAMPLESDIR}/wshare
	-${RM} -f ${WRKSRC}/wshare/*.o ${WRKSRC}/wshare/*.orig
	${INSTALL_DATA} ${WRKSRC}/wshare/*.* ${EXAMPLESDIR}/wshare
	${INSTALL_PROGRAM} ${WRKSRC}/wshare/wshare ${EXAMPLESDIR}/wshare
	${MKDIR} ${DOCSDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${WRKSRC}/index.html ${DOCSDIR}
	cd ${WRKSRC}/doc; ${TAR} cf - *| ${TAR} xf - -C ${DOCSDIR}/doc
.endif

.include <bsd.port.mk>
