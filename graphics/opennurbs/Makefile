PORTNAME=	opennurbs
PORTVERSION=	20130711
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://files.na.mcneel.com/opennurbs/5.0/2013-07-11/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Tools to accurately transfer 3-D geometry between applications
WWW=		https://www.rhino3d.com/opennurbs

LICENSE_FILE=	${WRKSRC}/readme.txt

USES=		iconv:build dos2unix gmake zip
MAKE_ARGS=	CC="${CC}" CCC="${CXX}"

MAKEFILE=	makefile

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

# In r311275 zlib.h was moved to contrib/zlib/zlib.h from lib/libz/zlib.h
LIBZ=		${SRC_BASE}/contrib/zlib
.if !exists(${LIBZ}/zlib.h)
LIBZ=		${SRC_BASE}/sys/contrib/zlib
.endif
.if !exists(${LIBZ}/zlib.h)
LIBZ:=		${SRC_BASE}/lib/libz
.endif
.if !exists(${LIBZ}/zlib.h)
IGNORE=		needs SRC_BASE to compile. Install base system sources and try again
.endif

.if ${ARCH} != i386
MAKE_ARGS+=	ON_GNU_OPTIMIZER_FLAGS="-g -fPIC"
.endif

post-patch:
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
	@${REINPLACE_CMD} -e 's|D_GNU_SOURCE -I|D_GNU_SOURCE -Dregister= -I|g' \
		${WRKSRC}/makefile
.endif

pre-build:
	@${RM} -r ${WRKSRC}/zlib
	${CP} -R ${LIBZ} ${WRKSRC}/zlib

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/openNURBS/zlib
	${INSTALL_DATA} ${WRKSRC}/libopenNURBS.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/openNURBS
	${INSTALL_DATA} ${WRKSRC}/zlib/*.h \
		${STAGEDIR}${PREFIX}/include/openNURBS/zlib

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples_linking_pragmas.h \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/opennurbs.h ${STAGEDIR}${EXAMPLESDIR}
.for i in brep read roundtrip userdata write
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/example_${i}
	${INSTALL_PROGRAM} ${WRKSRC}/example_${i}/example_${i} ${STAGEDIR}${EXAMPLESDIR}/example_${i}
	cd ${WRKSRC}/example_${i} && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/example_${i} "-name *\.cpp -or -name *\.h"
.endfor

.include <bsd.port.post.mk>
