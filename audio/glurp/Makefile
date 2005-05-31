# New ports collection makefile for:	glurp
# Date created:		Jun 9 2004
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	glurp
PORTVERSION=	0.11.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Nice and clean GTK+-2.x based graphical client for musicpd

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
USE_GNOME=	gnometarget libglade2
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -export-dynamic" \

.include <bsd.port.mk>
