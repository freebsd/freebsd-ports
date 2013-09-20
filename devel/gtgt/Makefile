# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtgt
PORTVERSION=	3.2.0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General (or GNU) template generation tools

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes

PORTDOCS=	autoconf.html automake.html \
		company-license.long company-license.short \
		gtgt.gif gtgt.html gtgt.txt \
		index.html libtool.html
PLIST_FILES=	${SCRIPTS:S/^/bin\//}

SCRIPTS=	gcng gptg gscg

NO_STAGE=	yes
post-patch:
.for file in ${SCRIPTS}
	@${REINPLACE_CMD} -e \
		's|^#!.*|#!${LOCALBASE}/bin/bash|g' ${WRKSRC}/scripts/${file}
.endfor

do-install:
.for file in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
