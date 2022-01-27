# Handle PyQt related ports
#
# Feature:	pyqt
# Usage:	USES=pyqt:ARGS
# Valid ARGS:	5
#
# MAINTAINER:	kde@FreeBSD.org
#
# Internal Port variables for PyQt ports:
# PYQT_DIST	- This port is part of PyQt5 itself. Variables and
#		targets are then set assuming a certain tarball and
#		port layout.
# USE_PYQT	- List of PyQt components to depend on
#		* foo_build    only build depend
#		* foo_run      only run depend
#		* foo_test     only test depend
#		* foo          both (default)
# PYQT_SIPDIR	- where sip files will be installed to
# PYQT_APIDIR	- where api files will be installed to
# PYQT_DOCDIR	- where doc files will be installed to
# PYQT_EXAMPLESDIR	- where examples will be installed to

.if !defined(_INCLUDE_USES_PYQT_MK)
_INCLUDE_USES_PYQT_MK=	yes

# At the moment we support PyQt bindings versions 5, sip
# option is for internal use by the py-sip ports.
_PYQT_SUPPORTED=        5 sip

.  if empty(pyqt_ARGS)
IGNORE=	pyqt needs a qt-version (${_PYQT_SUPPORTED})
.  endif

# At the moment we support PyQt bindings versions 5
.  for ver in ${_PYQT_SUPPORTED:O:u}
.    if ${pyqt_ARGS:M${ver}}
.      if empty(_PYQT_VERSION)
_PYQT_VERSION=  ${ver}
.      else
IGNORE?=        cannot be installed: different PYQT versions specified via pyqt:[${_PYQT_SUPPORTED:S/ //g}]
.      endif
.    endif
.  endfor

.  if empty(_PYQT_VERSION)
IGNORE?=        USES=pyqt needs a version number (valid values: ${_PYQT_SUPPORTED})
_PYQT_VERSION=	0
.  endif

PYQT_MAINTAINER=	kde@FreeBSD.org

MASTER_SITE_RIVERBANK=	https://www.riverbankcomputing.com/static/Downloads/%SUBDIR%/

MASTER_SITES_SIP=	https://pypi.python.org/packages/source/s/sip/
MASTER_SITES_PYQT5=	https://pypi.python.org/packages/source/P/PyQt5/
MASTER_SITES_PYQTSIP=	https://pypi.python.org/packages/source/P/PyQt5-sip/
MASTER_SITES_PYQTCHART=	https://pypi.python.org/packages/source/P/PyQtChart/
MASTER_SITES_PYQTNETWORKAUTH=	https://pypi.python.org/packages/source/P/PyQtNetworkAuth/
MASTER_SITES_PYQTBUILDER=	https://pypi.io/packages/source/P/PyQt-builder/
MASTER_SITES_PYQTWEBENGINE=	https://pypi.python.org/packages/source/P/PyQtWebEngine/
#https://www.riverbankcomputing.com/static/Downloads/QScintilla/2.12.0/QScintilla_src-2.12.0.tar.gz
MASTER_SITES_QSCI2=	RIVERBANK/QScintilla/${PORTVERSION} \
			SF/pyqt/QScintilla2/QScintilla-${PORTVERSION} \
			GENTOO

SIP_VERSION=		6.3.1
SIP4_VERSION=		4.19.25
QSCI2_VERSION=		2.13.1
PYQT5_VERSION=		5.15.4
PYQTCHART_VERSION=	${PYQT5_VERSION} # can be different
PYQTNETWORKAUTH_VERSION=${PYQT5_VERSION}
PYQTWEBENGINE_VERSION=	${PYQT5_VERSION}
PYQTSIP_VERSION=	12.9.0
PYQTBUILDER_VERSION=	1.12.0

SIP_DISTNAME=		sip-${SIP_VERSION}
SIP4_DISTNAME=		sip-${SIP4_VERSION}
PYQT5_DISTNAME=		PyQt5-${PYQT5_VERSION}
PYQTSIP_DISTNAME=	PyQt5_sip-${PYQTSIP_VERSION}
PYQTCHART_DISTNAME=	PyQtChart-${PYQTCHART_VERSION}
PYQTNETWORKAUTH_DISTNAME=	PyQtNetworkAuth-${PYQTNETWORKAUTH_VERSION}
PYQTBUILDER_DISTNAME=	PyQt-builder-${PYQTBUILDER_VERSION}
PYQTWEBENGINE_DISTNAME=	PyQtWebEngine-${PYQTWEBENGINE_VERSION}
PYQT5_DISTINFO_FILE=	${.CURDIR:H:H}/devel/${PYQT_RELNAME}/distinfo
QSCI2_DISTNAME=		QScintilla_src-${QSCI2_VERSION}
PYQT5_LICENSE=		GPLv3

_USE_PYQT_ALL=		pyqt5 chart networkauth webengine
_USE_SIP_ALL=		sip pysip
_USE_QSCINTILLA=	qscintilla2
_USE_PYQTBUILDER=	qtbuilder

# Unversioned variables for the rest of the file
PYQT_VERSION=		${PYQT${_PYQT_VERSION}_VERSION}
PYQT_RELNAME=		py-qt${_PYQT_VERSION}
PYQT_PY_RELNAME=	${PYTHON_PKGNAMEPREFIX}qt${_PYQT_VERSION}
PYQT_MASTERSITES=	${MASTER_SITES_PYQT${_PYQT_VERSION}}
PYQT_DISTNAME=		${PYQT${_PYQT_VERSION}_DISTNAME}
PYQT_DISTINFO_FILE=	${PYQT${_PYQT_VERSION}_DISTINFO_FILE}
PYQT_LICENSE=		${PYQT${_PYQT_VERSION}_LICENSE}

# PATH
py-sip_PATH=			${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}
py-pysip_PATH=			${PYQT_PY_RELNAME}-sip>=${PYQTSIP_VERSION}
py-qscintilla2_PATH=		${PYQT_PY_RELNAME}-qscintilla2>=${QSCI2_VERSION}
py-qtbuilder_PATH=		${PYTHON_PKGNAMEPREFIX}qtbuilder>=${PYQTBUILDER_VERSION}
py-pyqt5_PATH=			${PYQT_PY_RELNAME}-pyqt>=${PYQT5_VERSION}
py-chart_PATH=			${PYQT_PY_RELNAME}-chart>=${PYQT5_VERSION}
py-networkauth_PATH=		${PYQT_PY_RELNAME}-networkauth>=${PYQT5_VERSION}
py-webengine_PATH=		${PYQT_PY_RELNAME}-webengine>=${PYQT5_VERSION}

# PORT
py-sip_PORT=			devel/py-sip
py-qtbuilder_PORT=		devel/py-qtbuilder
py-pysip_PORT=			devel/${PYQT_RELNAME}-sip
py-qscintilla2_PORT=		devel/${PYQT_RELNAME}-qscintilla2
py-positioning_PORT=		devel/${PYQT_RELNAME}-positioning
py-pyqt5_PORT=			devel/${PYQT_RELNAME}-pyqt
py-chart_PORT=			x11-toolkits/${PYQT_RELNAME}-chart
py-networkauth_PORT=		net/${PYQT_RELNAME}-networkauth
py-webengine_PORT=		www/${PYQT_RELNAME}-webengine

# The versionned executable of sip
SIP=		${LOCALBASE}/bin/sip-build-${PYTHON_VER}

# Relative directories
_VERSION_SUBDIR_REL=	PyQt${_PYQT_VERSION}/${PYTHON_VER}
_APIDIR_REL=	share/${_VERSION_SUBDIR_REL}/qsci
_DOCDIR_REL=	share/doc/${_VERSION_SUBDIR_REL}
_EXAMPLEDIR_REL=	share/examples/${_VERSION_SUBDIR_REL}
_SIPDIR_REL=		PyQt${_PYQT_VERSION}/bindings
_DESIGNERDIR_REL=	${QT_PLUGINDIR_REL}/designer/${_VERSION_SUBDIR_REL}
_QMLDIR_REL=		${QT_QMLDIR_REL}/${_VERSION_SUBDIR_REL}

# Absolute directories
PYQT_APIDIR=		${PREFIX}/${_APIDIR_REL}
PYQT_DOCDIR=		${PREFIX}/${_DOCDIR_REL}
PYQT_EXAMPLEDIR=	${PREFIX}/${_EXAMPLEDIR_REL}
PYQT_SIPDIR?=		${PYTHON_SITELIBDIR}/${_SIPDIR_REL}
PYQT_DESIGNERDIR=	${PREFIX}/${_DESIGNERDIR_REL}
PYQT_QMLDIR=		${PREFIX}/${_QMLDIR_REL}

PLIST_SUB+=	PYQT_APIDIR=${_APIDIR_REL} \
		PYQT_DOCDIR=${_DOCDIR_REL} \
		PYQT_EXAMPLEDIR=${_EXAMPLEDIR_REL} \
		PYQT_SIPDIR=${PYQT_SIPDIR} \
		PYQT_DESIGNERDIR=${_DESIGNERDIR_REL} \
		PYQT_QMLDIR=${_QMLDIR_REL} \
		PYQT_SIPVERSION=${SIP_VERSION} \
		PYQT_QSCIVERSION=${QSCI2_VERSION} \
		PYQT_PYQTVERSION=${PYQT_VERSION}

.  if defined(PYQT_DIST)

PLIST_SUB+=	PYTHON_MAJOR_VER="${PYTHON_MAJOR_VER}"

SIP_ARGS=	--qmake ${QMAKE} \
		--verbose \
		--no-make \
		--build-dir build \
		--protected-is-public \
		--api-dir ${PYQT_APIDIR}
.	if ${PORTNAME} == "pyqt"
SIP_ARGS+=	--confirm-license
.	endif

.  if ${PORTNAME} == "pyqt"
.    if !target(post-patch)
post-patch:
	${REINPLACE_CMD} -e "s#%%PYQT_DESIGNERDIR%%#${PYQT_DESIGNERDIR}#" ${WRKSRC}/project.py
	${REINPLACE_CMD} -e "s#%%PYQT_QMLDIR%%#${PYQT_QMLDIR}#" ${WRKSRC}/project.py
.    endif  # !target(post-patch)
.  endif

.    if !target(do-build)
do-build:
	(cd ${WRKSRC}; ${SIP} ${SIP_ARGS}; ${MAKE} -C ./build)

.    endif  # !target(do-build)

.    if !target(do-install)
do-install:
	(cd ${WRKSRC} ; ${MAKE} -C ./build install INSTALL_ROOT=${STAGEDIR} )
.    endif  # !target(do-install)

.  endif  # defined(PYQT_DIST)

# Set build, run and test depends -- we need to prefix them internally with "py-"
# else we conflict with the ones defined in bsd.qt.mk with the same name
_USE_PYQT_ALL+=				${_USE_SIP_ALL} \
					${_USE_QSCINTILLA} \
					${_USE_PYQTBUILDER}
.  for comp in ${_USE_PYQT_ALL:O:u}
_USE_PYQT_ALL_SUFFIXED+=		py-${comp} py-${comp}_build py-${comp}_run py-${comp}_test
py-${comp}_BUILD_DEPENDS?=		${py-${comp}_PATH}:${py-${comp}_PORT}@${PY_FLAVOR}
py-${comp}_RUN_DEPENDS?=		${py-${comp}_PATH}:${py-${comp}_PORT}@${PY_FLAVOR}
py-${comp}_TEST_DEPENDS?=		${py-${comp}_PATH}:${py-${comp}_PORT}@${PY_FLAVOR}
py-${comp}_build_BUILD_DEPENDS?=	${py-${comp}_BUILD_DEPENDS}
py-${comp}_run_RUN_DEPENDS?=		${py-${comp}_RUN_DEPENDS}
py-${comp}_test_TEST_DEPENDS?=		${py-${comp}_TEST_DEPENDS}
.  endfor

_USE_PYQT=      ${USE_PYQT:O:u}
.  for comp in ${_USE_PYQT}
.    if ${_USE_PYQT_ALL_SUFFIXED:Mpy-${comp}}
BUILD_DEPENDS+=		${py-${comp}_BUILD_DEPENDS}
RUN_DEPENDS+=		${py-${comp}_RUN_DEPENDS}
TEST_DEPENDS+=		${py-${comp}_TEST_DEPENDS}
.    else
IGNORE?=	cannot be installed: unknown USE_PYQT component ${comp} #'
.    endif
.  endfor

.endif # defined(_INCLUDE_USES_PYQT_MK)
