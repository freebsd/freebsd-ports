# New ports collection makefile for:	tuxpaint-stamps
# Date created:				15 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxpaint
DISTVERSION=	2004.10.03
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-stamps
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}-i386-1
EXTRACT_SUFX=	.tgz

MAINTAINER=	alejandro@varnet.biz
COMMENT=	TuxPaint Stamps

RUN_DEPENDS=	tuxpaint:${PORTSDIR}/games/tuxpaint

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/usr/local/share/tuxpaint

post-extract:
# Remove CVS directories
	@${FIND} ${WRKSRC} -type d -name CVS -print0 | \
		${XARGS} -0 ${RM} -rf

# cartoon/tux is already included with tuxpaint itself
	@${RM} -rf ${WRKSRC}/cartoon/tux

do-install:
	@${CP} -R ${WRKSRC}/stamps ${DATADIR}

.include <bsd.port.mk>
