# $FreeBSD$

PORTNAME=	libSavitar
DISTVERSION=	4.5.0
CATEGORIES=	devel cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	LibSavitar is a c++ implementation of 3mf loading/python bindings

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>0:devel/py-sip@${PY_FLAVOR}

USES=		cmake python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
USE_GITHUB=	yes
GH_TAGNAME=	96eba0e
USE_LDCONFIG=	yes

# need this hack so as not to conflict with pugixml
# XXX TODO rework port to use pugixml instead
post-install:
	${RM} ${STAGEDIR}${PREFIX}/include/pugiconfig.hpp
	${RM} ${STAGEDIR}${PREFIX}/include/pugixml.hpp
	${RM} ${STAGEDIR}${PREFIX}/lib/cmake/pugixml/pugixml-config.cmake
	${RM} ${STAGEDIR}${PREFIX}/lib/libpugixml.a

.include <bsd.port.mk>
