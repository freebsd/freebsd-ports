# New ports collection makefile for:   hlstats
# Date created:        29 December 2003
# Whom:                hideki
#
# $FreeBSD$
#

PORTNAME=	steam
PORTVERSION=	1.0
CATEGORIES=	games linux
MASTER_SITES=	http://hlstats.neojapangz.com/files/

MAINTAINER=	hido@neojapangz.com
COMMENT=	Half Life dedicated server running on steam

IS_INTERACTIVE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_LINUX=	yes

do-build:
	@ ${CHMOD} +x ${WRKDIR}/hldsupdatetool.bin && cd ${WRKDIR} && ./hldsupdatetool.bin
	@ ${CAT} pkg-message | ${SED} 's|%%PREFIX%%|${PREFIX}|' > ${PKGMESSAGE}

do-install:
	@ ${MKDIR} ${PREFIX}/${PORTNAME}
	@ ${CP} ${WRKDIR}/${PORTNAME} ${PREFIX}/${PORTNAME}/
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
