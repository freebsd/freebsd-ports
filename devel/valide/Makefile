# New ports collection makefile for:	valide
# Date created:		2008-08-05
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	valide
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/${PORTNAME}/

MAINTAINER=	romain@blogreen.org
COMMENT=	An IDE for the Vala programming language

RUN_DEPENDS=	valac:${PORTSDIR}/lang/vala

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 gtksourceview2

.include <bsd.port.mk>
