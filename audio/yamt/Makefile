# New ports collection makefile for:	yamt
# Date created:			9 January 2000
# Whom:				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	yamt
PORTVERSION=	0.5
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	demon@FreeBSD.org

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomelibs gnomehack gnomeprefix
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

.include <bsd.port.mk>
