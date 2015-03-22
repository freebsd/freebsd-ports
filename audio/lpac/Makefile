# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lpac
PORTVERSION=	1.40
CATEGORIES=	audio linux
MASTER_SITES=	CENKES \
		ftp://relay1.tomsk.gov.ru/pub/FreeBSD/ports/distfiles/ \
		ftp://ftp.itsinternet.net/pub/FreeBSD/ports/distfiles/ \
		ftp://chernabog.cc.vt.edu/pub2/freebsd/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lossless audio codec

ONLY_FOR_ARCHS=	amd64 i386

NO_CDROM=	No commercial use
NO_BUILD=	yes
USE_LINUX=	yes
PLIST_FILES=	bin/lpac

do-install:
	${BRANDELF} -t Linux ${WRKDIR}/lpac
	${INSTALL_PROGRAM} ${WRKDIR}/lpac ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
