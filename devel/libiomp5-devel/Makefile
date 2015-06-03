# Created by: Brooks Davis
# $FreeBSD$

PORTNAME=	libiomp5
PORTVERSION=	3.7.r${SVN_REV}
CATEGORIES=	devel
MASTER_SITES=	LOCAL/brooks
PKGNAMESUFFIX=	-devel
DISTNAME=	openmp-${PORTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Intel/LLVM OpenMP runtime

BUILD_DEPENDS+=	llvm-config${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm${LLVM_SUFFIX}

LLVM_SUFFIX=	-devel
LLVM_PREFIX=	${PREFIX}/llvm${LLVM_SUFFIX}
#DATADIR=	${PREFIX}/share/${PORTNAME}${LLVM_SUFFIX}
#DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${LLVM_SUFFIX}
CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}
CMAKE_ARGS=	-Darch=${OPENMP_ARCH}

USES=		cmake compiler:c++11-lang ninja tar:xz

WRKSRC=		${WRKDIR}/${DISTNAME}/runtime

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
OPENMP_ARCH=	32
BROKEN_FreeBSD_9=	doesn't compile with base clang
.elif ${ARCH} == "amd64"
OPENMP_ARCH=	32e
.elif ${ARCH} == "powerpc64"
OPENMP_ARCH=	ppc64
.elif ${ARCH} == "arm" || ${ARCH} == "aarch64"
OPENMP_ARCH=	${ARCH}
.else
BROKEN=		Only builds on amd64, arm, aarch64, powerpc64, and i386.
.endif

.include "${.CURDIR}/../../devel/llvm-devel/Makefile.svn_rev"

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
SVN?=	svnlite
do-fetch:
	${MKDIR} ${WRKDIR}
	${SVN} export -r ${SVN_REV} \
	    http://llvm.org/svn/llvm-project/openmp/trunk ${WRKDIR}/${DISTNAME}
	cd ${WRKDIR}; tar cvfJ ${DISTDIR}/${DISTNAME}.tar.xz ${DISTNAME}
.if ${USER} == brooks || ${USER} == bed22
	scp ${DISTDIR}/${DISTNAME}.tar.xz \
	    brooks@freefall.freebsd.org:public_distfiles/
.endif
.endif

.include <bsd.port.post.mk>
