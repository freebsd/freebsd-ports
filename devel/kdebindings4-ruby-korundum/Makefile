# New ports collection makefile for:	korundum
# Date created:				2 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	korundum
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}kdebindings-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Ruby bindings for KDE

LIB_DEPENDS=	qtruby4shared.2:${PORTSDIR}/devel/kdebindings4-ruby-qtruby \
		smokekdecore.3:${PORTSDIR}/devel/kdebindings4-smoke-smokekde \
		smokebase.3:${PORTSDIR}/devel/kdebindings4-smoke-smokegen \
		soprano.4:${PORTSDIR}/textproc/soprano \
		kateinterfaces.5:${PORTSDIR}/editors/kate \
		smokeqtcore.3:${PORTSDIR}/devel/kdebindings4-smoke-smokeqt \
		okularcore.1:${PORTSDIR}/graphics/okular

CONFLICTS=	ruby1[89]-kdebindings-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix pimlibs akonadi automoc4
USE_QT_VER=	4
QT_COMPONENTS=	dbus network opengl sql svg xml \
		qmake_build moc_build uic_build rcc_build
USE_RUBY=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

SUB_FILES=	ruby-kdebindings-env.sh pkg-message
SUB_LIST+=	RUBY_SITELIBDIR=${RUBY_SITELIBDIR} \
		RUBY_SITEARCHLIBDIR=${RUBY_SITEARCHLIBDIR}

.include <bsd.port.pre.mk>

CMAKE_ARGS+=	-DRUBY_LIBRARY=${LOCALBASE}/lib/lib${RUBY_NAME}.so \
		-DRUBY_INCLUDE_PATH=${LOCALBASE}/lib/ruby/${RUBY_VER}/${RUBY_ARCH} \
		-DCUSTOM_RUBY_SITE_LIB_DIR=${RUBY_SITELIBDIR} \
		-DCUSTOM_RUBY_SITE_ARCH_DIR=${RUBY_SITEARCHLIBDIR}

pre-configure:
	${REINPLACE_CMD} -e '/examples/ d' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/modules/plasma/CMakeLists.txt

post-install:
	${MKDIR} ${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/ruby-kdebindings-env.sh ${PREFIX}/env
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
