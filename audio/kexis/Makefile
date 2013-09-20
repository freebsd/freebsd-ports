# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kexis
PORTVERSION=	0.2.2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Kexis/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lossless WAV file compressor

NO_STAGE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/kexis

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kexis ${PREFIX}/bin/

.include <bsd.port.mk>
