# New ports collection makefile for:	knight
# Date created:		24 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	knights
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	knights

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A KDE chess interface (gnuchess/crafty)

RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty

USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	XML2POT=${TRUE} PO2XML=${TRUE}

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
