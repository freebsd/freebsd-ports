# New ports collection makefile for:	plasma-applet-yawp
# Date Created:				2009-01-15
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	yawp
PORTVERSION=	0.3.6
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	SF
PKGNAMEPREFIX=	plasma-applet-

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Weather plasma applet for KDE4

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix workspace
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE-GPL2

.include <bsd.port.mk>
