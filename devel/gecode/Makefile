# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gecode
DISTVERSIONPREFIX=	release-
DISTVERSION=	6.2.0
CATEGORIES=	devel math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	f08079c5df271869bc7c0799b3eccc52ca2f4d83.patch:-p1 # https://github.com/Gecode/gecode/pull/51
PATCHFILES+=	c810c96b1ce5d3692e93439f76c4fa7d3daf9fbb.patch:-p1 # fix C++ clang-10 problem with static field assignments
PATCHFILES+=	bb1efcd8c4bf5d8d6c079a1b7704c51ea958bf06.patch:-p1 # suppress clang warnings about wrong array index
PATCHFILES+=	3b86d0dabc371d5976c5dafef0fc7f6c5f92640b.patch:-p1 # https://github.com/Gecode/gecode/pull/102: Fix MOC invocation in gist folder

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic Constraint Development Environment

LICENSE=	BSL MIT
LICENSE_COMB=	multi

NOT_FOR_ARCHS=		aarch64 armv6 armv7 mips mips64
NOT_FOR_ARCHS_REASON=	needs code written to specify rounding control mechanism in Boost.Numeric.Interval

USES=		bison:alias cmake compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Gecode

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=		GIST
OPTIONS_SUB=		yes

GIST_DESC=		Enable gist, graphical and interactive search tool
GIST_CMAKE_BOOL=	ENABLE_GIST
GIST_USES=		qt:5
GIST_USE=		qt=core,gui,printsupport,widgets,qmake_build,buildtools_build

.include <bsd.port.mk>
