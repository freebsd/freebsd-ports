# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	laudio
PORTVERSION=	0.4
CATEGORIES=	audio linux
MASTER_SITES=	http://www.lossless-audio.com/ CENKES
PKGNAMEPREFIX=	linux-
DISTNAME=	la04

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free lossless audio codec

ONLY_FOR_ARCHS=	amd64 i386

USES=		tar:bzip2
USE_LINUX=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/laudio
PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${BRANDELF} -t Linux ${WRKDIR}/la
	${INSTALL_PROGRAM} ${WRKDIR}/la ${STAGEDIR}${PREFIX}/bin/laudio
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
