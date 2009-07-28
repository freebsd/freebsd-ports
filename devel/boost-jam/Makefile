# Ports collection makefile for:  boost-jam
# Date Created:			  15 March 2009
# Whom:				  Alexander Churanov <churanov.port.maintainer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	boost-jam
COMMENT=	Build tool from the boost.org
USE_BZIP2=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/boost-all/common.mk"
.include "${PORTSDIR}/devel/boost-all/sites.mk"

.if ${ARCH} == alpha
BJAM-SUFFIX=	axp
.elif ${ARCH} == sparc64
BJAM-SUFFIX=	sparc
.elif ${ARCH} == ia64
BJAM-SUFFIX=	ia64
.elif ${ARCH} == powerpc
BJAM-SUFFIX=	ppc
.elif ${ARCH} == i386
BJAM-SUFFIX=	x86
.elif ${ARCH} == amd64
BJAM-SUFFIX=	x86_64
.else
BJAM-SUFFIX=	
.endif

BJAM=		${WRKSRC}/tools/jam/src/bin.freebsd${BJAM-SUFFIX}/bjam

do-build:
	cd ${WRKSRC}/tools/jam/src && ./build.sh gcc;

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BJAM} ${PREFIX}/bin/

.include <bsd.port.post.mk>
