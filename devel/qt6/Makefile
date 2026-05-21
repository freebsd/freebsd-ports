PORTNAME=	qt6
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform application and UI framework (metaport)
WWW=		https://www.qt.io/

USES=		metaport qt:6
USE_QT=		${_USE_QT_ALL:S/$/:run/}

# Macro to generate a list of all Qt port origins (stripping flavors)
# and to sort by category for helper update targets.
_UNIQUE_QT_PORTS= \
	for component in $$(${MAKE} -V_USE_QT_ALL); do \
	    ${MAKE} -Vqt-$${component}_PORT; \
	done | ${TR} ' ' '\n' | ${SED} -e '/^$$/d' -e 's|@.*||' | ${SORT} -u

# Redirect the standard 'makesum' target so if run in this directory, it doesn't
# create a bogus 'distinfo' file with just a timestamp.
makesum: qt-update-distinfo

# Update distinfo for all Qt components. devel/qt6-openapi needs a second pass
# after the main distfile is downloaded and the maven deps are created.
qt-update-distinfo:
	@${ECHO_CMD} "===> Updating distinfo for all Qt components..."; \
	unique_qt_ports=$$(${_UNIQUE_QT_PORTS}); \
	for port in $$unique_qt_ports; do \
	    if [ "$${port}" = "devel/qt${_QT_VER}-openapi" ]; then \
		${MAKE} -C ${.CURDIR:H:H}/$${port} -DDISABLE_LICENSES -DQTOPENAPI_MAINTAINER_MODE makesum qtopenapi-create-maven-deps; \
	    fi; \
	    ${MAKE} -C ${.CURDIR:H:H}/$${port} -DDISABLE_LICENSES makesum; \
	done

# Reset PORTREVISION for all Qt components.
qt-reset-portrevision:
	@${ECHO_CMD} "===> Resetting PORTREVISION for Qt components..."; \
	unique_qt_ports=$$(${_UNIQUE_QT_PORTS}); \
	for port in $$unique_qt_ports; do \
	    if [ "$${port}" = "print/qt${_QT_VER}-pdf" ]; then \
		${SED} -i "" -E -e 's|(^PORTREVISION\=[[:blank:]])[0-9]+|\10|' ${.CURDIR:H:H}/$${port}/Makefile; \
	    elif [ "$${port}" = "www/qt${_QT_VER}-webengine" ]; then \
		${SED} -i "" -E -e 's|(^PORTREVISION\?=[[:blank:]])[0-9]+|\10|' ${.CURDIR:H:H}/$${port}/Makefile; \
	    else \
		${SED} -i "" -e '/^PORTREVISION=/d' ${.CURDIR:H:H}/$${port}/Makefile; \
	    fi \
	done

# Check patches for all but the pdf and webengine components
# webengine and child port pdf need special care and their update
# script is not yet integrated.
qt-check-patches:
	@failed_qt_ports=""; \
	${ECHO_CMD} "===> Checking patches for Qt components..."; \
	unique_qt_ports=$$(${_UNIQUE_QT_PORTS}); \
	for port in $$unique_qt_ports; do \
	    if [ "$${port}" = "print/qt${_QT_VER}-pdf" ] || [ "$${port}" = "www/qt${_QT_VER}-webengine" ]; then \
		${PRINTF} "===>  Skipping heavy port: %-38s [SKIP]\n" "$${port}"; \
		continue; \
	    fi; \
	    if [ ! -d "${.CURDIR:H:H}/$${port}/files" ]; then \
		${PRINTF} "===>  Skipping patchless port: %-34s [SKIP]\n" "$${port}"; \
		continue; \
	    fi; \
	    ${PRINTF} "===>  Testing patches for %-39s " "$${port}"; \
	    ${MAKE} -C ${.CURDIR:H:H}/$${port} clean >/dev/null 2>&1; \
	    tmp_log=$$(${MKTEMP} -t qt_patch); \
	    if ! ${MAKE} -C ${.CURDIR:H:H}/$${port} -DDISABLE_LICENSES -DPATCH_CONTINUE_ON_FAIL=yes patch > "$$tmp_log" 2>&1; then \
		${ECHO_CMD} "[FAIL]"; \
		bad_patches=$$(${AWK} '/FAILED Applying/ {printf "%s,", $$NF}' "$$tmp_log" | ${SED} 's/,$$//'); \
		failed_qt_ports="$${failed_qt_ports} $${port}:$$bad_patches"; \
	    else \
		${ECHO_CMD} "[OK]"; \
		${MAKE} -C ${.CURDIR:H:H}/$${port} clean >/dev/null 2>&1; \
	    fi; \
	    ${RM} -f "$$tmp_log"; \
	done; \
	if [ ! -z "$$failed_qt_ports" ]; then \
	    ${ECHO_CMD} "[FAIL] The following ports require manual repair/removal of the listed patches:"; \
	    for f in $$failed_qt_ports; do \
		failed_qt_port="$${f%%:*}"; \
		failed_qt_patches="$$(${ECHO_CMD} "$${f#*:}" | ${TR} ',' ' ')"; \
		${PRINTF} "  - %s\n" "$$failed_qt_port"; \
		for p in $$failed_qt_patches; do \
		    ${PRINTF} "      * %s\n" "$$p"; \
		done; \
	    done; \
	    exit 1; \
	fi

qt-update-all: qt-reset-portrevision qt-update-distinfo qt-check-patches

.include <bsd.port.mk>
