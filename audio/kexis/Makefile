# New ports collection makefile for:	kexis
# Date created:		22 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kexis
PORTVERSION=	0.2.2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Kexis/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Lossless WAV file compressor

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/kexis

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kexis ${PREFIX}/bin/

.include <bsd.port.mk>
