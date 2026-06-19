PORTNAME=	mate-common
DISTVERSION=	1.28.0
PORTREVISION=	1
CATEGORIES=	devel mate
MASTER_SITES=	https://github.com/mate-desktop/${PORTNAME}/releases/download/v${DISTVERSION}/
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common automake macros for MATE
WWW=		https://mate-desktop.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pkgconfig:both tar:xz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PORTSCOUT=	site:https://github.com/mate-desktop/mate-common/releases/ limitw:1,even

.include <bsd.port.mk>
