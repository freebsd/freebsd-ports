# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	qscintilla2
PORTVERSION=	${QSCI2_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_QSCI2}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for QScintilla2 (PyQt4), QSci module

LIB_DEPENDS=	qscintilla2:${PORTSDIR}/devel/qscintilla2
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT_VERSION}:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui
RUN_DEPENDS:=	${BUILD_DEPENDS}

DISTINFO_FILE=	${QSCI2_DISTINFO_FILE}
HAS_CONFIGURE=	yes
USE_PYTHON=	2.5+
USE_QT4=	gui

OPTIONS_DEFINE=	API
OPTIONS_DEFAULT=API
API_DESC=	Install binding API for QScintilla2

OPTIONSFILE?=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
SIPDIR=		${PREFIX}/share/py-sip
QSCIDIR=	${PREFIX}/share/qt4/qsci
ARGS=		-p 4 -d ${PYTHONPREFIX_SITELIBDIR}/PyQt4 -v ${SIPDIR}
WRKSRC=		${WRKDIR}/${DISTNAME}/Python
ALL_TARGET=	#empty

.include "${.CURDIR}/../py-qt4/bsd.pyqt.mk"
.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MAPI)
ARGS+=		-a /dev/null
PLIST_SUB+=	API="@comment "
.else
ARGS+=		-a ${QSCIDIR}
PLIST_SUB+=	API=""
.endif

.if defined(WITH_DEBUG)
ARGS+=		-u -r
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}\
		${PYTHON_CMD} configure.py ${ARGS}

.include <bsd.port.mk>
