# New ports collection Makefile for:	kslide
# Date created:				2004-01-23
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kslide
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games kde
MASTER_SITES=	http://www.web-xs.de/~ecoquelle/taquin/ \
		http://david.bieder.free.fr/eric/taquin/ \
		http://perso.wanadoo.fr/coquelle/taquin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE puzzle game

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
