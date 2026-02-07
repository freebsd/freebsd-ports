PORTNAME=	msp430-debug-stack
PORTVERSION=	3.15.1.1
PORTREVISION=	14
CATEGORIES=	devel
MASTER_SITES=	https://dr-download.ti.com/software-development/driver-or-library/MD-4vnqcP1Wk4/${PORTVERSION}/ \
		LOCAL/lev:doc1 \
		LOCAL/lev:doc2
DISTFILES=	MSPDebugStack_OS_Package_${PORTVERSION:S/./_/g}.zip \
		slau320aj.pdf:doc1 \
		slau656d.pdf:doc2
EXTRACT_ONLY=	MSPDebugStack_OS_Package_${PORTVERSION:S/./_/g}.zip

MAINTAINER=	lev@FreeBSD.org
COMMENT=	TI MSP430 debugging interface library
WWW=		http://www.ti.com/tool/mspds

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libhidapi.so:comms/hidapi

USES=		compiler:c++11-lib dos2unix gmake zip:infozip
USE_LDCONFIG=	yes

DOS2UNIX_REGEX=	.*/Makefile|.*\.(cpp|h)

MAKE_ARGS=	BOOST_DIR=${LOCALBASE} \
		HIDAPI_DIR=${LOCALBASE}

MAKE_JOBS_UNSAFE=	yes
NO_WRKSUBDIR=		yes

SUB_FILES=	pkg-message

REINPLACE_ARGS=	-i ""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC}/DLL430_v3/src/TI/DLL430 \
		\( -name '*.cpp' -o -name '*.h' \) -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|[io]fstream|std::&|; s|std::std::|std::|'
	@${REINPLACE_CMD} -e 's/-lboost_system //' ${WRKSRC}/Makefile

do-install:
	${INSTALL_LIB} ${WRKSRC}/libmsp430.so ${STAGEDIR}${PREFIX}/lib/libmsp430.so
	${INSTALL_DATA} ${WRKSRC}/libmsp430.a ${STAGEDIR}${PREFIX}/lib/libmsp430.a
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libmsp430
	${INSTALL_DATA} ${WRKSRC}/DLL430_v3/include/* ${STAGEDIR}${PREFIX}/include/libmsp430/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/slau320aj.pdf ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/slau656d.pdf ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} ${FILESDIR}/mspfet.conf.sample ${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
