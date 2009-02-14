# New ports collection makefile for:	kipi-plugins-kde4
# Date created:				Jan 23, 2009
# Whom:					Kris Moore
#
# $FreeBSD$
#

PORTNAME=	kipi-plugins
DISTVERSION=	0.2.0-beta6
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kipi
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kris@pcbsd.org
COMMENT=	KDE4 kipi graphics plugins

LIB_DEPENDS=	cv.1:${PORTSDIR}/graphics/opencv \
		gpod.3:${PORTSDIR}/audio/libgpod \
		expat.6:${PORTSDIR}/textproc/expat2 \
		kipi.6:${PORTSDIR}/graphics/kdegraphics4
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdehier kdeprefix pimlibs kdebase
USE_QT_VER=	yes
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
