# New ports collection makefile for:	kbibtex
# Date created:				Mon Aug  8 18:43:04 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kbibtex
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	databases kde
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~fischer/${PORTNAME}/download/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	BibTeX editor for KDE

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

MAN1=		kbibtex.1

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
