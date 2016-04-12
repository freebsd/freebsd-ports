# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtgt
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General (or GNU) template generation tools

RUN_DEPENDS=	bash:shells/bash

LICENSE=	GPLv2+ # though COPYING has GPLv3

USES=		shebangfix
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	autoconf.html automake.html \
		company-license.long company-license.short \
		gtgt.gif gtgt.html gtgt.txt \
		index.html libtool.html
SCRIPTS=	gcng gptg gscg

PLIST_FILES=	${SCRIPTS:S/^/bin\//}
SHEBANG_FILES=	${SCRIPTS:S/^/scripts\//}

OPTIONS_DEFINE=	DOCS

do-install:
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
