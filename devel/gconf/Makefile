# New ports collection makefile for:	gconf
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gconf
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/GConf
DISTNAME=	GConf-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	guile.9:${PORTSDIR}/lang/guile \
		oaf.0:${PORTSDIR}/devel/oaf \
		db3.2:${PORTSDIR}/databases/db3

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOMELIBS=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
	@if [ ! -f ${PREFIX}/etc/gconf/1/path ]; then \
		${CP} -p ${PREFIX}/etc/gconf/1/path.example ${PREFIX}/etc/gconf/1/path ; \
	fi
	@${MKDIR} ${PREFIX}/etc/gconf/gconf.xml.defaults/apps
	@${MKDIR} ${PREFIX}/etc/gconf/gconf.xml.defaults/schemas/apps


.include <bsd.port.mk>
