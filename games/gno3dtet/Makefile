# New ports collection makefile for:	gno3dtet
# Date created:		21 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gno3dtet
PORTVERSION=	1.6.4
CATEGORIES=	games gnome
MASTER_SITES=	http://12.252.48.14/ftp/gno3dtet/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs 
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
	${CHOWN} root:games ${PREFIX}/bin/gno3dtet
	${CHMOD} 2555 ${PREFIX}/bin/gno3dtet
	${CHOWN} root:games ${PREFIX}/share/gnome/games/gno3dtet.hof
	${CHMOD} 664 ${PREFIX}/share/gnome/games/gno3dtet.hof

.include <bsd.port.mk>
