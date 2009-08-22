# New ports collection makefile for:	mcal
# Date created:		Mon Oct 15 14:13:23 GMT 2001
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	mcal
PORTVERSION=	0.3
CATEGORIES=	deskutils
MASTER_SITES=	SF/lib${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	thierry@pompo.net
COMMENT=	A libmcal powered cal replacement

LIB_DEPENDS=	mcal.0:${PORTSDIR}/misc/libmcal

WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
	@${ECHO} "*****************************************************************************"
	@${ECHO} ""
	@${ECHO} " mcal has been installed in ${PREFIX}/mcal."
	@${ECHO} ""
	@${ECHO} "*****************************************************************************"

.include <bsd.port.mk>
