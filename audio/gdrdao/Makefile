# New ports collection makefile for:	gdrdao
# Date created:				November 5 2000
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$

PORTNAME=	gdrdao
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

DEPRECATED=	"no longer on sourceforge, no new master site"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based GUI frontend for cdrdao, disk-at-once audio CD recorder

RUN_DEPENDS=	cdrdao:${PORTSDIR}/sysutils/cdrdao

USE_GNOME=	gnomelibs
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/gdrdao

.include <bsd.port.mk>
