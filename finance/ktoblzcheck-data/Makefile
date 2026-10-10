PORTNAME=	ktoblzcheck
PORTVERSION=	1.0.0.${BANKDATA_START_DATE}
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME} \
		LOCAL/jhale/${PORTNAME}:bankdata
PKGNAMESUFFIX=	-data
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-${KBCD_DATE}${EXTRACT_SUFX} \
		${BANKDATA_DISTFILE}:bankdata

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
# supported. Do not edit manually, unless you really know what you are doing!
# Run `make ktoblzcheck-data-update` to update this value automatically.
BANKDATA_START_DATE=	20260907
# Custom: This is the date when the bank data is officially void and can no
# longer be relied upon. Do not edit manually, unless you really know what you
# are doing! Run `make ktoblzcheck-data-update` to update this value
# automatically.
BANKDATA_END_DATE=	20261206
# Custom: Raw distfile name for the bank data.
BANKDATA_DISTFILE=	${PORTNAME}-bankdata-${BANKDATA_START_DATE}${EXTRACT_SUFX}

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

# Custom target to check for python mods needed by ktoblzcheck-data-update.py.
# This is a helper, since the FreeBSD ports infrastructure doesn't currently
# have a built-in method to deal with dependencies required by custom targets.
ktoblzcheck-data-update-py-mod-check:
	@for mod in "bs4,beautifulsoup" "requests,requests"; do \
	    IFS=","; \
	    set -- $${mod}; \
	    if ! ${PYTHON_CMD} -c "import $${1}" 2>/dev/null; then \
		${ECHO_MSG} "====> Error: Missing Python module $${1}. Please install it: \`pkg install ${PYTHON_PKGNAMEPREFIX}$${2}\`"; \
		exit 1; \
	    else \
		${ECHO_MSG} "====> Found Python module $${1}"; \
	    fi \
	done

# Custom target to create a new distfile, edit the 'BANKDATA_START_DATE' and
# 'BANKDATA_END_DATE' variables in this Makefile, and update distinfo.
ktoblzcheck-data-update: ktoblzcheck-data-update-py-mod-check
	${PYTHON_CMD} ${FILESDIR}/${@}.py -m ${.CURDIR}/Makefile -o ${DISTDIR} -s ${EXTRACT_SUFX}
	${MAKE} -C ${.CURDIR} makesum
	@${ECHO_CMD} "====> Don't forget to upload the distfile to freefall after verifying:"
	@${ECHO_CMD} "====> \`${MAKE} -C ${.CURDIR} ktoblzcheck-data-upload\`"

# Custom target to upload the new distfile to freefall. This only works for
# FreeBSD committers with access to freefall. Manually verify the distfile
# before running this target!!!
ktoblzcheck-data-upload:
	@if [ -f ${DISTDIR}/${BANKDATA_DISTFILE} ]; then \
	    ssh freefall.freebsd.org "${MKDIR} public_distfiles/${PORTNAME}"; \
	    scp ${DISTDIR}/${BANKDATA_DISTFILE} freefall.FreeBSD.org:public_distfiles/${PORTNAME}/; \
	else \
	    ${ECHO_CMD} "====> Error: distfile ${DISTDIR}/${BANKDATA_DISTFILE} not found."; \
	    ${ECHO_CMD} "====> Run \`${MAKE} -C ${.CURDIR} ktoblzcheck-data-update\` first."; \
	    exit 1; \
	fi

.include <bsd.port.mk>
