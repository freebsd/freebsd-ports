# New ports collection makefile for:	bonobo
# Date created:				8th October 1999
# Whom:					Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

PORTNAME=	bonobo
PORTVERSION=	1.0.4
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/bonobo

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gnomeprint.16:${PORTSDIR}/print/gnomeprint

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOMECTRL=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFILES=	configure libefs/configure
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

# XXX: hack - will be fixed in next release - say hi to
#      GNOME release engineering :)
post-patch:
	@find ${WRKSRC} -name '*.idl' | xargs touch

.include <bsd.port.mk>
