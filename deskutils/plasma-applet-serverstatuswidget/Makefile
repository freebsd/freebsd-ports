# New ports collection makefile for:	plasma-applet-serverstatuswidget
# Date Created:				2011-02-23
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	serverstatuswidget
PORTVERSION=	1.4
CATEGORIES=	deskutils kde
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	101336-${PORTNAME}-${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Server monitoring plasma applet for KDE4

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_KDE4=	automoc4 kdeprefix workspace
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:

	${ECHO_CMD} >> ${WRKSRC}/src/serverstatus.h

.include <bsd.port.mk>
