PORTNAME=	nodeeditor
DISTVERSION=	3.0.11
CATEGORIES=	devel
MASTER_SITES+=	https://raw.githubusercontent.com/catchorg/Catch2/v2.13.10/single_include/catch2/:catch2
DISTFILES+=	catch.hpp:catch2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Qt Node Editor, Dataflow programming framework
WWW=		https://github.com/paceholder/nodeeditor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=		cmake gl qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	paceholder
GH_PROJECT=	nodeeditor
USE_GL=		gl
USE_QT=		base

CMAKE_ARGS=	-DBUILD_DOCS=OFF

post-extract:
	${MKDIR} ${WRKDIR}/.build/external/Catch2/single_include/catch2
	${LN} -s ${DISTDIR}/catch.hpp ${WRKDIR}/.build/external/Catch2/single_include/catch2

.include <bsd.port.mk>
