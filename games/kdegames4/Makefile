# New ports collection Makefile for:	kdegames
# Date created:				2008-02-08
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdegames
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Games for the KDE integrated X11 desktop

LIB_DEPENDS=	ggzcore.9:${PORTSDIR}/games/ggz-client-libs \
		qca.2:${PORTSDIR}/devel/qca \
		qhull.5:${PORTSDIR}/math/qhull5 \
		sndfile.1:${PORTSDIR}/audio/libsndfile

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_OPENAL=	al
USE_PYTHON=	yes
USE_TWISTED_RUN=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4 pykde4 sharedmime
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	opengl gui svg iconengines multimedia pixeltool \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
CMAKE_ARGS+=	-DINSTALL_KAJONGG=TRUE

OPTIONS=	FREEBSD "Install FreeBSD card deck" off

.include <bsd.port.options.mk>

.if defined(WITH_FREEBSD)
RUN_DEPENDS+=	kde4-freebsd-carddeck>=1.0:${PORTSDIR}/games/freebsd-carddeck-kde4
.endif

.include <bsd.port.mk>
