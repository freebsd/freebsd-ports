# $FreeBSD$

PORTNAME=	krosspython
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	devel kde kde-kde4 python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	kross-interpreters-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kross Python scripting library

USES=		cmake:outsource kde:4 python:2.7 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	corelib gui qmake_build moc_build uic_build rcc_build
CMAKE_ARGS+=	-DBUILD_falcon:BOOL=FALSE \
		-DBUILD_ruby:BOOL=FALSE \
		-DBUILD_java:BOOL=FALSE

PLIST_FILES=	lib/kde4/krosspython.so

.include <bsd.port.mk>
