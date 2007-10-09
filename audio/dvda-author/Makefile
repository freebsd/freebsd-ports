# New ports collection makefile for:   dvda-author
# Date created:        9 October 2007
# Whom:                dieringe@zedat.fu-berlin.de
#
# $FreeBSD$
#

PORTNAME=	dvda-author
PORTVERSION=	20050703
CATEGORIES=	audio
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	dvd-audio

MAINTAINER=	dieringe@zedat.fu-berlin.de
COMMENT=	Author and playback unencrypted and uncompressed Audio-DVDs

USE_ZIP=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	bin/dvda-author

do-install:
	${INSTALL} ${WRKSRC}/dvda-author ${PREFIX}/bin

.include <bsd.port.mk>
