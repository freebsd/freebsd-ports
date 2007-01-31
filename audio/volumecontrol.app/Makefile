# New ports collection makefile for:    volumecontrol.app
# Date created:         28 Aug 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	volumecontrol
PORTVERSION=	0.5
CATEGORIES=	audio gnustep
MASTER_SITES=	http://www.linuks.mine.nu/volumecontrol/ \
		${MASTER_SITE_GNUSTEP_CH}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Audio mixer for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:C/\.app//}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile on 4.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|linux/soundcard.h|sys/soundcard.h|g' \
		${WRKSRC}/AppController.m

.include <bsd.port.post.mk>
