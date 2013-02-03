# $FreeBSD$

PORTNAME=	qtruby
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde ruby
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Ruby bindings for Qt

LIB_DEPENDS=	qwt.5:${PORTSDIR}/x11-toolkits/qwt5 \
		qscintilla2:${PORTSDIR}/devel/qscintilla2

CONFLICTS_INSTALL=	ruby1[89]-kdebindings-4.[0-6].* \
			ruby1[89]-kdebindings-korundum-4.7.*

USE_KDE4=	kdehier kdeprefix smokeqt
USE_QT4=	dbus declarative designer gui network \
		phonon qtestlib script webkit xml \
		qmake_build moc_build uic_build rcc_build
USE_RUBY=	yes
USE_XZ=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

SUB_FILES=	ruby-kdebindings-env.sh pkg-message
SUB_LIST+=	RUBY_SITELIBDIR=${RUBY_SITELIBDIR} \
		RUBY_SITEARCHLIBDIR=${RUBY_SITEARCHLIBDIR}

.include <bsd.port.pre.mk>

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
	${MKDIR} ${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/ruby-kdebindings-env.sh ${PREFIX}/env
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
