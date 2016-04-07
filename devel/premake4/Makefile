# Created by: Vitaly Magerya <vmagerya@gmail.com>
# $FreeBSD$

PORTNAME=	premake4
PORTVERSION=	4.4.b5
CATEGORIES=	devel
MASTER_SITES=	SF/premake/Premake/${PORTVERSION:C/.b.+//}
DISTNAME=	premake-${PORTVERSION:S/.b/-beta/}-src

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Build script creation tool

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/premake-${PORTVERSION:S/.b/-beta/}
BUILD_WRKSRC=	${WRKSRC}/build/gmake.unix

USES=		gmake zip
MAKE_ARGS=	ARCH="" CC="${CC}" CXX="${CXX}"

PLIST_FILES=	bin/premake4

PORTDOCS=	CHANGES.txt LICENSE.txt README.txt

MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|-ldl||' ${BUILD_WRKSRC}/Premake4.make
	${REINPLACE_CMD} -e 's|debug|release|' \
		${WRKSRC}/tests/test \
		${WRKSRC}/tests/base/test_premake_command.lua
	${REINPLACE_CMD} -e 's|io.open(conf_file)|nil|' \
		${WRKSRC}/src/base/os.lua \
		${WRKSRC}/src/host/scripts.c

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} \
		${WRKSRC}/bin/release/premake4 ${STAGEDIR}${PREFIX}/bin

regression-test: build
	cd ${WRKSRC}/tests && ./test

.include <bsd.port.mk>
