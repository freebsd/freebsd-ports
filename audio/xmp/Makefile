# New ports collection makefile for: 	xmp
# Version required:	xmp-2.0.0-pre
# Date created:		18 September 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

DISTNAME=	xmp-2.0.0-pre
PKGNAME=	xmp-2.0.0
CATEGORIES=	audio
MASTER_SITES=	http://xmp.helllabs.org/pkg/2.0.0/ \
		http://xmp.linuxbox.com/pkg/2.0.0/

MAINTAINER=	anders@fix.no

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-alsa

USE_XLIB=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

CFLAGS+=          -DHAVE_SYS_RTPRIO_H

MAN1=		xmp.1 xxmp.1

.include <bsd.port.mk>
