# New ports collection makefile for:	xopps
# Version required:	1.13
# Date created:		1 Ag 1997
# Whom:			Pedro Giffuni (orig)
#
# $FreeBSD$
#

DISTNAME=	xopps.1.13
PKGNAME=	xopps-1.13
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp.weird.com/pub/mirror/ \
		ftp://devvax.jpl.nasa.gov/pub/xopps/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=
USE_X_PREFIX=	yes
REQUIRES_MOTIF=	yes
MAKE_ENV=	'MACH=${OPSYS}'

MAN1=	xopps.1

post-extract:
	@${CP} ${WRKSRC}/Defines.spr ${WRKSRC}/Defines.${OPSYS}

post-patch:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/*.c

.include <bsd.port.mk>
