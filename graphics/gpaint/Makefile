# New ports collection makefile for:	gpaint
# Date created:				18 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gpaint
PORTVERSION=	0.2.2
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://alpha.gnu.org/pub/gnu/gpaint/

MAINTAINER=	sobomax@FreeBSD.org

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gdkpixbuf gnomeprint
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
