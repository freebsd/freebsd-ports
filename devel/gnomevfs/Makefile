# New ports collection makefile for:	gnomevfs
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomevfs
PORTVERSION=	0.5
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/gnome-vfs
DISTNAME=	gnome-vfs-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	bonobo.2:${PORTSDIR}/devel/bonobo \
		gconf-1.1:${PORTSDIR}/devel/gconf \
		bz2.1:${PORTSDIR}/archivers/bzip2

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
INSTALL_SHLIBS=	yes
#CONFIGURE_ARGS=	--disable-gconf
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN5=		gnome-vfs-mime.5

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'
	@find ${WRKSRC} -name 'xml-i18n-*' | xargs ${PERL} -pi -e \
		's|/usr/local/bin/perl|${PERL}|g'

.include <bsd.port.mk>
