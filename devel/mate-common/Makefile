PORTNAME=	mate-common
DISTVERSIONPREFIX=	v
DISTVERSION=	1.28.0
CATEGORIES=	devel mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common automake macros for MATE
WWW=		https://mate-desktop.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USE_GITHUB=	yes
GH_ACCOUNT=	mate-desktop
USES=		autoreconf gmake pkgconfig:both
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

.include <bsd.port.mk>
