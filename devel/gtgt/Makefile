# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtgt
PORTVERSION=	3.2.0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General (or GNU) template generation tools

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		shebangfix
NO_BUILD=	yes

PORTDOCS=	autoconf.html automake.html \
		company-license.long company-license.short \
		gtgt.gif gtgt.html gtgt.txt \
		index.html libtool.html
PLIST_FILES=	${SCRIPTS:S/^/bin\//}

SHEBANG_FILES=	scripts/gcng scripts/gptg scripts/gscg

OPTIONS_DEFINE=	DOCS

do-install:
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
