# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	optimfrog
DISTVERSION=	4.520b1
CATEGORIES=	audio linux
MASTER_SITES=	http://www.losslessaudio.org/DownloadNew/OptimFROG_All_Linux_x86_${DISTVERSION:S/.//}.php?
DISTNAME=	OptimFROG_All_Linux_x86_${DISTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lossless audio codec

ONLY_FOR_ARCHS=	amd64 i386

NO_CDROM=	No commercial use
NO_BUILD=	yes
USES=		zip
USE_LINUX=	yes
PLIST_FILES=	bin/off bin/ofr bin/ofs
FETCH_ARGS=	-o ${DISTDIR}/${DISTFILES}

do-install:
	@${BRANDELF} -t Linux ${WRKSRC}/off ${WRKSRC}/ofr ${WRKSRC}/ofs
	@${INSTALL_PROGRAM} ${WRKSRC}/off ${WRKSRC}/ofr ${WRKSRC}/ofs ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
