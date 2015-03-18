# $FreeBSD$

PORTNAME=	qml
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	lang
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt QML and JavaScript language module

USE_QT5=	core network buildtools_build
QT_DIST=	declarative
USES=		python:build qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

post-patch:
# tools/tools.pro will be processed automatically unless it does not exist.
	${RM} -r ${WRKSRC}/tools

	${REINPLACE_CMD} 's,python,${PYTHON_CMD},g' \
		${WRKSRC}/src/3rdparty/masm/masm.pri


.include <bsd.port.mk>
