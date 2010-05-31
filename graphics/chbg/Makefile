# New ports collection makefile for:	chbg
# Date created:		10 Dec 1999
# Whom:			Peter Jones <p@dancris.com>
#
# $FreeBSD$
#

PORTNAME=	chbg
PORTVERSION=	1.5
PORTREVISION=	13
CATEGORIES=	graphics gnome
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Change Background Picture with time period

USE_GNOME=	gdkpixbuf
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-gnome

.include <bsd.port.pre.mk>

MAN1=		chbg.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
