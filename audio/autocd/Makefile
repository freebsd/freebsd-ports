# New ports collection makefile for:	 autocd
# Date created:		11 Marth 2003
# Whom:			Dmitry Afanasiev <KOT@MATPOCKuH.Ru>
#
# $FreeBSD$
#

PORTNAME=	autocd
PORTVERSION=	3.00.02a
CATEGORIES=	audio sysutils
MASTER_SITES=	ftp://kot.spb.ru/pub/src/projects/autocd/

MAINTAINER=	KOT@MATPOCKuH.Ru
COMMENT=	Compact disc control utility

USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/Makefile

MAN1=		autocd.1 cdctl.1

.include	<bsd.port.mk>
