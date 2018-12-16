# $FreeBSD$

PORTNAME=	help
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt online help integration module

USES=		compiler:c++11-lang qmake qt-dist:5,tools
USE_QT=		core gui network sql widgets \
		buildtools_build sql-sqlite3_run
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/assistant
INSTALL_WRKSRC=	${WRKSRC}/src/assistant

post-install:
# qcollectiongenerator was integrated into qhelpgenerator.
# Instead of fixing 20 ports, simply provide it.
	${RLN} ${STAGEDIR}${QT_BINDIR}/qhelpgenerator \
		${STAGEDIR}${QT_BINDIR}/qcollectiongenerator

.include <bsd.port.mk>
