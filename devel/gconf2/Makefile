# New ports collection makefile for:	gconf
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gconf
PORTVERSION=	0.9
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/GConf
DISTNAME=	GConf-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		guile.9:${PORTSDIR}/lang/guile \
		oaf.0:${PORTSDIR}/devel/oaf \
		iconv.1:${PORTSDIR}/converters/iconv

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GNOME=	yes
INSTALL_SHLIBS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -liconv"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
