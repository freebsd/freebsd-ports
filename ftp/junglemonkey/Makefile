# New ports collection makefile for:	junglemonkey
# Date created:        			21st April 2000
# Whom:                			Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	junglemonkey
PORTVERSION=	0.1.9
CATEGORIES=	ftp gnome
MASTER_SITES=	http://www.junglemonkey.net/src/
DISTNAME=	jm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnet.0:${PORTSDIR}/net/gnet \
		popt.0:${PORTSDIR}/devel/popt \
		glade.4:${PORTSDIR}/devel/libglade

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		jm.1 jmlite.1 jmsearchserver.1 mtprendezvous.1

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
