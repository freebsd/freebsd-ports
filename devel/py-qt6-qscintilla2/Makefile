PORTNAME=	qscintilla2
PORTVERSION=	${QSCI2_VERSION}
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_QSCI2}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt6-
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for QScintilla2 (PyQt6), QSci module
WWW=		https://riverbankcomputing.com/software/pyqt \
		https://www.riverbankcomputing.com/software/qscintilla

LIB_DEPENDS=	libqscintilla2_qt6.so:devel/qscintilla2-qt6

DISTINFO_FILE=	${.CURDIR:H}/qscintilla2-qt6/distinfo
DESTDIRNAME=	INSTALL_ROOT

USES=		python pyqt:6 gl qt:6
USE_GL=		gl
USE_PYQT=	pyqt6 sip:build qtbuilder
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		base

OPTIONS_DEFINE=		DEBUG
DEBUG_CONFIGURE_ON=	--debug --trace

WRKSRC=		${WRKDIR}/${DISTNAME}/Python
ALL_TARGET=	#empty

post-extract:
	${CP} ${WRKSRC}/pyproject-qt6.toml ${WRKSRC}/pyproject.toml

do-build:
	(cd ${WRKSRC} ; sip-build-${PYTHON_VER} --qmake ${QMAKE} --verbose --no-make --build-dir build ; ${MAKE} -C ./build )

do-install:
	(cd ${WRKSRC} ; ${MAKE} -C ./build install INSTALL_ROOT=${STAGEDIR} )

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt6/Qsci.abi3.so

.include <bsd.port.mk>
