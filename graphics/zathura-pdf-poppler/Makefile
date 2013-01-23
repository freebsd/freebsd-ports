# Created by: Mike Krutov <neko@takino.org>
# $FreeBSD$

PORTNAME=	zathura-pdf-poppler
PORTVERSION=	0.2.2
CATEGORIES=	graphics
MASTER_SITES=	http://pwmt.org/projects/zathura/plugins/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Poppler render PDF plugin for Zathura PDF viewer

LIB_DEPENDS=	poppler-glib:${PORTSDIR}/graphics/poppler-glib
BUILD_DEPENDS=	zathura:${PORTSDIR}/graphics/zathura
RUN_DEPENDS=	zathura:${PORTSDIR}/graphics/zathura

USE_GNOME=	glib20 gtk20
USE_GMAKE=	yes

PLIST_FILES=	lib/zathura/pdf.so
PLIST_DIRSTRY=	lib/zathura

.include <bsd.port.mk>
