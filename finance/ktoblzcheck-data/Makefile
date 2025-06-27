PORTNAME=	ktoblzcheck
PORTVERSION=	1.0.0.${BANKDATA_START_DATE}
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME} \
		LOCAL/jhale/${PORTNAME}:bankdata
PKGNAMESUFFIX=	-data
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-${KBCD_DATE}${EXTRACT_SUFX} \
		${PORTNAME}-bankdata-${BANKDATA_START_DATE}${EXTRACT_SUFX}:bankdata

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Bank data used by ktoblzcheck
WWW=		https://ktoblzcheck.sourceforge.net/

# Project does not specify a license for the resulting databases, but the data
# files it processes are in the public domain.
LICENSE=	PD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>0:textproc/py-openpyxl@${PY_FLAVOR}

USES=		cmake python:build

CMAKE_ARGS=	-DDATA_FILEPATH_sepa:PATH="../data/sepa_${BANKDATA_START_DATE}.txt"
CMAKE_ON=	INSTALL_RAW_BANKDATA_FILE \
		INSTALL_SEPA_BANKDATA_FILE
CMAKE_OFF=	ENABLE_BANKDATA_DOWNLOAD

WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${KBCD_DATE}

PLIST_SUB=	BANKDATA_START_DATE=${BANKDATA_START_DATE}

# Custom: Upstream ships a dated a distfile, but will most likely not contain
# the most recent bank data. This is just used for build system changes.
KBCD_DATE=		20250515
# Custom: This is the date when the bank data is officially recocognized and
# supported.
BANKDATA_START_DATE=	20250609
# Custom: This is the date when the bank data is officially void and can no
# longer be relied upon.
BANKDATA_END_DATE=	20250907

post-extract:
# Out of an abundance of caution, remove the pre-built DBs and shipped SEPA data.
	(cd ${WRKSRC}/data && ${RM} bankdata* sepa*)
# Populate ${WRKSRC}/data with the contents of our bankdata archive.
.for f in blz_${BANKDATA_START_DATE}.txt ch_data.txt nl_data.xlsx sepa_${BANKDATA_START_DATE}.txt
	${CP} ${WRKDIR}/${PORTNAME}-bankdata-${BANKDATA_START_DATE}/${f} ${WRKSRC}/data
.endfor

post-patch:
# See comment in files/patch-src_CMakeLists.txt.
	@${REINPLACE_CMD} -e 's|%%BANKDATA_END_DATE%%|'"$$(date -j -f "%Y%m%d" "+%d.%m.%Y" ${BANKDATA_END_DATE})"'|' \
		${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
