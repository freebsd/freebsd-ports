# New ports collection makefile for:	chbg
# Date created:		10 Dec 1999
# Whom:			Peter Jones <p@dancris.com>
#
# $FreeBSD$
#

PORTNAME=	chbg
PORTVERSION=	1.5
PORTREVISION=	4
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.idata.sk/~ondrej/sw/
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Change Background Picture with time period

USE_X_PREFIX=	yes
USE_GNOME=	gdkpixbuf
USE_GMAKE=	yes
USE_REINPLACE=	yes
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
