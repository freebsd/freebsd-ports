# New ports collection makefile for:	gno3dtet
# Date created:		21 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gno3dtet
PORTVERSION=	1.6.4
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	ftp://12.206.131.3/pub/gno3dtet/ \
		http://www.eseb.net/ftp/gno3dtet/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME version of the classic 3D-ified T*tris

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs
USE_LIBTOOL_VER=13
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
