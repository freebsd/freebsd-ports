# New ports collection makefile for:	nautilus-sendto
# Date created:		2004-12-03
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/deskutils/nautilus-sendto/Makefile,v 1.7 2007/03/12 11:50:11 ahze Exp $

PORTNAME=	nautilus-sendto
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integration between nautilus, evolution, and gaim

BUILD_DEPENDS=	evolution:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	evolution:${PORTSDIR}/mail/evolution

MAN1=		nautilus-sendto.1
GCONF_SCHEMAS=	nst.schemas
USE_BZIP2=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	intlhack gnomeprefix gnometarget nautilus2 gnomehack
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
