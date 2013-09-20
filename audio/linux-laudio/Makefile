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

USE_BZIP2=	yes
NO_STAGE=	yes

NO_BUILD=	yes

PLIST_FILES=	bin/laudio
PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/la ${PREFIX}/bin/laudio
	${BRANDELF} -t Linux ${PREFIX}/bin/laudio
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/readme.txt ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
