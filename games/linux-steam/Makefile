# New ports collection makefile for:   hlstats
# Date created:        29 December 2003
# Whom:                hideki
#
# $FreeBSD$
#

PORTNAME=	steam
PORTVERSION=	1.0
PORTREVISOIN=	2
CATEGORIES=	games linux
MASTER_SITES=	http://www.coreblack.com/files/
PKGNAMEPREFIX=	linux-

MAINTAINER=	hido@coreblack.com
COMMENT=	Half Life dedicated server running on steam

IS_INTERACTIVE=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

INSTALLDIR?=	steam

PLIST_SUB+=	INSTALLDIR=${INSTALLDIR}

pre-everything::
	@ ${ECHO_MSG} "You can use the INSTALLDIR option to change the install dir"

do-build:
	@ ${CHMOD} +x ${WRKDIR}/hldsupdatetool.bin && cd ${WRKDIR} && ./hldsupdatetool.bin
	@ ${CAT} pkg-message | ${SED} 's|%%PREFIX%%|${PREFIX}|' > ${PKGMESSAGE}

do-install:
	@ ${MKDIR} ${PREFIX}/${INSTALLDIR}
	@ ${CP} ${WRKDIR}/${PORTNAME} ${PREFIX}/${INSTALLDIR}/
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
