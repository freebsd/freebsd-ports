# New ports collection makefile for:	gcolor2
# Date created:		18 April 2005
# Whom:			Piotr Smyrak, piotr.smyrak@heron.pl
#
# $FreeBSD$
#

PORTNAME=	gcolor2
PORTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	smyru@heron.pl
COMMENT=	A simple GTK+ 2.0 color selector

USE_GNOME=	gtk20 gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

SUB_FILES=	gcolor2.desktop

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/gcolor2.desktop ${PREFIX}/share/applications

.include <bsd.port.mk>
