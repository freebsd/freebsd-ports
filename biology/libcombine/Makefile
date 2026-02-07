PORTNAME=	libcombine
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.20
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for working with the COMBINE archive format
WWW=		https://sbml.org/software/libsbml/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libsbml.so:biology/libsbml

USES=		cmake:testing compiler:c++11-lang gnome localbase:ldflags
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sbmlteam
GH_PROJECT=	libCombine
GH_TUPLE=	fbergmann:zipper:c56a27f:zipper/submodules/zipper \
		sebastiandev:minizip:e3a8cb7:zipper_minizip/submodules/zipper/minizip

CMAKE_OFF=	BUILD_TEST
CMAKE_TESTING_ON=	BUILD_TEST # tests fail to build, see https://github.com/sbmlteam/libCombine/issues/58

LDFLAGS+=	-lsbml # FindSBML.cmake fails to set this link flag

.include <bsd.port.mk>
