# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	qscintilla2
PORTVERSION=	${QSCI2_VERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_QSCI2}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for QScintilla2 (PyQt4), QSci module

LIB_DEPENDS=	libqscintilla2.so:${PORTSDIR}/devel/qscintilla2
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT_VERSION}:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui
RUN_DEPENDS:=	${BUILD_DEPENDS}

DESTDIRNAME=	INSTALL_ROOT
DISTINFO_FILE=	${QSCI2_DISTINFO_FILE}
HAS_CONFIGURE=	yes
USE_PYTHON=	yes
USE_QT4=	gui moc_build qmake_build
QT_NONSTANDARD=	yes  # Do not add unknown arguments to CONFIGURE_ARGS.

OPTIONS_DEFINE=		DEBUG
DEBUG_CONFIGURE_ON=	--debug --trace

OPTIONSFILE?=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
SIPDIR=		${PREFIX}/share/py-sip
QSCIDIR=	${PREFIX}/share/qt4/qsci
CONFIGURE_ARGS=	--pyqt PyQt4 -d ${PYTHONPREFIX_SITELIBDIR}/PyQt4 -v ${SIPDIR} \
		--apidir ${QSCIDIR} --qmake ${QMAKE} --pyqt-sipdir ${SIPDIR}
WRKSRC=		${WRKDIR}/${DISTNAME}/Python
ALL_TARGET=	#empty

.include "${.CURDIR}/../py-qt4/bsd.pyqt.mk"

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}\
		${PYTHON_CMD} configure.py ${CONFIGURE_ARGS}

.include <bsd.port.mk>
