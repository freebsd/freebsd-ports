# New ports collection makefile for:	gnomedb
# Date created:				19th June 2001
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomedb
PORTVERSION=	0.2.10
PORTREVISION=	1
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-db
DISTNAME=	gnome-db-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	bonobo.2:${PORTSDIR}/devel/bonobo \
		gda-client.0:${PORTSDIR}/databases/libgda

USE_X_PREFIX=	yes
USE_GNOMECTRL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(GNOME_datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g ; \
		 s|\$\(GNOME_datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
