# New ports collection makefile for:	glife
# Date created:				18th May 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glife
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	gLife-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$$(datadir)/gnome/|\$$(datadir)/|g ; \
		 s|\$$(datadir)/locale|\$$(prefix)/share/locale|g'

.include <bsd.port.mk>
