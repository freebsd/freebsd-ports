# New ports collection makefile for:    zip
# Date created:		22 Dec 1994
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	zip
PORTVERSION=	3.0
CATEGORIES=	archivers
MASTER_SITES=	SF/info${PORTNAME}/Zip%203.x%20%28latest%29/${PORTVERSION}
DISTFILES=	${PORTNAME}30${EXTRACT_SUFX}
USE_ZIP=	yes

MAINTAINER=	ache@FreeBSD.org
COMMENT=	Create/update ZIP files compatible with pkzip

WRKSRC=		${WRKDIR}/${PORTNAME}30
MAKEFILE=	unix/Makefile
ALL_TARGET=	generic
MAN1=		zip.1 zipcloak.1 zipnote.1 zipsplit.1

PLIST_FILES=	\
	bin/zip \
	bin/zipcloak \
	bin/zipnote \
	bin/zipsplit

do-install:
.for file in zip zipcloak zipnote zipsplit
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${file}.1 ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
