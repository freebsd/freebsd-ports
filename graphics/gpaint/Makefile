# New ports collection makefile for:	gpaint
# Date created:				18 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gpaint
PORTVERSION=	0.3.3
DISTVERSIONPREFIX=	2-
PORTREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small-scale painting program for GNOME

USE_GNOME=	gnometarget libgnomeprint libgnomeprintui
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gpaint-2 %%DATADIR%%/glade/gpaint.glade
PLIST_DIRS=	%%DATADIR%%/glade %%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e \
		's|_RESPONSE_DISCARD|_RESPONSE_NO|g' ${WRKSRC}/src/drawing.c

.include <bsd.port.mk>
