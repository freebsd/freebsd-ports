# New ports collection makefile for:	digikamimageplugins
# Date created: 			7 November 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	digikamimageplugins
DISTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	digikam

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Collection of image editor plugins for Digikam

LIB_DEPENDS=	digikam.0:${PORTSDIR}/graphics/digikam

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_KDELIBS_VER=3
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g;s|-fno-schedule-insns -fno-inline||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/configure

.include <bsd.port.mk>
