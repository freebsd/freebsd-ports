# New ports collection makefile for:	kalbum
# Date created:			Tue Jul  1 18:03:44 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kalbum
PORTVERSION=		0.8.0
PORTREVISION=	10
CATEGORIES=		graphics kde
MASTER_SITES=		http://www.paldandy.com/kalbum/data/${PORTNAME}-${PORTVERSION}/

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Create albums from a collection of images

DEPRECATED=		Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g; s/-lpthread/${PTHREAD_LIBS}/g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
