PORTNAME=	ktoblzcheck
PORTVERSION=	1.57
PORTREVISION=	1
CATEGORIES=	finance german
MASTER_SITES=	SF/${PORTNAME} \
		LOCAL/jhale/${PORTNAME}:bankdata
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-bankdata-${BANKDATA_DATE}${EXTRACT_SUFX}:bankdata

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Check bank codes of German banks
WWW=		https://ktoblzcheck.sourceforge.net/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>0:textproc/py-openpyxl@${PY_FLAVOR}
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake localbase pathfix python:build sqlite
USE_LDCONFIG=	yes

CMAKE_OFF=	ENABLE_BANKDATA_DOWNLOAD \
		INSTALL_RAW_BANKDATA_FILE

PORTDOCS=	README.md

BANKDATA_DATE=	20240603

OPTIONS_DEFINE=	DOCS DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen \
				dot:graphics/graphviz
DOXYGEN_CMAKE_BOOL_OFF=		CMAKE_DISABLE_FIND_PACKAGE_Doxygen

TEST_TARGET=			test

post-patch:
	@${CP} ${WRKDIR}/${PORTNAME}-bankdata-${BANKDATA_DATE}/blz_${BANKDATA_DATE}.txt ${WRKSRC}/src/bankdata
	@${CP} ${WRKDIR}/${PORTNAME}-bankdata-${BANKDATA_DATE}/ch_data.txt ${WRKSRC}/src/bankdata
	@${CP} ${WRKDIR}/${PORTNAME}-bankdata-${BANKDATA_DATE}/nl_data.xlsx ${WRKSRC}/src/bankdata
	@${CP} ${WRKDIR}/${PORTNAME}-bankdata-${BANKDATA_DATE}/sepa_${BANKDATA_DATE}.txt ${WRKSRC}/src/bankdata/sepa
	@${REINPLACE_CMD} -e 's|%%BANKDATA_DATE%%|'"$$(date -j -f "%Y%m%d" "+%d.%m.%Y" ${BANKDATA_DATE})"'|' \
		${WRKSRC}/src/bankdata/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
