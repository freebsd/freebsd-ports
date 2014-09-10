# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	basket
PORTVERSION=	1.81
PORTREVISION=	4
CATEGORIES=	deskutils kde
MASTER_SITES=	http://basket.kde.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop organization tool

LICENSE=	GPLv2

LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme

USE_XORG=	xft xpm
USE_KDE4=	automoc4 kdeprefix pimlibs qimageblitz
USE_QT4=	moc_build qmake_build rcc_build uic_build
USES=		cmake tar:bzip2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
