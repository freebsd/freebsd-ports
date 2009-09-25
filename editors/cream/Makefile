# New ports collection makefile for:	cream
# Date created:				2004-08-25
# Whom:					Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	cream
PORTVERSION=	0.42
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/Cream/${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Gvim extension with many features

RUN_DEPENDS=	${LOCALBASE}/bin/gvim:${PORTSDIR}/editors/vim

NO_BUILD=	yes
PLIST_SUB=	VIMRUNTIME="${VIMRUNTIME:S/${PREFIX}\///}"

.include <bsd.port.pre.mk>

VIMRUNTIME!=	cd ${PORTSDIR}/editors/vim && ${MAKE} -V DATADIR

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cream ${PREFIX}/bin
	${MKDIR} ${VIMRUNTIME}/cream
	${INSTALL_DATA} ${WRKSRC}/creamrc ${WRKSRC}/*.vim ${VIMRUNTIME}/cream
.for f in addons bitmaps help lang
	${MKDIR} ${VIMRUNTIME}/cream/${f}
	${INSTALL_DATA} ${WRKSRC}/${f}/* ${VIMRUNTIME}/cream/${f}
.endfor
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/cream.png ${WRKSRC}/cream.svg \
		${PREFIX}/share/pixmaps
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/cream.desktop ${PREFIX}/share/applications
.if !defined(NOPORTDOCS)
.for f in docs docs-html
	${MKDIR} ${DOCSDIR}/${f}
	${INSTALL_DATA} ${WRKSRC}/${f}/* ${DOCSDIR}/${f}
.endfor
.endif

.include <bsd.port.post.mk>
