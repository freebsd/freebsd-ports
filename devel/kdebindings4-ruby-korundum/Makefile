# New ports collection makefile for:	korundum
# Date created:				2 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	korundum
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde ruby
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}kdebindings-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Ruby bindings for KDE

CONFLICTS=	ruby1[89]-kdebindings-4.[0-6].*

USE_KDE4=	kate kdehier kdelibs kdeprefix okular pimlibs \
		qtruby smokegen smokekde smokeqt \
		akonadi automoc4 soprano
USE_QT_VER=	4
QT_COMPONENTS=	dbus network opengl sql svg xml \
		qmake_build moc_build uic_build rcc_build
USE_RUBY=	yes
USE_XZ=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

CMAKE_ARGS+=	-DRUBY_LIBRARY=${LOCALBASE}/lib/lib${RUBY_NAME}.so \
		-DRUBY_INCLUDE_PATH=${LOCALBASE}/lib/ruby/${RUBY_VER}/${RUBY_ARCH} \
		-DCUSTOM_RUBY_SITE_LIB_DIR=${RUBY_SITELIBDIR} \
		-DCUSTOM_RUBY_SITE_ARCH_DIR=${RUBY_SITEARCHLIBDIR}

pre-configure:
	${REINPLACE_CMD} -e '/examples/ d' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/modules/plasma/CMakeLists.txt

.include <bsd.port.post.mk>
