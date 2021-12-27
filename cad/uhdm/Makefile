PORTNAME=	uhdm
DISTVERSIONPREFIX=	v
DISTVERSION=	g20211226
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal Hardware Data Model

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake tcl:86,build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	chipsalliance
GH_PROJECT=	${PORTNAME:tu}
GH_TAGNAME=	a8be019
GH_TUPLE=	capnproto:capnproto:14f24a4:capnproto/third_party/capnproto \
		google:googletest:e2239ee:googletest/third_party/googletest

CMAKE_ON=	BUILD_SHARED_LIBS

BINARY_ALIAS=	tclsh=${TCLSH}

.include <bsd.port.mk>
