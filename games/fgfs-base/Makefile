# New ports collection makefile for:	flightgear
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=	fgfs-base
PORTVERSION=	0.9.8
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Shared/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Shared/

MAINTAINER=	des@FreeBSD.org
COMMENT=	FlightGear scenery, textures and aircraft models

NO_BUILD=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/data
DATADIR=	${PREFIX}/share/FlightGear

post-extract:
	@${FIND} ${WRKSRC} \( -name '.#*' -or -name '*~' \) -print -delete

do-install:
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 0755 ${DATADIR}
	@(cd ${WRKSRC} && ${FIND} . -type d | (cd ${DATADIR} &&\
		${XARGS} ${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 0755))
	@(cd ${WRKSRC} && ${FIND} . -type f |\
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR})

.include <bsd.port.mk>
