# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-stldict
PORTVERSION=	0.5
CATEGORIES=	devel

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure interface to C++ STL map/unordered_map

USE_PURE=	yes

USE_GCC=	yes
CXXFLAGS+=	-std=c++0x -DHAVE_STD_IS_PERMUTATION

.include "${.CURDIR}/../../lang/pure/bsd.pure.mk"
.include <bsd.port.mk>
