# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

_BUILDING_OPENCV_CORE=	yes
MASTERDIR=	${.CURDIR}/../opencv

_COMPVERSION!= ${CC} --version
.if ${_COMPVERSION:Mclang}
CXXFLAGS+=	-std=gnu++11 -Wno-error -Wno-c++11-narrowing
.endif

.include "${MASTERDIR}/Makefile"
