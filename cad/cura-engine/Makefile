# $FreeBSD$

PORTNAME=		CuraEngine
DISTVERSIONPREFIX=	v
DISTVERSION=		4.5.0-19
DISTVERSIONSUFFIX=	-gdbf3d79
PORTREVISION=	1
PORTEPOCH=		1
CATEGORIES=		cad
DIST_SUBDIR=		Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	Engine of slicing solution for RepRap 3D printers

LICENSE=	AGPLv3

LIB_DEPENDS=	libArcus.so:net/libarcus	\
		libprotobuf.so:devel/protobuf

USES=		compiler:c++11-lang cmake

STB_TAG=	d5d052c

USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
GH_PROJECT=	CuraEngine
GH_TAGNAME=	dbf3d79
GH_TUPLE=	nothings:stb:${STB_TAG}:stb/include/stb

CMAKE_ARGS+=	-DStb_FOUND:BOOL=ON		\
		-DStb_INCLUDE_DIRS=${WRKSRC}/include

PLIST_FILES=	bin/CuraEngine

.include <bsd.port.mk>
