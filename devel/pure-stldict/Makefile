# New ports collection makefile for:	pure-stldict
# Date created:		2011-12-05
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-stldict
PORTVERSION=	0.3
CATEGORIES=	devel

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure interface to C++ STL map/unordered_map

USE_PURE=	yes

USE_GCC=	4.6+
CXX=		g++${GCC_DEFAULT_V}
CXXFLAGS+=	-std=c++0x -DHAVE_STD_IS_PERMUTATION
CXXFLAGS+=	-DHAVE_STD_IS_PERMUTATION

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/pure/bsd.pure.mk"
.include <bsd.port.post.mk>
