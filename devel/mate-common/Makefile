PORTNAME=	mate-common
DISTVERSION=	1.28.0
PORTREVISION=	1
CATEGORIES=	devel mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common automake macros for MATE
WWW=		https://mate-desktop.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pkgconfig:both tar:xz
USE_GITHUB=	nodefault
GH_ACCOUNT=	mate-desktop
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
