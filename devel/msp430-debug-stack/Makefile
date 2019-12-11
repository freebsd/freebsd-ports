# $FreeBSD$

PORTNAME=	msp430-debug-stack
PORTVERSION=	3.12.000.004
PORTREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	http://www.ti.com/lit/sw/slac460x/ \
		http://www.ti.com/lit/ug/slau320ac/:doc1 \
		http://www.ti.com/lit/ug/slau656b/:doc2
DISTFILES=	slac460x.zip \
		slau320ac.pdf:doc1 \
		slau656b.pdf:doc2
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	slac460x.zip

MAINTAINER=	lev@FreeBSD.org
COMMENT=	TI MSP430 debugging interface library

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

do-install:
	${INSTALL_LIB} ${WRKSRC}/libmsp430.so ${STAGEDIR}${PREFIX}/lib/libmsp430.so
	${INSTALL_DATA} ${WRKSRC}/libmsp430.a ${STAGEDIR}${PREFIX}/lib/libmsp430.a
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libmsp430
	${INSTALL_DATA} ${WRKSRC}/DLL430_v3/include/* ${STAGEDIR}${PREFIX}/include/libmsp430/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/slau320ac.pdf ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/slau656b.pdf ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} ${FILESDIR}/mspfet.conf ${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
