# New ports collection makefile for: goats
# Date created:			Jul 7, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$

PORTNAME=	goats
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.menudo.freeserve.co.uk/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Yellow post-it note applet for GNOME 2

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeprintui gnomepanel libglade2 gnomeprefix gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
