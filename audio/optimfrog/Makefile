# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	optimfrog
DISTVERSION=	4.520b1
CATEGORIES=	audio linux
MASTER_SITES=	CENKES
DISTNAME=	OptimFROG_All_Linux_x86_${DISTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lossless audio codec

ONLY_FOR_ARCHS=	amd64 i386

NO_CDROM=	No commercial use
NO_BUILD=	yes
USE_LINUX=	yes
NO_STAGE=	yes
USE_ZIP=	yes
PLIST_FILES=	bin/off bin/ofr bin/ofs

do-install:
	@${BRANDELF} -t Linux ${WRKSRC}/off ${WRKSRC}/ofr ${WRKSRC}/ofs
	@${INSTALL_PROGRAM} ${WRKSRC}/off ${WRKSRC}/ofr ${WRKSRC}/ofs ${PREFIX}/bin/

.include <bsd.port.mk>
