# New ports collection makefile for:	Info-ZIP
# Date created:				22 Dec 1994
# Whom:					Andrey Chernov <ache@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zip
PORTVERSION=	3.0
CATEGORIES=	archivers
MASTER_SITES=	SF/info${PORTNAME}/Zip%203.x%20%28latest%29/${PORTVERSION} \
		ftp://ftp.skysmurf.nl/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	freebsd@skysmurf.nl
COMMENT=	Create/update ZIP files compatible with PKZIP

MAKEFILE=	unix/Makefile
ALL_TARGET=	generic

PLIST_FILES=	bin/zip bin/zipcloak bin/zipnote bin/zipsplit
MAN1=		zip.1 zipcloak.1 zipnote.1 zipsplit.1
PORTDOCS=	*


do-install:
.for p in ${PLIST_FILES:T}
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${p}.1 ${MANPREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
# License is BSD-based, but not identical, so intall with documentation
. for d in CHANGES LICENSE README* TODO WHATSNEW WHERE
	${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
