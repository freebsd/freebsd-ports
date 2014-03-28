# Created by: hideki
# $FreeBSD$

PORTNAME=	steam
PORTVERSION=	1.1
CATEGORIES=	games linux
MASTER_SITES=	http://storefront.steampowered.com/download/
PKGNAMEPREFIX=	linux-
DISTNAME=	hldsupdatetool.bin
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	chris@easymac.org
COMMENT=	Half Life and Source dedicated server using steam

BUILD_DEPENDS=	${LINUX_BASE_PORT}

IS_INTERACTIVE=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs

INSTALLDIR?=	steam

SUB_FILES=	pkg-message
SUB_LIST=	INSTALLDIR=${PREFIX}/${INSTALLDIR}
PLIST_SUB+=	INSTALLDIR=${INSTALLDIR}

pre-everything::
	@${ECHO_MSG} "You can use the INSTALLDIR option to change the install directory."

do-build:
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}
	@${BRANDELF} -t Linux ${WRKDIR}/${DISTFILES}
	@${CHMOD} +x ${WRKDIR}/${DISTFILES} && cd ${WRKDIR} && ./${DISTFILES}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${INSTALLDIR}
	@${CP} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/${INSTALLDIR}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
