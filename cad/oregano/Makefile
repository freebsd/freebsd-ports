# New ports collection makefile for:	oregano
# Date created:			19 Feb 2001
# Whom:				Anders Andersson <anders@codefactory.se>
#
# $FreeBSD$
#

PORTNAME=	oregano
PORTVERSION=	0.22
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.codefactory.se/pub/CodeFactory/software/oregano/

MAINTAINER=	anders@codefactory.se

LIB_DEPENDS=	gnomeprint.13:${PORTSDIR}/print/gnomeprint \
		glade.4:${PORTSDIR}/devel/libglade \
		xml.5:${PORTSDIR}/textproc/libxml

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
