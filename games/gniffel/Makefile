# New ports collection makefile for:	gniffel
# Date created:				6 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gniffel
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	games gnome
# mastersite disappeared in February 2002
MASTER_SITES=	# http://www.informatik.fh-wiesbaden.de/~i820/downloads/

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of the famous Yatzi game, also known as Kniffel, for GNOME

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
