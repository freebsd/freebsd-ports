# New ports collection makefile for:	xmixer
# Version required:	0.9.3
# Date created:		27 October 1999
# Whom:			trevor@jpj.net
#
# $FreeBSD$
#

DISTNAME=	xmixer-0.9.3
CATEGORIES=	audio
MASTER_SITES=	http://www.hdk-berlin.de/~rasca/
MASTER_SITE_SUBDIR=	apps/sound/mixers

MAINTAINER=	trevor@jpj.net

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

WRKSRC=		${WRKDIR}/xmixer

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		xmixer.1

post-extract:
	@${RM} ${WRKSRC}/config.cache

.include <bsd.port.mk>
