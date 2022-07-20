PORTNAME=	ko.TeX-fonts-base
PORTVERSION=	0.1.0.20070927
PORTREVISION=	6
CATEGORIES=	korean print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/ko.TeX/current/
DISTNAME=	ko.tex-unfonts-base-20070927

MAINTAINER=	hyogeollee@gmail.com
COMMENT=	Korean TeX base fonts

USE_TEX=	dvipsk latex
CONFLICTS=	hlatex

NO_BUILD=	yes

NO_WRKSUBDIR=	yes

TEXMF=		${PREFIX}/share/texmf-local
TEXMF_FONTS=	${TEXMF}/fonts
TEXMF_TEX=	${TEXMF}/tex

PORTDOCS=	COPYING LICENSE MANIFEST

OPTIONS_DEFINE=	DOCS

do-install:
	(cd ${WRKSRC}/fonts && ${COPYTREE_SHARE} . ${STAGEDIR}${TEXMF_FONTS})
	(cd ${WRKSRC}/tex && ${COPYTREE_SHARE} . ${STAGEDIR}${TEXMF_TEX})
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-local -not -type d | ${SORT} | \
		  ${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-local -type d -empty | ${SORT} -r | \
		  ${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
