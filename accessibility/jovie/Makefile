# New ports collection makefile for:	ktts
# Date created:		2010-03-27
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jovie
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	accessibility kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kdeaccessibility-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE text-to-speech system

LIB_DEPENDS=	speechd.5:${PORTSDIR}/accessibility/speech-dispatcher

CONFLICTS=	ktts-4.[4-6].*

DISTINFO_FILE=	${PORTSDIR}/accessibility/kdeaccessibility4/distinfo
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	xml qmake_build moc_build uic_build rcc_build
CMAKE_ARGS+=	-DBUILD_kmousetool:BOOL=OFF
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
