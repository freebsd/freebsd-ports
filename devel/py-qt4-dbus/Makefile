# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	dbus
PORTVERSION=	${PYQT4_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, QtDBus module

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}dbus>=0.8:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.8:${PORTSDIR}/devel/py-dbus \
		${PKGNAMEPREFIX}core>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-core

DISTINFO_FILE=	${PYQT4_DISTINFO_FILE}
HAS_CONFIGURE=	yes
USE_PYTHON=	yes
USE_QT4=	dbus moc_build qmake_build

OPTIONS_DEFINE=	API
OPTIONS_DEFAULT=API
API_DESC=	Install QtDBus API for QScintilla2

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
		--enable QtDBus \
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
		${WRKSRC}/qpy/QtDBus/Makefile

.include <bsd.port.mk>
