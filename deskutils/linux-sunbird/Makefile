# New ports collection makefile for:	linux-sunbird
# Date created:		2004-09-17
# Whom:			voisine
#
# $FreeBSD$
#

PORTNAME=	sunbird
PORTVERSION=	0.3.1
DISTVERSIONSUFFIX=	.en-US.linux-i686
PORTEPOCH=	1
CATEGORIES=	deskutils
MASTER_SITE_SUBDIR?=	calendar/${PORTNAME}/releases/${DISTVERSION}/linux-i686/en-US

MAINTAINER=	voisine@gmail.com
COMMENT=	Calendaring application branched from Mozilla

USE_BZIP2=	yes

post-extract:
	@${MKDIR} ${WRKSRC}/plugins/
	@${TOUCH} ${WRKSRC}/plugins/.empty
	@${RM} -rf ${WRKSRC}/updates

.include "${.CURDIR}/../../www/linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
