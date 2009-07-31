# New ports collection makefile for:	junglemonkey
# Date created:        			21st April 2000
# Whom:                			Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	junglemonkey
PORTVERSION=	0.1.11
PORTREVISION=	9
CATEGORIES=	ftp gnome
MASTER_SITES=	http://www.gizmolabs.org/~dhelder/junglemonkey/src/
DISTNAME=	jm-${PORTVERSION}

MAINTAINER=	beech@FreeBSD.org
COMMENT=	A distributed file sharing program for GNOME

LIB_DEPENDS=	gnet.7:${PORTSDIR}/net/gnet

USE_GNOME=	gnomehack gnomeprefix libglade
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gnome=yes --enable-debug=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		jm.1 jmlite.1 mtprendezvous.1

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
