# New ports collection makefile for:	gnomememoryblocks
# Date created:				10th July 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomememoryblocks
PORTVERSION=	0.2
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnome-memblocks
DISTNAME=	gnome-memblocks-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$$(datadir)/gnome/|\$$(datadir)/|g ; \
		 s|\$$(datadir)/locale|\$$(prefix)/share/locale|g'

.include <bsd.port.mk>
