PORTNAME=	ko.TeX-fonts-extra
PORTVERSION=	0.1.0
PORTREVISION=	6
CATEGORIES=	korean print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/ko.TeX/extrafonts/
DISTFILES=	ko.tex-extra-hlfont.tar.gz \
		ko.tex-unfonts-extra.tar.gz

MAINTAINER=	hyogeollee@gmail.com
COMMENT=	Korean TeX extra fonts

USE_TEX=	dvipsk latex
CONFLICTS=	hlatex

NO_BUILD=	yes

NO_WRKSUBDIR=	yes

TEXMF=		${PREFIX}/share/texmf-local
TEXMF_FONTS=	${TEXMF}/fonts
TEXMF_TEX=	${TEXMF}/tex

OPTIONS_DEFINE=	DOCS

PORTDOCS=	fonts/*

do-install:
	(cd ${WRKSRC}/fonts && ${COPYTREE_SHARE} . ${STAGEDIR}${TEXMF_FONTS})
	(cd ${WRKSRC}/tex && ${COPYTREE_SHARE} . ${STAGEDIR}${TEXMF_TEX})
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-local -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/share/texmf-local -type d -empty | ${SORT} -r | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
