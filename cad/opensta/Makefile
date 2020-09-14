# $FreeBSD$

PORTNAME=	opensta
DISTVERSION=	g20200907
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gate level static timing verifier

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libcudd.so:math/cudd

USES=		bison compiler:c++11-lang cmake tcl
USE_GITHUB=	yes
GH_ACCOUNT=	The-OpenROAD-Project
GH_PROJECT=	OpenSTA
GH_TAGNAME=	08acbfed00976fa89006b0b34687c1c1cd12d33c
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DFREEBSD_TCL_VER=${TCL_VER:S/.//} -DFREEBSD_TCL_INCLUDEDIR=${TCL_INCLUDEDIR} -DCUDD=${LOCALBASE}

LDFLAGS+=	-pthread

BINARY_ALIAS=	tclsh=${TCLSH}

.include <bsd.port.mk>
