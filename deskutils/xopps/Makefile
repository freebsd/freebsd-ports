# New ports collection makefile for:	xopps
# Date created:		1 Ag 1997
# Whom:			Pedro Giffuni (orig)
#
# $FreeBSD$
#

PORTNAME=	xopps
PORTVERSION=	1.13
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp.weird.com/pub/mirror/ \
		http://dl.droso.net/ports/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool which lets you draw Gantt charts

ALL_TARGET=
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_MOTIF=	yes
MAKE_ENV=	'MACH=${OPSYS}'

MAN1=	xopps.1

post-extract:
	@${CP} ${WRKSRC}/Defines.spr ${WRKSRC}/Defines.${OPSYS}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/*.c

.include <bsd.port.mk>
