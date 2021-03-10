# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ktoblzcheck
PORTVERSION=	1.53
PORTREVISION=	2
CATEGORIES=	finance german
MASTER_SITES=	SF/${PORTNAME} \
		LOCAL/jhale:bankdata
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-bankdata-${BANKDATA_DATE}${EXTRACT_SUFX}:bankdata

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Check bank codes of German banks

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake pathfix python:3.6+,build
USE_LDCONFIG=	yes

CMAKE_ON=	INSTALL_RAW_BANKDATA_FILE
CMAKE_OFF=	ENABLE_BANKDATA_DOWNLOAD

PLIST_SUB=	BANKDATA_DATE=${BANKDATA_DATE}
PORTDOCS=	README.md

BANKDATA_DATE=	20210308

OPTIONS_DEFINE=	DOCS DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen \
				dot:graphics/graphviz
DOXYGEN_CMAKE_BOOL_OFF=		CMAKE_DISABLE_FIND_PACKAGE_Doxygen

TEST_TARGET=			test

post-patch:
	@${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_DATADIR}\/man|$${CMAKE_INSTALL_MANDIR}|' ${WRKSRC}/doc/CMakeLists.txt
	@(cd ${WRKSRC}/src/bankdata && ${RM} bankdata_*.txt blz_*.txt)
	@${CP} ${WRKDIR}/${PORTNAME}-bankdata-${BANKDATA_DATE}/blz_${BANKDATA_DATE}.txt ${WRKSRC}/src/bankdata
	@${TOUCH} ${WRKSRC}/src/bankdata/bankdata_${BANKDATA_DATE}.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
