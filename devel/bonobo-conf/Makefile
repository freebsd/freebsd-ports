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

USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack bonobo gconf
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
