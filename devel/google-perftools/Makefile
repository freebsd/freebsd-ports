# Created by: Yuri Victorovich <yuri@tsoft.com>
# $FreeBSD$

PORTNAME=	google-perftools
PORTVERSION=	2.2.1
CATEGORIES=	devel
MASTER_SITES=	https://googledrive.com/host/0B6NtGsLhIcf7MWxMMF9JdTN3UVk/ \
		${MASTER_SITE_LOCAL}
DISTNAME=	gperftools-${PORTVERSION}

MAINTAINER=	yuri@tsoft.com
COMMENT=	Fast, multi-threaded malloc() and nifty performance analysis tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

PROJECTHOST=	gperftools

WRKSRC=		${WRKDIR}/gperftools-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/gperftools

BUILD_DEPENDS+=	${LOCALBASE}/include/execinfo.h:${PORTSDIR}/devel/libexecinfo
LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		compiler libtool

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
BROKEN=	Does not build, assembly not supported, see PR-94: http://code.google.com/p/google-perftools/issues/detail?id=94&can=1
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
	@${ECHO} "Please run 'make check'. Two testcases are known to fail."
	@${ECHO} "Report any testcase failures to http://code.google.com/p/google-perftools/issues/list"
	@${ECHO}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig ${STAGEDIR}${PREFIX}/libdata

# four of the tests are known to fail on 7.0, uncomment this as soon as this is fixed
#regression-test: check

check: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.post.mk>
