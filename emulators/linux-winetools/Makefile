# New ports collection makefile for:	linux-winetools
# Date created:				4 September 2002
# Whom:					Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	winetools
PORTVERSION=	1.20
CATEGORIES=	emulators linux
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/winetools/}
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION}.setup.sh
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	blackend@FreeBSD.org

RUN_DEPENDS=	wine:${PORTSDIR}/emulators/wine

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes

BRANDELF?=	/usr/bin/brandelf
STRIP=

post-extract:
	@${TAIL} +179 ${DISTDIR}/${DISTFILES} | ${TAR} -xzf - -C ${WRKDIR} ${PORTNAME}
	@${BRANDELF} -t Linux ${WRKDIR}/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
