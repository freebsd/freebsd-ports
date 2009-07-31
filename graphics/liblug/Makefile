# New ports collection makefile for:	liblug
# Date created:				27 December 2000
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		liblug
PORTVERSION=		1.0.6
PORTREVISION=	3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=		ports@FreeBSD.org
COMMENT=	A multi-format graphics manipulation library

LIB_DEPENDS=		tiff.4:${PORTSDIR}/graphics/tiff

PLIST_FILES=		lib/liblug.a
USE_XORG=		x11

WRKSRC=			${WRKDIR}/lug
MAKEFILE=		Makefile.linux
USE_LDCONFIG=	yes

.include <bsd.port.mk>
