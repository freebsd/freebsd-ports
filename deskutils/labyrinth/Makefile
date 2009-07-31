# New ports collection makefile for:	labyrinth
# Date created:		2008-09-28
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	labyrinth
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	deskutils python
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	romain@blogreen.org
COMMENT=	Mind-mapping tool for GNOME

WRKSRC=		${WRKDIR}/${PORTNAME}-0.4.0
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	GMSGFMT=msgfmt
USE_GNOME=	pygnome2 gnomedesktop gnomehack
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
