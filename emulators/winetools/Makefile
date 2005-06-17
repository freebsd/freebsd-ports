# New ports collection makefile for:	linux-winetools
# Date created:				4 September 2002
# Whom:					Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	winetools
PORTVERSION=	1.25a
PORTREVISION=	2
CATEGORIES=	emulators linux
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/winetools/}
PKGNAMEPREFIX=	linux-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A setup and configuration tool for WINE

RUN_DEPENDS=	wine:${PORTSDIR}/emulators/wine

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes
ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/winetools

post-extract:
	@${BRANDELF} -t Linux ${WRKDIR}/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
