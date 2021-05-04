# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>

PORTNAME=	lpac
PORTVERSION=	1.40
CATEGORIES=	audio linux
MASTER_SITES=	ftp://chernabog.cc.vt.edu/pub2/freebsd/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lossless audio codec

ONLY_FOR_ARCHS=	amd64 i386

# Converted from NO_CDROM
LICENSE=	LPAC
LICENSE_NAME=	lpac
LICENSE_TEXT=	No commercial use
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

NO_BUILD=	yes
USES=		linux
PLIST_FILES=	bin/lpac

do-install:
	${BRANDELF} -t Linux ${WRKDIR}/lpac
	${INSTALL_PROGRAM} ${WRKDIR}/lpac ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
