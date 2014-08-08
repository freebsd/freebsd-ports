# Created by: Solène RAPENNE <charles@bsd.zplay.eu>
# $FreeBSD$

PORTNAME=	sxiv
PORTVERSION=	1.1.1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/muennich/sxiv/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	solene@bsd.zplay.eu
COMMENT=	Lightweight image viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libImlib2.so:${PORTSDIR}/graphics/imlib2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/
USES=		pkgconfig
USE_XORG=	x11

PLIST_FILES=	bin/sxiv \
		man/man1/sxiv.1.gz \
		share/sxiv/exec/image-info
PLIST_DIRS=	share/sxiv/exec \
		share/sxiv

.include <bsd.port.mk>
