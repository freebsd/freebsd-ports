# $FreeBSD$

PORTNAME=	krossruby
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde kde-kde4 ruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	kross-interpreters-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Ruby bindings for Qt/KDE

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs pimlibs automoc4
USE_QT4=	corelib gui qmake_build moc_build uic_build rcc_build
USE_RUBY=	yes
CMAKE_ARGS+=	-DBUILD_python:BOOL=FALSE \
		-DBUILD_falcon:BOOL=FALSE \
		-DBUILD_java:BOOL=FALSE

PLIST_FILES=	lib/kde4/krossruby.so

.include <bsd.port.mk>
