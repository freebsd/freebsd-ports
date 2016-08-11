# Created by: Juha Erkkilä <erkkila@cc.jyu.fi>
# $FreeBSD$

PORTNAME=	etktab
PORTVERSION=	3.2
PORTREVISION=	3
CATEGORIES=	audio tcl tk
MASTER_SITES=	SF/${PORTNAME}/eTktab/${PORTVERSION} \
		SF/${PORTNAME}/keyboard%20layout%20support/${PORTVERSION}:keyboard
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Guitar tablature editor

USES=		tk
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/eTktab-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*

DOCS_DISTFILES=	canada_multi-3.2.etk:keyboard \
		dvorak-3.2.etk:keyboard \
		uk-3.2.etk:keyboard \
		us-3.2.etk:keyboard

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|wish|${WISH}|g' ${WRKSRC}/eTktab

post-extract-DOCS-on:
.for FILE in canada_multi-3.2.etk dvorak-3.2.etk uk-3.2.etk us-3.2.etk
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${FILE} ${WRKSRC}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/eTktab ${STAGEDIR}${PREFIX}/bin/etktab

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in CHANGES.html LICENSE.html README.html eTktab-small.xpm eTktab.xpm \
		canada_multi-3.2.etk dvorak-3.2.etk uk-3.2.etk us-3.2.etk
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
