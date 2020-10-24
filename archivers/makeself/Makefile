# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	makeself
PORTVERSION=	2.4.2
DISTVERSIONPREFIX=	release-
CATEGORIES=	archivers

MAINTAINER=	ed.arrakis@gmail.com
COMMENT=	Neat script to make self-extracting archives

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	megastep

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/makeself bin/makeself-header \
		bin/makeself-header.sh bin/makeself.sh \
		man/man1/makeself.1.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
.for i in makeself makeself-header
	${INSTALL_SCRIPT} ${WRKSRC}/${i}.sh ${STAGEDIR}${PREFIX}/bin
	@${LN} -sf ${i}.sh ${STAGEDIR}${PREFIX}/bin/${i}
.endfor
	${INSTALL_MAN} ${WRKSRC}/makeself.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
