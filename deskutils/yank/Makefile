# New ports collection makefile for:	yank
# Date created:				28 November 1999
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yank
PORTVERSION=	0.2.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://home.ins.de/~m.hussmann/software/yank/

MAINTAINER=	jedgar@FreeBSD.org

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's^-l(pthread|c_r)^${PTHREAD_LIBS}^g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's^\$\(datadir\)/gnome/^\$\(datadir\)/^g ; \
		 s^\$\(datadir\)/locale^\$\(prefix\)/share/locale^g'
	@find ${WRKSRC}/src/Plugins -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|_la_LDFLAGS =|_la_LDFLAGS = -avoid-version|g'

.include <bsd.port.mk>
