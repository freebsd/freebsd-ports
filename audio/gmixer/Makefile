# New ports collection makefile for:	gmixer
# Date created:        25 February 1999
# Whom:                Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmixer
PORTVERSION=	0.98c
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cpiazza

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11/gtk+ mixer control

ALL_TARGET=	gmixer

USE_GNOME=	gtk12

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmixer ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/gmixer.xpm ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
