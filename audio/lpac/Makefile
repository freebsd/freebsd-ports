# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lpac
PORTVERSION=	1.40
CATEGORIES=	audio linux
MASTER_SITES=	CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lossless audio codec

ONLY_FOR_ARCHS=	amd64 i386

NO_CDROM=	No commercial use
NO_BUILD=	yes
USE_LINUX=	yes
NO_STAGE=	yes
PLIST_FILES=	bin/lpac

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/lpac ${PREFIX}/bin/
	@${BRANDELF} -t Linux ${PREFIX}/bin/lpac

.include <bsd.port.mk>
