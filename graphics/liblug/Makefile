# New ports collection makefile for:	liblug
# Date created:				27 December 2000
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		liblug
PORTVERSION=		1.0.6
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=		greid@ukug.uk.freebsd.org

LIB_DEPENDS=		tiff.4:${PORTSDIR}/graphics/tiff

USE_XLIB=		yes

WRKSRC=			${WRKDIR}/lug
MAKEFILE=		Makefile.linux
INSTALLS_SHLIB=		yes

.include <bsd.port.mk>
