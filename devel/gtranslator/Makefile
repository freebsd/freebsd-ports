# New ports collection makefile for:	gtranslator
# Date created:				16 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtranslator
PORTVERSION=	0.37
CATEGORIES=	devel gnome
MASTER_SITES=	http://www.gtranslator.org/download/releases/${PORTVERSION}/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	oaf.0:${PORTSDIR}/devel/oaf \
		gconf-1.1:${PORTSDIR}/devel/gconf \
		gnomevfs.0:${PORTSDIR}/devel/gnomevfs \
		gal.4:${PORTSDIR}/x11-toolkits/gal

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

MAN1=		gtranslator.1 nautilus-gtranslator-view.1 pozilla.sh.1
MANCOMPRESSED=	yes

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
