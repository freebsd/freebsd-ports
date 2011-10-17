# New ports collection makefile for:	kdebindings4-ruby
# Date created:		2008-08-19
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qtruby
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}kdebindings-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Ruby bindings for Qt

LIB_DEPENDS=	smokeqtcore.3:${PORTSDIR}/devel/kdebindings4-smoke-smokeqt \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt5 \
		qscintilla2.5:${PORTSDIR}/devel/qscintilla2

CONFLICTS=	ruby1[89]-kdebindings-4.[0-6].*

USE_KDE4=	kdehier kdeprefix
USE_QT_VER=	4
QT_COMPONENTS=	dbus declarative designer gui network \
		phonon qtestlib script webkit xml \
		qmake_build moc_build uic_build rcc_build
USE_RUBY=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

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

.include <bsd.port.post.mk>
