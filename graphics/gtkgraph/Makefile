# New ports collection makefile for:	gtkgraph
# Date created:				12 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	gtkgraph
PORTVERSION=	0.6.1
PORTREVISION=	8
CATEGORIES=	graphics math
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= jedgar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphing calculator using GTK+

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	imlib
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; s|-O2|${CFLAGS}| ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
