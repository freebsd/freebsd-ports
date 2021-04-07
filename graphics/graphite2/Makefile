PORTNAME=	graphite2
DISTVERSION=	1.3.14
CATEGORIES=	graphics print
MASTER_SITES=	https://github.com/silnrsi/graphite/releases/download/${DISTVERSION}/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Rendering capabilities for complex non-Roman writing systems

LICENSE=	GPLv2 LGPL21 MPL20
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools3>0:print/py-fonttools3@${PY_FLAVOR}

USES=		cmake compiler:c++11-lib python:test tar:tgz
USE_LDCONFIG=	yes

TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -e 's|/pkgconfig|data&|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
