# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libc++
PORTVERSION=	${SVN_REV}
CATEGORIES=	devel
MASTER_SITES=	http://files.etoilebsd.net/libc++/ \
		LOCAL/bapt

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Llvm's C++ standard library with c++11 support

LIB_DEPENDS=	libcxxrt.so:${PORTSDIR}/devel/libcxxrt

LICENSE_GROUP=	MIT UIUC
LICENSE_NAME_UIUC=	University of Illinois/NCSA Open Source License
LICENSE_PERMS_UIUC=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake:outsource compiler:c++11-lang tar:xz
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if exists(/usr/lib/libcxxrt.so)
CXXRT_INCS=	/usr/include/c++/v1/
CXXRT_LIB=	/usr/lib/libcxxrt.so
.else
CXXRT_INCS=	${LOCALBASE}/include/cxxrt/
CXXRT_LIB=	${LOCALBASE}/lib/libcxxrt.so
.endif

CMAKE_ARGS=	-DLIBCXX_CXX_ABI=libcxxrt -DLIBCXX_LIBCXXRT_INCLUDE_PATHS=${CXXRT_INCS}

.if !defined(SVN_REV)
.if defined(BOOTSTRAP)
SVN_REV!=       LC_ALL=C svn info http://llvm.org/svn/llvm-project/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif
.endif

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+= svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
		http://llvm.org/svn/llvm-project/libcxx/trunk \
		${WRKSRC}
	cd ${WRKDIR}; tar cfJ ${DISTDIR}/${DISTNAME}.tar.xz ${DISTNAME}
	echo "SVN_REV=  ${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
.endif

post-install:
	${LN} -sf c++/v1 ${STAGEDIR}${PREFIX}/include/c++/v1/tr1
	${RM} ${STAGEDIR}${PREFIX}/lib/libc++.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/c++/
	${ECHO} 'GROUP ( ${PREFIX}/lib/libc++.so.1 ${CXXRT_LIB})' > ${STAGEDIR}${PREFIX}/lib/libc++.so
	${ECHO} 'GROUP ( ${PREFIX}/lib/libc++.so.1 ${CXXRT_LIB})' > ${STAGEDIR}${PREFIX}/lib/c++/libstdc++.so

regression-test: build
	cd ${WRKSRC}/test && ${SH} ./testit

.include <bsd.port.mk>
