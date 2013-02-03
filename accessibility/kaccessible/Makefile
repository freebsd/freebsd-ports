# $FreeBSD$

PORTNAME=	kaccessible
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	accessibility kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibility services for KDE

LIB_DEPENDS=	speechd.5:${PORTSDIR}/accessibility/speech-dispatcher

CONFLICTS_INSTALL=	kdeaccessibility-4.[0-7].*

USE_XZ=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT4=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
