# $FreeBSD$

PORTNAME=	jovie
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	accessibility kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE text-to-speech system

LIB_DEPENDS=	libspeechd.so:${PORTSDIR}/accessibility/speech-dispatcher

CONFLICTS=	ktts-4.[4-6].*

NO_STAGE=	yes
USE_XZ=		yes
USES=		cmake:outsource
USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT4=	xml qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
