# New ports collection makefile for:	plasma-applet-daisy
# Date Created:				2009-07-08
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	daisy
PORTVERSION=	0.0.4.25
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	http://cdlszm.org/downloads/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Simple launcher plasma applet for KDE4

USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix kdelibs workspace
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

.include <bsd.port.mk>
