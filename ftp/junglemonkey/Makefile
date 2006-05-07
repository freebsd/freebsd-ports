# New ports collection makefile for:	junglemonkey
# Date created:        			21st April 2000
# Whom:                			Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	junglemonkey
PORTVERSION=	0.1.11
PORTREVISION=	4
CATEGORIES=	ftp gnome
MASTER_SITES=	http://www.junglemonkey.net/src/
DISTNAME=	jm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A distributed file sharing program for GNOME

LIB_DEPENDS=	gnet.1:${PORTSDIR}/net/gnet

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix libglade
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gnome=yes --enable-debug=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		jm.1 jmlite.1 mtprendezvous.1

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|/gnome/help/|/help/|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$$(datadir)/gnome/|\$$(datadir)/|g ; \
		 s|\$$(datadir)/locale|\$$(prefix)/share/locale|g'

.include <bsd.port.mk>
