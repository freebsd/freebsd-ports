# New ports collection makefile for:	ksetispy
# Date created:		Sat Jan  5 14:44:45 BRST 2002
# Whom:		Hammurabi Mendes <hmendes@brturbo.com>
#
# $FreeBSD$
#

PORTNAME=	ksetispy
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	astro kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitors the progress of the SETI@home client

USE_BZIP2=	yes
USE_KDEBASE_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
