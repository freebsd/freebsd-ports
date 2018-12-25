# Created by: Hannes Hauswedell <h2+fbsdports@fsfe.org>
# $FreeBSD$

PORTNAME=	seqan-apps
DISTVERSIONPREFIX=	seqan-v
DISTVERSION=	2.4.0
PORTREVISION=	5
CATEGORIES=	biology

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Official bioinformatic applications based on the SeqAn library

LICENSE=	BSD3CLAUSE LGPL3 GPLv3
LICENSE_COMB=	multi

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake compiler:openmp # once #199603 is resolved, add c++14-lang
USE_GITHUB=	yes
GH_ACCOUNT=	seqan
GH_PROJECT=	seqan
CMAKE_ARGS=	-DSEQAN_BUILD_SYSTEM="SEQAN_RELEASE_APPS"

OPTIONS_RADIO=		ARCH
OPTIONS_RADIO_ARCH=	SSE4 AVX2 NATIVE
SSE4_DESC=		Use SSE4 and POPCNT instructions
SSE4_CMAKE_ON=		-DSEQAN_ARCH_SSE4:BOOL=TRUE
AVX2_DESC=		Use SSE4, AVX2 and POPCNT instructions
AVX2_CMAKE_ON=		-DSEQAN_ARCH_AVX2:BOOL=TRUE
NATIVE_DESC=		Use all available instruction sets (-march=native)
NATIVE_CMAKE_ON=	-DSEQAN_ARCH_NATIVE:BOOL=TRUE

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PLIST_SUB+=	RM_I386="@comment "
.else
PLIST_SUB+=	RM_I386=""
.endif

.if ${ARCH:Mmips*} || ${ARCH:Mpowerpc*} || ${ARCH} == sparc64
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
