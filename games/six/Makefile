# New ports collection Makefile for:	six
# Date created: 			2003-0-1-26
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	six
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	games kde
MASTER_SITES=	http://six.retes.hu/download/

MAINTAINER=	ports@freebsd.org
COMMENT=	KDE HEX clone

USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

post-patch:
	${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS}," ${WRKSRC}/configure


.include <bsd.port.mk>
