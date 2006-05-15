# New ports collection makefile for:	nautilus-open-terminal
# Date created:		2005-07-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/deskutils/nautilus-open-terminal/Makefile,v 1.5 2005/10/08 19:41:16 marcus Exp $
#

PORTNAME=	nautilus-open-terminal
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://manny.cluecoder.org/packages/nautilus-open-terminal/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Nautilus extension which allows you to open a terminal

GNU_CONFIGURE=	yes
USE_GNOME=	nautilus2 gnomeprefix intlhack gnomehack
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
