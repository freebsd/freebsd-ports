# Created by: Solène RAPENNE <solene@bsd.zplay.eu>
# $FreeBSD$

PORTNAME=	sxiv
PORTVERSION=	1.3.1
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	solene@bsd.zplay.eu
COMMENT=	Lightweight image viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libImlib2.so:${PORTSDIR}/graphics/imlib2 \
		libexif.so:${PORTSDIR}/graphics/libexif

USE_GITHUB=	yes
GH_ACCOUNT=	muennich
USES=		pkgconfig gmake
USE_XORG=	x11

PLIST_FILES=	bin/sxiv \
		man/man1/sxiv.1.gz \
		share/sxiv/exec/image-info \
		share/sxiv/exec/key-handler

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sxiv

.include <bsd.port.mk>
