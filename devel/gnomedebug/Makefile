# New ports collection makefile for:	gnomedebug
# Date created:				24 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomedebug
PORTVERSION=	0.1.6
CATEGORIES?=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/${PORTNAME:S/gnome/gnome-/}
DISTNAME=	${PORTNAME:S/gnome/gnome-/}-${PORTVERSION}

MAINTAINER?=	gnome@FreeBSD.org

LIB_DEPENDS=	gdl.0:${PORTSDIR}/x11-toolkits/gdl

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
