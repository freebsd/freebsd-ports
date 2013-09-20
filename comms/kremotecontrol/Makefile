# $FreeBSD$

PORTNAME=	kremotecontrol
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	comms kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE frontend for your remote controls

RUN_DEPENDS=	lircd:${PORTSDIR}/comms/lirc

CONFLICTS_INSTALL=	kdeutils-4.[0-7].*

USE_XZ=		yes
USE_KDE4=	kdeprefix kdehier automoc4 kdelibs
USES=		cmake:outsource
USE_QT4=	corelib script xmlpatterns \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
