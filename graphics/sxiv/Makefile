# Created by: Solène RAPENNE <solene@bsd.zplay.eu>
# $FreeBSD$

PORTNAME=	sxiv
PORTVERSION=	1.2
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
		share/sxiv/exec/image-info \
		share/sxiv/exec/key-handler
PLIST_DIRS=	share/sxiv/exec \
		share/sxiv

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sxiv

.include <bsd.port.mk>
