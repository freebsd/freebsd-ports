# New ports collection makefile for:	digikamimageplugins
# Date created: 			7 November 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	digikamimageplugins
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	digikam

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	Collection of image editor plugins for Digikam

LIB_DEPENDS=	digikam.0:${PORTSDIR}/graphics/digikam

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_KDELIBS_VER=3
CONFIGURE_ARGS+=--program-prefix=''

pre-configure::
	${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/configure

.include <bsd.port.mk>
