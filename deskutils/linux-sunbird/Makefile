# New ports collection makefile for:	linux-sunbird
# Date created:		2004-09-17
# Whom:			voisine
#
# $FreeBSD$
#

PORTNAME=	sunbird
DISTVERSION=	0.5rc3
DISTVERSIONSUFFIX=	.en-US.linux-i686
PORTEPOCH=	1
CATEGORIES=	deskutils
MASTER_SITE_SUBDIR?=	calendar/${PORTNAME}/releases/${DISTVERSION}/linux-i686/en-US
DISTNAME=	${PORTNAME}-0.5${DISTVERSIONSUFFIX}
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Calendaring application branched from Mozilla

post-extract:
	@${MKDIR} ${WRKSRC}/plugins/
	@${TOUCH} ${WRKSRC}/plugins/.empty
	@${RM} -rf ${WRKSRC}/updates

.include "${.CURDIR}/../../www/linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
