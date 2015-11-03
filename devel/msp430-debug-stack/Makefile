# $FreeBSD$

PORTNAME=	msp430-debug-stack
PORTVERSION=	3.05.01.01
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.ti.com/lit/sw/slac460n/ \
		http://www.ti.com/lit/ug/slau320u/:doc1 \
		http://www.ti.com/lit/ug/slau656/:doc2
DISTFILES=	slac460n.zip \
		slau320u.pdf:doc1 \
		slau656.pdf:doc2
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	slac460n.zip

MAINTAINER=	lev@FreeBSD.org
COMMENT=	TI MSP430 debugging interface library

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libhidapi.so:${PORTSDIR}/comms/hidapi

USES=		compiler:c++11-lib gmake zip:infozip
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/MSPDebugStack_OS_Package

MAKE_ARGS+=	BOOST_DIR=${LOCALBASE} \
		HIDAPI_DIR=${LOCALBASE}

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_LIB} ${WRKSRC}/libmsp430.so ${STAGEDIR}${PREFIX}/lib/libmsp430.so
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libmsp430
	${INSTALL_DATA} ${WRKSRC}/DLL430_v3/include/* ${STAGEDIR}${PREFIX}/include/libmsp430/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/slau320u.pdf ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/slau656.pdf ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
