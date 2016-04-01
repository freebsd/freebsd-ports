# $FreeBSD$

PORTNAME=	msp430-debug-stack
PORTVERSION=	3.05.01.01
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.ti.com/lit/sw/slac460n/ \
		http://www.ti.com/lit/ug/slau320v/:doc1 \
		http://www.ti.com/lit/ug/slau656/:doc2
DISTFILES=	slac460n.zip \
		slau320v.pdf:doc1 \
		slau656.pdf:doc2
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	slac460n.zip

MAINTAINER=	lev@FreeBSD.org
COMMENT=	TI MSP430 debugging interface library

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libhidapi.so:comms/hidapi

BROKEN_FreeBSD_9=	does not build (internal compiler error)

USES=		compiler:c++11-lib dos2unix gmake zip:infozip
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/MSPDebugStack_OS_Package
DOS2UNIX_REGEX=	.*\.(cpp|h)

MAKE_ARGS+=	BOOST_DIR=${LOCALBASE} \
		HIDAPI_DIR=${LOCALBASE}

MAKE_JOBS_UNSAFE=	yes

SUB_FILES+=	pkg-message

REINPLACE_ARGS=	-i ""

post-patch:
	@${FIND} ${WRKSRC}/DLL430_v3/src/TI/DLL430 \
		\( -name '*.cpp' -o -name '*.h' \) -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|[io]fstream|std::&|; s|std::std::|std::|'

do-install:
	${INSTALL_LIB} ${WRKSRC}/libmsp430.so ${STAGEDIR}${PREFIX}/lib/libmsp430.so
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libmsp430
	${INSTALL_DATA} ${WRKSRC}/DLL430_v3/include/* ${STAGEDIR}${PREFIX}/include/libmsp430/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/slau320v.pdf ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/slau656.pdf ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} ${FILESDIR}/mspfet.conf ${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
