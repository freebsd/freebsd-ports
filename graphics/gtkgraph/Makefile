# New ports collection makefile for:	gtkgraph
# Date created:				12 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	gtkgraph
PORTVERSION=	0.6.1
CATEGORIES=	graphics math
MASTER_SITES=	http://gtkgraph.linuxave.net/

MAINTAINER=	jedgar@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_IMLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; s|-O2|${CFLAGS}| ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
