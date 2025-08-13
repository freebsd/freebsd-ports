PORTNAME=	qschematic
DISTVERSION=	3.0.3
CATEGORIES=	devel

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	Qt/C++ library providing widgets for drawing diagrams
WWW=		https://github.com/simulton/qschematic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libgpds.so:devel/gpds

USES=		cmake compiler:c++23-lang pkgconfig qt:6
USE_QT=		base

USE_GITHUB=	yes
GH_ACCOUNT=	simulton
GH_PROJECT=	QSchematic

CMAKE_ARGS=	-DQSCHEMATIC_DEPENDENCY_GPDS_TARGET:STRING="gpds::gpds-shared"
CMAKE_OFF=	QSCHEMATIC_BUILD_DEMO QSCHEMATIC_DEPENDENCY_GPDS_DOWNLOAD

# Since the update from USES qt:5 to qt:6 there appears to be some overlinking
# resulting in pulling in OpenGL which is not needed by upstream.
# Put a "workaround" in place until we get to investigate this.
LDFLAGS+=	-Wl,--as-needed

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
