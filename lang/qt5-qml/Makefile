# $FreeBSD$

PORTNAME=	qml
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	lang
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt QML and JavaScript language module

USE_QT=		core network buildtools_build
USES=		compiler:c++11-lang python:build qmake qt-dist:5,declarative
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

post-patch:
# tools/tools.pro will be processed automatically unless it does not exist.
	${RM} -r ${WRKSRC}/tools

	${REINPLACE_CMD} 's,python,${PYTHON_CMD},g' \
		${WRKSRC}/src/3rdparty/masm/masm.pri

# qtdeclarative.pro wants to run python, replace that with PYTHON_CMD
	${REINPLACE_CMD} '/py_out/s#python#${PYTHON_CMD}#g' \
		${WRKSRC}/qtdeclarative.pro

.include <bsd.port.mk>
