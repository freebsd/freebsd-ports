# Created by: Juha Erkkilä <erkkila@cc.jyu.fi>
# $FreeBSD$

PORTNAME=	etktab
PORTVERSION=	3.2
PORTREVISION=	2
CATEGORIES=	audio tcl tk
MASTER_SITES=	SF/${PORTNAME}/eTktab/${PORTVERSION} \
		SF/${PORTNAME}/keyboard%20layout%20support/${PORTVERSION}:keyboard
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Guitar tablature editor

OPTIONS_DEFINE=	DOCS

USES+=		tk
NO_BUILD=	yes
NO_STAGE=	yes
WRKSRC=		${WRKDIR}/eTktab-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	canada_multi-3.2.etk:keyboard \
		dvorak-3.2.etk:keyboard \
		uk-3.2.etk:keyboard \
		us-3.2.etk:keyboard
.endif

post-patch:
	${REINPLACE_CMD} -e 's|wish8.4|${WISH}|g' ${WRKSRC}/eTktab

post-extract:
.for FILE in canada_multi-3.2.etk dvorak-3.2.etk uk-3.2.etk us-3.2.etk
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${FILE} ${WRKSRC}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/eTktab ${PREFIX}/bin/etktab
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for FILE in CHANGES.html LICENSE.html README.html eTktab-small.xpm eTktab.xpm \
		canada_multi-3.2.etk dvorak-3.2.etk uk-3.2.etk us-3.2.etk
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
