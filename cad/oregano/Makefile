# New ports collection makefile for:	oregano
# Date created:			19 Feb 2001
# Whom:				Anders Andersson <anders@hack.org>
#
# $FreeBSD$
#

PORTNAME=	oregano
PORTVERSION=	0.23
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.codefactory.se/pub/CodeFactory/software/oregano/

MAINTAINER=	anders@andersa.net
COMMENT=	Schematic capture and simulation of electrical circuits

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\(\$$(datadir)/\)gnome/|\1|g ; \
		s|\$$(datadir)/locale|$$(prefix)/share/locale|g'

.include <bsd.port.mk>
