# New ports collection makefile for:	linux-sunbird
# Date created:		2004-09-17
# Whom:			voisine
#
# $FreeBSD$
#

PORTNAME=	sunbird
DISTVERSION=	0.9
PORTREVISION=	1
DISTVERSIONSUFFIX=	.en-US.linux-i686
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	deskutils
MASTER_SITE_SUBDIR?=	calendar/${PORTNAME}/releases/${DISTVERSION}/linux-i686/en-US

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Calendaring application branched from Mozilla

DEPRECATED=	Upstream development discontinued. Please consider using\
		${PORTSDIR}/deskutils/lightning instead
EXPIRATION_DATE=	2010-09-04

post-extract:
	@${MKDIR} ${WRKSRC}/plugins/
	@${TOUCH} ${WRKSRC}/plugins/.empty

.include "${.CURDIR}/../../www/linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
