# $FreeBSD$

PORTNAME=	korundum
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde ruby
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Ruby bindings for KDE

USE_KDE4=	kate kdelibs okular pimlibs \
		qtruby smokegen smokekde smokeqt \
		akonadi automoc4 soprano
USE_QT4=	corelib network opengl sql svg xml \
		qmake_build moc_build uic_build rcc_build
USE_RUBY=	yes
USES=		cmake:outsource tar:xz

CMAKE_ARGS+=	-DRUBY_LIBRARY=${LOCALBASE}/lib/lib${RUBY_NAME}.so \
		-DRUBY_INCLUDE_PATH=${LOCALBASE}/lib/ruby/${RUBY_VER}/${RUBY_ARCH} \
		-DCUSTOM_RUBY_SITE_LIB_DIR=${RUBY_SITELIBDIR} \
		-DCUSTOM_RUBY_SITE_ARCH_DIR=${RUBY_SITEARCHLIBDIR}

pre-configure:
	${REINPLACE_CMD} -e '/examples/ d' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/modules/plasma/CMakeLists.txt

.include <bsd.port.mk>
