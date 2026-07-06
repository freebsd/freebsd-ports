PORTNAME=	graphite2
DISTVERSION=	1.3.15
CATEGORIES=	graphics print
MASTER_SITES=	https://github.com/silnrsi/graphite/releases/download/${DISTVERSION}/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Rendering capabilities for complex non-Roman writing systems
WWW=		https://graphite.sil.org

LICENSE=	GPLv2 LGPL21 MPL20
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>0:print/py-fonttools@${PY_FLAVOR}

USES=		cmake:testing compiler:c++11-lib cpe pathfix python:test tar:tgz
CPE_VENDOR=	sil
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING

post-patch:
	@${REINPLACE_CMD} -e 's|/pkgconfig|data&|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
