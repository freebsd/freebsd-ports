# New ports collection makefile for:   wmfmixer
# Date created:        21 June 2002
# Whom:                Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmfmixer
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	audio windowmaker afterstep
MASTER_SITES=	http://www.finik.net/files/ \
		http://www.linuks.mine.nu/dockapp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An audio mixer for the WindowMaker dock

PLIST_FILES=	bin/wmfmixer
USE_GMAKE=	yes
USE_XPM=	yes
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
