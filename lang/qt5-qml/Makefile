# $FreeBSD$

PORTNAME=	qml
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	lang
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt QML and JavaScript language module

USE_QT5=	core network buildtools_build
QT_DIST=	declarative
USES=		python:build qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

WRKSRC_SUBDIR=	src/${PORTNAME}

post-patch:
	${REINPLACE_CMD} 's,python,${PYTHON_CMD},g' ${WRKSRC}/../3rdparty/masm/masm.pri

.include <bsd.port.mk>
