# New ports collection makefile for:	digikam
# Date created: 			3 February 2003
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	digikam
PORTVERSION=	0.10.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics kde
MASTER_SITES=	SFE

MAINTAINER=	datahead4@gmail.com
COMMENT=	An advanced digital photo management application for KDE4

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2 \
		lcms.1:${PORTSDIR}/graphics/lcms \
		png.5:${PORTSDIR}/graphics/png \
		jasper.4:${PORTSDIR}/graphics/jasper \
		kipi.6:${PORTSDIR}/graphics/kdegraphics4

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs pimlibs
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui sql qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes

MAN1=		digitaglinktree.1

.include <bsd.port.mk>
