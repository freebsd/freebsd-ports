PORTNAME=	graphite2
DISTVERSION=	1.3.15
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	https://github.com/silnrsi/graphite/releases/download/${DISTVERSION}/

PATCH_SITES=	https://github.com/silnrsi/graphite/commit/
PATCHFILES=	2963a66ade6d8961dc1cf965eb74a1132b0396e2.patch:-p1

MAINTAINER=	office@FreeBSD.org
COMMENT=	Rendering capabilities for complex non-Roman writing systems
WWW=		https://graphite.sil.org

LICENSE=	GPLv2 LGPL21 MPL20
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>0:print/py-fonttools@${PY_FLAVOR}

USES=		cmake:testing compiler:c++11-lib cpe python:test tar:tgz
CPE_VENDOR=	sil
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING

post-patch:
	@${REINPLACE_CMD} -e 's|/pkgconfig|data&|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
