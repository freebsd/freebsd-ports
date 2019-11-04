# $FreeBSD$

PORTNAME=	qscintilla2
PORTVERSION=	${QSCI2_VERSION}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_QSCI2}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt5-
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for QScintilla2 (PyQt5), QSci module

LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5

DISTINFO_FILE=	${.CURDIR:H}/qscintilla2-qt5/distinfo
DESTDIRNAME=	INSTALL_ROOT

HAS_CONFIGURE=	yes

USES=		python pyqt:5 gl qmake:no_env qt:5
USE_GL=		gl
USE_PYQT=	sip core gui printsupport widgets
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core gui printsupport widgets buildtools_build qmake_build

OPTIONS_DEFINE=		DEBUG
DEBUG_CONFIGURE_ON=	--debug --trace

QSCIDIR=	${PREFIX}/share/qt5/qsci
CONFIGURE_ARGS=	--pyqt PyQt5 -d ${PYTHONPREFIX_SITELIBDIR}/PyQt5 -v ${PYQT_SIPDIR} \
		--apidir ${PYQT_APIDIR} --qmake ${QMAKE} --pyqt-sipdir ${PYQT_SIPDIR} \
		--sip ${SIP}
WRKSRC=		${WRKDIR}/${DISTNAME}/Python
ALL_TARGET=	#empty

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}\
		${PYTHON_CMD} configure.py ${CONFIGURE_ARGS}

.include <bsd.port.mk>
