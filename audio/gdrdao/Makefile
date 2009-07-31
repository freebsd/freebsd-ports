# New ports collection makefile for:	gdrdao
# Date created:				November 5 2000
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$

PORTNAME=	gdrdao
PORTVERSION=	0.4.1
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	danfe

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based GUI frontend for cdrdao, disk-at-once audio CD recorder

RUN_DEPENDS=	cdrdao:${PORTSDIR}/sysutils/cdrdao

USE_GNOME=	gnomelibs
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/gdrdao

.include <bsd.port.mk>
