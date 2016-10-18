# $FreeBSD$

PORTNAME=	qtruby
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-kde4 ruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Ruby bindings for Qt

LIB_DEPENDS=	libqwt.so:x11-toolkits/qwt5 \
		libqscintilla2.so:devel/qscintilla2

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	smokeqt
USE_QT4=	corelib dbus declarative gui network phonon script webkit xml \
		qmake_build moc_build uic_build rcc_build
USE_RUBY=	yes
USE_LDCONFIG=	yes

SUB_FILES=	ruby-kdebindings-env.sh pkg-message
SUB_LIST+=	RUBY_SITELIBDIR=${RUBY_SITELIBDIR} \
		RUBY_SITEARCHLIBDIR=${RUBY_SITEARCHLIBDIR}

CMAKE_ARGS+=	-DRUBY_LIBRARY=${LOCALBASE}/lib/lib${RUBY_NAME}.so \
		-DRUBY_INCLUDE_PATH=${LOCALBASE}/lib/ruby/${RUBY_VER}/${RUBY_ARCH} \
		-DCUSTOM_RUBY_SITE_LIB_DIR=${RUBY_SITELIBDIR} \
		-DCUSTOM_RUBY_SITE_ARCH_DIR=${RUBY_SITEARCHLIBDIR}

post-patch:
	${REINPLACE_CMD} -e 's|QWT_FOUND|Qwt5_FOUND|g' \
		${WRKSRC}/src/CMakeLists.txt
	${REINPLACE_CMD} -e 's|share/qtruby4/cmake|lib/cmake/qtruby4|g' \
		${WRKSRC}/cmake/CMakeLists.txt \
		${WRKSRC}/src/CMakeLists.txt

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/ruby-kdebindings-env.sh ${STAGEDIR}${PREFIX}/env

.include <bsd.port.mk>
