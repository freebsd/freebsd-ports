# $FreeBSD$

PORTNAME=	jovie
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	accessibility kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE text-to-speech system

LIB_DEPENDS=	speechd.5:${PORTSDIR}/accessibility/speech-dispatcher

CONFLICTS=	ktts-4.[4-6].*

USE_XZ=	yes
USE_CMAKE=	yes
USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT4=	xml qmake_build moc_build uic_build rcc_build
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
