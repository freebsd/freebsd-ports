PORTNAME=	libSavitar
DISTVERSION=	5.3.0
CATEGORIES=	devel cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	C++ implementation of 3mf loading/python bindings
WWW=		https://github.com/Ultimaker/libSavitar

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=0:devel/py-sip@${PY_FLAVOR}
LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++11-lang python pyqt:6 gettext-runtime
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
GH_TUPLE=       Ultimaker:pySavitar:${PORTVERSION}:pySavitar
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-extract:
	@${MKDIR} ${WRKSRC}/cmake
	@for f in COPYING-CMAKE-SCRIPTS FindSIP.cmake FindSIP.py SIPMacros.cmake; do \
		${CP} ${FILESDIR}/$$f ${WRKSRC}/cmake; \
		done
	@for f in CMakeLists.txt SavitarConfig.cmake.in; do \
		${CP} ${FILESDIR}/$$f ${WRKSRC}; \
		done
	@${CP} -r ${WRKDIR}/pySavitar-${DISTVERSION}/python ${WRKSRC}

.include <bsd.port.mk>
