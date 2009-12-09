# New ports collection makefile for:	compiler-rt
# Date created:		8 Oct 2009
# Whom:                 Brooks Davis
#
# $FreeBSD$
#

PORTNAME=	compiler-rt
DISTVERSION=	0.r${SVN_REV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Compiler runtime library with Blocks support

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

CONFIGURE_WRKSRC=	${WRKDIR}/build
BUILD_WRKSRC=		${WRKDIR}/build
INSTALL_WRKSRC=		${WRKDIR}/build

CMAKE_SOURCE_PATH=	${WRKSRC}

USE_CMAKE=	yes
USE_GCC=	4.2+
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	VERBOSE=1
MAKE_JOBS_SAFE=	yes

LLVM_SVN=	http://llvm.org/svn/llvm-project

# fixuns?fti_test tests fail
# powi?f2_test tests fail to link due to lack of -lm
BROKEN_TESTS?=	fixunsdfti_test \
		fixunssfti_test \
		powidf2_test \
		powisf2_test \
		powixf2_test

PLIST_FILES=	include/Block.h \
		include/Block_private.h \
		lib/libBlocksRuntime.so

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CFLAGS+=	-march=i486
.endif

.if defined(BOOTSTRAP)
SVN_REV!=	svn info ${LLVM_SVN}/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif

.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
	    ${LLVM_SVN}/compiler-rt/trunk ${WRKSRC}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
	echo "SVN_REV=	${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
.if ${USER} == brooks
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    freefall.freebsd.org:public_distfiles/
.endif
.endif

post-extract:
	${MKDIR} ${CONFIGURE_WRKSRC}

post-patch:
.for test in ${BROKEN_TESTS}
	${REINPLACE_CMD} -e 's/\(MACRO_ADD_CHECK_TEST( ${test}\)/# \1/' \
	    ${WRKSRC}/test/CMakeLists.txt
.endfor

regression-test:
	cd ${BUILD_WRKSRC} && make test

.include <bsd.port.post.mk>
