# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libc++
PORTVERSION=	${SVN_REV}
CATEGORIES=	devel
MASTER_SITES=	LOCAL/kwm

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Llvm's C++ standard library with c++11 support

BUILD_DEPENDS=	clang33:${PORTSDIR}/lang/clang33

LICENSE_GROUP=	MIT UIUC
LICENSE_NAME_UIUC=	University of Illinois/NCSA Open Source License
LICENSE_PERMS_UIUC=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_BZIP2=	yes
USES=		cmake:outsource
USE_LDCONFIG=	yes

CC=	clang33
CXX=	clang++33
CPP=	clang-cpp33

.include <bsd.port.options.mk>

.if ${OSVERSION} <  901502
IGNORE=		Doesn't build due to lack of aligned_alloc()
.endif

# This check can be replaced with a compiler groks c++11. Suggestions welcome.
.if ${OSVERSION} >= 1000019 
IGNORE=		libc++ is in base please use that
.endif

.if !defined(SVN_REV)
.if defined(BOOTSTRAP)
LANG=           "C"
SVN_REV!=       svn info http://llvm.org/svn/llvm-project/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif
.endif

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+= svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
		http://llvm.org/svn/llvm-project/libcxx/trunk ${WRKSRC}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
	echo "SVN_REV=  ${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
.endif

regression-test: build
	cd ${WRKSRC}/test && ${SH} ./testit

.include <bsd.port.mk>
