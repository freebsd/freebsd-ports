# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	rapidjson
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel textproc

MAINTAINER=	yuri@rawbw.com
COMMENT=	Fast JSON parser/generator for C++ with both SAX/DOM style API

LICENSE=	unknown
LICENSE_NAME=	RapidJSON
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

BROKEN_powerpc64=	Does not build

USE_GITHUB=	yes
GH_ACCOUNT=	miloyip

USES=		cmake gmake

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_DEFAULT=${OPTIONS_DEFINE}
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|LIB_INSTALL_DIR}/pkgconfig"|CMAKE_INSTALL_PREFIX}/libdata/pkgconfig"|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|DOC_INSTALL_DIR}/examples"|CMAKE_INSTALL_PREFIX}/share/examples/${PORTNAME}"|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/example/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/test/unittest/CMakeLists.txt

post-stage:
	@${RM} -rf ${STAGEDIR}${EXAMPLESDIR}/CMakeFiles

.include <bsd.port.mk>
