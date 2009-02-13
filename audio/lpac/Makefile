# New ports collection makefile for:	lpac
# Date created:		22 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lpac
PORTVERSION=	1.40
CATEGORIES=	audio linux
MASTER_SITES=	CENKES

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Lossless audio codec

ONLY_FOR_ARCHS=	amd64 i386

NO_CDROM=	No commercial use
NO_BUILD=	yes
USE_LINUX=	yes
PLIST_FILES=	bin/lpac

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/lpac ${PREFIX}/bin/
	@${BRANDELF} -t Linux ${PREFIX}/bin/lpac

.include <bsd.port.mk>
