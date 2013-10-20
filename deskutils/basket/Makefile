# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	basket
PORTVERSION=	1.81
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	http://basket.kde.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop organization tool

LICENSE=	GPLv2

LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme

USE_BZIP2=	yes
USE_XORG=	xft xpm
USE_KDE4=	automoc4 kdeprefix pimlibs qimageblitz
USE_QT4=	moc_build qmake_build rcc_build uic_build
USES=		cmake
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
