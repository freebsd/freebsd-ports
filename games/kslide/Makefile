# New ports collection Makefile for:	kslide
# Date created:				2004-01-23
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kslide
PORTVERSION=	1.0.1
PORTREVISION=	6
CATEGORIES=	games kde
MASTER_SITES=	http://david.bieder.free.fr/eric/taquin/ \
		http://perso.orange.fr/coquelle/taquin/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	KDE puzzle game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_GETTEXT=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
