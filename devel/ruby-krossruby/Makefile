# $FreeBSD$

PORTNAME=	krossruby
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	devel kde ruby
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	kross-interpreters-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Ruby bindings for Qt/KDE

USE_KDE4=	kdehier kdelibs kdeprefix pimlibs automoc4
USE_QT4=	corelib gui qmake_build moc_build uic_build rcc_build
USE_RUBY=	yes
USES=		cmake:outsource tar:xz
CMAKE_ARGS+=	-DBUILD_python:BOOL=FALSE \
		-DBUILD_falcon:BOOL=FALSE \
		-DBUILD_java:BOOL=FALSE

PLIST_FILES=	lib/kde4/krossruby.so

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 2.0
BROKEN=		Only works with Ruby 1.9
.endif

.include <bsd.port.post.mk>
