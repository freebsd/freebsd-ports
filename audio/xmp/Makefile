# New ports collection makefile for: 	xmp
# Date created:		18 September 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xmp
PORTVERSION=	2.0.2
CATEGORIES=	audio
MASTER_SITES=	http://xmp.helllabs.org/pkg/%SUBDIR%/ \
		http://xmp.linuxave.net/pkg/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	anders@fix.no

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa

MAN1=		xmp.1
MLINKS=		xmp.1 xxmp.1

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/docs/xmp.1

.include <bsd.port.mk>
