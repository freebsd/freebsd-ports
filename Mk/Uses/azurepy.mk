# $FreeBSD$
#
# Shared namespace for py-azure-* ports
# Feature:	azurepy
# Usage:	USES=	azurepy
# MAINTAINER:	dbaio@FreeBSD.org

.if !defined(_INCLUDE_USES_AZUREPY_MK)
_INCLUDE_USES_AZUREPY_MK=	yes

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}azure-cli-base>=0:sysutils/py-azure-cli-base@${PY_FLAVOR}

POST_PLIST=	trim-azure-namespace

_USES_install+=	701:remove-common-files
remove-common-files:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/azure/__init__.py* \
		${STAGEDIR}${PYTHON_SITELIBDIR}/azure/cli/__init__.py* \
		${STAGEDIR}${PYTHON_SITELIBDIR}/azure/cli/command_modules/__init__.py* \
		${STAGEDIR}${PYTHON_SITELIBDIR}/azure/mgmt/__init__.py* \
		${STAGEDIR}${PYTHON_SITELIBDIR}/azure/mgmt/datalake/__init__.py*
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/azure/__pycache__ \
		${STAGEDIR}${PYTHON_SITELIBDIR}/azure/cli/__pycache__ \
		${STAGEDIR}${PYTHON_SITELIBDIR}/azure/cli/command_modules/__pycache__ \
		${STAGEDIR}${PYTHON_SITELIBDIR}/azure/mgmt/__pycache__ \
		${STAGEDIR}${PYTHON_SITELIBDIR}/azure/mgmt/datalake/__pycache__

trim-azure-namespace:
	@${REINPLACE_CMD} -e '/azure\/__init__.py*/d' \
		-e '/azure\/cli\/__init__.py*/d' \
		-e '/azure\/cli\/command_modules\/__init__.py*/d' \
		-e '/azure\/mgmt\/__init__.py*/d' \
		-e '/azure\/mgmt\/datalake\/__init__.py*/d' \
		-e '/azure\/__pycache__*/d' \
		-e '/azure\/cli\/__pycache__*/d' \
		-e '/azure\/cli\/command_modules\/__pycache__*/d' \
		-e '/azure\/mgmt\/__pycache__*/d' \
		-e '/azure\/mgmt\/datalake\/__pycache__*/d' \
		${TMPPLIST}

.endif
