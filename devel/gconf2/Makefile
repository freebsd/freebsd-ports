# New ports collection makefile for:	gconf
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gconf
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/GConf
DISTNAME=	GConf-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		guile.9:${PORTSDIR}/lang/guile \
		oaf.0:${PORTSDIR}/devel/oaf

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GNOME=	yes
INSTALL_SHLIBS=	yes
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

.include <bsd.port.mk>
