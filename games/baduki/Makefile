# New ports collection makefile for:   baduki
# Date created:        11 December 1999
# Whom:                spcoltri@unm.edu
#
# $FreeBSD$
#

PORTNAME=	baduki
PORTVERSION=	0.2.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://autoinst.acs.uci.edu/pub/go/baduki/

MAINTAINER=	spcoltri@omcl.org
COMMENT=	The game of Go

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$(top_builddir)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

.include <bsd.port.mk>
