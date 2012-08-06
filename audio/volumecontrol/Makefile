# New ports collection makefile for:    volumecontrol.app
# Date created:         28 Aug 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	volumecontrol
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	audio gnustep
MASTER_SITES=	http://gnu.ethz.ch/linuks.mine.nu/volumecontrol/ \
		${MASTER_SITE_GNUSTEP_CH}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio mixer for GNUstep

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|linux/soundcard.h|sys/soundcard.h|g' \
		${WRKSRC}/AppController.m

.include <bsd.port.mk>
