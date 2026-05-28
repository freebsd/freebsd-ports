PORTNAME=	opennurbs
PORTVERSION=	8.27.26019.16021
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Tools to accurately transfer 3-D geometry between applications
WWW=		http://opennurbs.org/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	mcneel

LIB_DEPENDS=	libuuid.so:misc/libuuid

USES=		cmake compiler:c++17-lang iconv:build localbase
CFLAGS+=	-DON_COMPILER_CLANG	\
		-DON_SIZEOF_WCHAR_T=4
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${ARCH} != "sparc64" && ${ARCH} != "powerpc" && ${ARCH} != powerpc64
CFLAGS+=	-DON_LITTLE_ENDIAN
.else
CFLAGS+=	-DON_BIG_ENDIAN
.endif

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples_linking_pragmas.h \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/opennurbs.h ${STAGEDIR}${EXAMPLESDIR}
.for i in brep convert gl read roundtrip test userdata write
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/example_${i}
	cd ${WRKSRC}/example_${i} && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/example_${i} "-name *\.cpp -or -name *\.h"
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/opennurbs_cpp_base.h ${STAGEDIR}${PREFIX}/include/OpenNURBS/
	${MV} ${STAGEDIR}${PREFIX}/lib/libOpenNURBS.so ${STAGEDIR}${PREFIX}/lib/libOpenNURBS.so.0
	${LN} -sf libOpenNURBS.so.0 ${STAGEDIR}${PREFIX}/lib/libOpenNURBS.so
	${RM} ${STAGEDIR}${PREFIX}/lib/libzlib.a

.include <bsd.port.post.mk>
