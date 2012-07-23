# New ports collection makefile for:	plasma-applet-daisy
# Date Created:				2009-07-08
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	daisy
PORTVERSION=	0.0.4.26
CATEGORIES=	deskutils kde
MASTER_SITES=	http://cdlszm.org/downloads/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Simple launcher plasma applet for KDE4

LICENSE=	GPLv3

USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix kdelibs workspace
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
