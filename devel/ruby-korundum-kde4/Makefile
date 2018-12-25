# $FreeBSD$

PORTNAME=	korundum
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	devel kde kde-kde4 ruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Ruby bindings for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kate kdelibs okular pimlibs \
		qtruby smokegen smokekde smokeqt \
		akonadi automoc4 soprano
USE_QT=		corelib network opengl sql svg xml \
		qmake_build moc_build uic_build rcc_build
USE_RUBY=	yes

CMAKE_ARGS+=	-DRUBY_LIBRARY=${LOCALBASE}/lib/lib${RUBY_NAME}.so \
		-DRUBY_INCLUDE_PATH=${LOCALBASE}/lib/ruby/${RUBY_VER}/${RUBY_ARCH} \
		-DCUSTOM_RUBY_SITE_LIB_DIR=${RUBY_SITELIBDIR} \
		-DCUSTOM_RUBY_SITE_ARCH_DIR=${RUBY_SITEARCHLIBDIR}

pre-configure:
	${REINPLACE_CMD} -e '/examples/ d' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/modules/plasma/CMakeLists.txt

.include <bsd.port.mk>
