# New ports collection makefile for:	gruler
# Date created:				24 October 2004
# Whom:					Piotr Smyrak <smyru@heron.pl>
#
# $FreeBSD$
#

PORTNAME=	gruler
PORTVERSION=	0.6
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	http://linuxadvocate.org/projects/gruler/downloads/

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A customizable screen ruler for GNOME

USE_GNOME=	gnomeprefix gnomehack libgnomeui libglade2
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GCC=	3.4

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=""||' ${WRKSRC}/configure

.include <bsd.port.mk>
