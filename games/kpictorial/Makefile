# New ports collection makefile for:	kpictorial
# Date created:				2003-10-13
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kpictorial
PORTVERSION=	0.9.1
PORTREVISION=	7
CATEGORIES=	games kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Little logical game for KDE

USE_KDELIBS_VER=	3
USE_AUTOTOOLS=		libtool:22
USE_GMAKE=		yes

post-patch:
	${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS}," ${WRKSRC}/configure

.include <bsd.port.mk>
