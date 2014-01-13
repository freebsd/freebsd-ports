# $FreeBSD$

PORTNAME=	declarative
PORTVERSION=	${PYQT4_VERSION}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, QtDeclarative module

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${PKGNAMEPREFIX}gui>=${PYQT4_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PKGNAMEPREFIX}network>=${PYQT4_VERSION}:${PORTSDIR}/net/py-qt4-network

DISTINFO_FILE=	${PYQT4_DISTINFO_FILE}
HAS_CONFIGURE=	yes
USE_PYTHON=	yes
USE_QT4=	declarative qmake_build moc_build

OPTIONS_DEFINE=	API
OPTIONS_DEFAULT=API
API_DESC=	Install QtDeclarative API for QScintilla2

PATCHDIR=	${.CURDIR}/../py-qt4-core/files
OPTIONSFILE?=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
SIPDIR=		${PREFIX}/share/py-sip
QSCIDIR=	${PREFIX}/share/qt4/qsci
ARGS=		-b ${PREFIX}/bin \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-p ${PREFIX}/${QT_PLUGINDIR_REL} \
		-q ${QMAKE} \
		--confirm-license \
		--sipdir ${SIPDIR} \
		--enable QtDeclarative \
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

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}\
		${PYTHON_CMD} configure.py ${ARGS}

post-configure:
	${REINPLACE_CMD} -e 's|^CC.*|CC = ${CC}|' \
		-e 's|^CXX.*|CXX = ${CXX}|' \
		-e 's|^LINK.*|LINK = ${CXX}|' \
		-e 's|^CFLAGS|CXXFLAGS|' \
		${WRKSRC}/qpy/QtDeclarative/Makefile

.include <bsd.port.mk>
