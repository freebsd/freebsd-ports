# Created by: Andrey Chernov <ache@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zip
PORTVERSION=	3.0
CATEGORIES=	archivers
MASTER_SITES=	SF/info${PORTNAME}/Zip%203.x%20%28latest%29/${PORTVERSION} \
		http://www.skysmurf.nl/comp/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	freebsd@skysmurf.nl
COMMENT=	Create/update ZIP files compatible with PKZIP

# License is BSD-based, but not identical, so intall with documentation
LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS

MAKEFILE=	unix/Makefile
ALL_TARGET=	generic

PLIST_FILES=	bin/zip bin/zipcloak bin/zipnote bin/zipsplit \
		man/man1/zip.1.gz man/man1/zipcloak.1.gz \
		man/man1/zipnote.1.gz man/man1/zipsplit.1.gz
PORTDOCS=	*

do-install:
.for p in ${PLIST_FILES:Mbin*:T}
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${p}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGES README* TODO WHATSNEW WHERE ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
