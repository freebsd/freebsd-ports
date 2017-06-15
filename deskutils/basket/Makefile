# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	basket
PORTVERSION=	1.81
PORTREVISION=	5
CATEGORIES=	deskutils kde
MASTER_SITES=	http://basket.kde.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop organization tool

LICENSE=	GPLv2

LIB_DEPENDS=	libgpgme.so:security/gpgme

USES=		cmake gettext-tools kde:4 tar:bzip2
USE_XORG=	xft xpm
USE_KDE=	automoc4 pimlibs qimageblitz
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
