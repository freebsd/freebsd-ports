# $FreeBSD$

PORTNAME=	serverstatuswidget
PORTVERSION=	1.5.1
PORTREVISION=	3
CATEGORIES=	deskutils kde
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	101336-${PORTNAME}-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Server monitoring plasma applet for KDE4

USE_BZIP2=	yes
USES=		cmake gettext
USE_KDE4=	automoc4 kdeprefix workspace
USE_QT4=	qmake_build moc_build rcc_build uic_build

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
post-patch:

	${ECHO_CMD} >> ${WRKSRC}/src/serverstatus.h

.include <bsd.port.mk>
