# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	core
PORTVERSION=	${PYQT4_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, QtCore module

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip
RUN_DEPENDS:=	${BUILD_DEPENDS}

DISTINFO_FILE=	${PYQT4_DISTINFO_FILE}
HAS_CONFIGURE=	yes
USE_PYTHON=	yes
USE_QT4=	corelib qmake_build moc_build

OPTIONS_DEFINE=	API
OPTIONS_DEFAULT=API
API_DESC=	Install QtCore API for QScintilla2

OPTIONSFILE?=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
SIPDIR=		${PREFIX}/share/py-sip
QSCIDIR=	${PREFIX}/share/qt4/qsci
ARGS=		-b ${PREFIX}/bin \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-p ${PREFIX}/${QT_PLUGINDIR_REL} \
		-q ${QMAKE} \
		--confirm-license \
		--sipdir ${SIPDIR} \
		--enable QtCore \
		CC="${CC}" CXX="${CXX}" LINK="${CXX}" LINK_SHLIB="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"

.include "${.CURDIR}/../py-qt4/bsd.pyqt.mk"
.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MAPI)
ARGS+=		--no-qsci-api
PLIST_SUB+=	API="@comment "
.else
LIB_DEPENDS+=	qscintilla2:${PORTSDIR}/devel/qscintilla2
ARGS+=		--qsci-api --qsci-api-destdir=${QSCIDIR}
PLIST_SUB+=	API=""
.endif

.if defined(WITH_DEBUG)
ARGS+=		--debug --trace
.endif

post-patch:
	${RM} -rf ${WRKSRC}/pyuic/uic/port_v3

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}\
		${PYTHON_CMD} configure.py ${ARGS}

post-configure:
	${REINPLACE_CMD} -e 's|^CC.*|CC = ${CC}|' \
		-e 's|^CXX.*|CXX = ${CXX}|' \
		-e 's|^LINK.*|LINK = ${CXX}|' \
		-e 's|^CFLAGS|CXXFLAGS|' \
		${WRKSRC}/qpy/QtCore/Makefile

post-install:
	${INSTALL_DATA} ${FILESDIR}/Qt.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt4 &&\
		cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt4 &&\
		${PYTHON_CMD} ${PYTHON_LIBDIR}/py_compile.py\
		`ls *.py */*.py */*/*.py` &&\
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/py_compile.py\
		`ls *.py */*.py */*/*.py`

.include <bsd.port.mk>
