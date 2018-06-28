# $FreeBSD$

PORTNAME=	help
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt online help integration module

USE_QT=		core gui network sql widgets \
		buildtools_build sql-sqlite3_run
USES=		qmake qt-dist:5,tools
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/assistant
INSTALL_WRKSRC=	${WRKSRC}/src/assistant

.include <bsd.port.mk>
