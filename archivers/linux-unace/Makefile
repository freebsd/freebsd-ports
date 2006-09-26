# New ports collection makefile for: linunace
# Date created:		9 November 2005
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	unace
PORTVERSION=	2.5
PORTEPOCH=	1
CATEGORIES=	archivers linux
MASTER_SITES=	http://www.winace.com/files/ CSME
PKGNAMEPREFIX=	linux-
DISTNAME=	lin${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Extract, view & test ACE archives

RESTRICTED=	Distribution is permitted within the original package only
DEPRECATED=		security issues
EXPIRATION_DATE=	2006-10-26

ONLY_FOR_ARCHS=	amd64 i386
NO_BUILD=	yes
PLIST_FILES=	bin/linunace
PORTDOCS=	licence
STRIP=

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/unace ${PREFIX}/bin/linunace
	${BRANDELF} -t Linux ${PREFIX}/bin/linunace
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/licence ${DOCSDIR}
.endif

.include <bsd.port.mk>
