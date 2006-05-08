# New ports collection makefile for:	laudio
# Date created:		18 October 2005
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	laudio
PORTVERSION=	0.4
CATEGORIES?=	audio linux
MASTER_SITES=	http://www.lossless-audio.com/ \
		http://www.csme.ru/filez/
DISTNAME=	la04

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A free lossless audio codec

ONLY_FOR_ARCHS=	amd64 i386
USE_BZIP2=	yes

NO_BUILD=	yes
PLIST_FILES=	bin/laudio
PORTDOCS=	readme.txt

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/la ${PREFIX}/bin/laudio
	@${BRANDELF} -t Linux ${PREFIX}/bin/laudio
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/readme.txt ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
