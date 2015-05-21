# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	google-perftools
PORTVERSION=	2.4
CATEGORIES=	devel
MASTER_SITES=	https://googledrive.com/host/0B6NtGsLhIcf7MWxMMF9JdTN3UVk/
DISTNAME=	gperftools-${PORTVERSION}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Fast, multi-threaded malloc() and nifty performance analysis tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

PROJECTHOST=	gperftools

WRKSRC=		${WRKDIR}/gperftools-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/gperftools

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		compiler execinfo libtool

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lexecinfo

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == "clang" && !defined(USE_GCC)
# clang cannot disable builtins individually
CXXFLAGS+=	-fno-builtin
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--enable-frame-pointers
.endif
.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=	Does not build, assembly not supported, see PR#94: http://code.google.com/p/google-perftools/issues/detail?id=94&can=1
.endif

post-patch:
.if ${COMPILER_TYPE} == "clang" && !defined(USE_GCC)
	${REINPLACE_CMD} -Ee \
		's|-fno-builtin-[a-z_]+||g' \
		${WRKSRC}/Makefile.in
.endif
.if empty(PORT_OPTIONS:MDOCS)
	${REINPLACE_CMD} -e \
		'/^install-data-am:/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

post-build:
	@${ECHO}
	@${ECHO} "Please run 'make check' (requires bash)."
	@${ECHO} "Two testcases are known to fail. Testsuite is known to be"
	@${ECHO} "unreliable and give false positives and negatives (PR#661)."
	@${ECHO}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig ${STAGEDIR}${PREFIX}/libdata

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so.*

# four of the tests are known to fail on 7.0, uncomment this as soon as this is fixed
#regression-test: check

check: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.post.mk>
