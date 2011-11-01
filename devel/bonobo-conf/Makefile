# New ports collection makefile for:	bonobo-conf
# Date created:				9th February 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bonobo-conf
PORTVERSION=	0.16
PORTREVISION=	10
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Bonobo configuration moniker

DEPRECATED=	No more supported upstream, not depend on anymore.
EXPIRATION_DATE=	2011-11-30

USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack bonobo gconf
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
