# New ports collection makefile for:	ghex2
# Date created:				15 September 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ghex2
PORTVERSION=	1.99.2
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/1.99
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gailutil.17:${PORTSDIR}/x11-toolkits/gail \
		gnomeprintui-2.0:${PORTSDIR}/x11-toolkits/libgnomeprintui \
		gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
