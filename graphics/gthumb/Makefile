# New ports collection makefile for:	gThumb
# Date created:				03 Nov 2001
# Whom:					Harald Schmalzbauer <H@Schmalzbauer.de>
#
# $FreeBSD$
#

PORTNAME=	gthumb
PORTVERSION=	0.13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gthumb

MAINTAINER=	H@Schmalzbauer.de

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack libglade gnomevfs
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gthumb.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
