# Created by: Vitaly Magerya <vmagerya@gmail.com>
# $FreeBSD$

PORTNAME=	premake4
PORTVERSION=	4.3
CATEGORIES=	devel
MASTER_SITES=	SF/premake/Premake/${PORTVERSION}
DISTNAME=	premake-${PORTVERSION}-src
EXTRACT_SUFX=	.zip

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Writes build scripts

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/premake-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/build/gmake.unix

USES=		gmake
MAKE_ARGS=	ARCH=""

PLIST_FILES=	bin/premake4

PORTDOCS=	CHANGES.txt LICENSE.txt README.txt

post-patch:
	${REINPLACE_CMD} -e 's|-ldl||' ${BUILD_WRKSRC}/Premake4.make
	${REINPLACE_CMD} -e 's|debug|release|' ${WRKSRC}/tests/test

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/premake4 ${STAGEDIR}${PREFIX}/bin

regression-test: build
	cd ${WRKSRC}/tests && ./test

.include <bsd.port.mk>
