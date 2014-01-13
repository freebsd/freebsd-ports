# $FreeBSD$

PORTNAME=	krosspython
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde python
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	kross-interpreters-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kross Python scripting library

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_PYTHON=	yes
USE_QT4=	corelib gui qmake_build moc_build uic_build rcc_build
USE_XZ=		yes
USES=		cmake:outsource
CMAKE_ARGS+=	-DBUILD_falcon:BOOL=FALSE \
		-DBUILD_ruby:BOOL=FALSE \
		-DBUILD_java:BOOL=FALSE

PLIST_FILES=	lib/kde4/krosspython.so

NO_STAGE=	yes
.include <bsd.port.mk>
