# Ports collection Makefile for:	dasher
# Date created:				5 July 2003
# Whom:					lewiz <purple@lewiz.net>
#
# $FreeBSD$
#

PORTNAME=	dasher
PORTVERSION=	3.2.2
PORTREVISION=	1
CATEGORIES=	accessibility editors x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/3.2
DIST_SUBDIR=	gnome2

MAINTAINER=	purple@lewiz.net
COMMENT=	Information efficient text-entry interface

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomehier gconf2 libglade2
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		dasher.1

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-O2||g'

.include <bsd.port.mk>
