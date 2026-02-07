PORTNAME=	mate-common
PORTVERSION=	1.28.0
CATEGORIES=	devel mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common automake macros for MATE
WWW=		https://mate-desktop.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USES=		gmake pkgconfig:both tar:xz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

.include <bsd.port.mk>
