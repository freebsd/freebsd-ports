# Created by: Hyogeol Lee <hyogeollee@gmail.com>
# $FreeBSD$

PORTNAME=	ko.TeX
PORTVERSION=	0.1.1.20080329
PORTREVISION=	5
CATEGORIES=	korean print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/ko.TeX/current/
DISTNAME=	ko.tex-macro-20080329

MAINTAINER=	hyogeollee@gmail.com
COMMENT=	Korean TeX macro and utilities

RUN_DEPENDS=	${BASE_MAP}:korean/ko.TeX-fonts-base

USES=		shebangfix
SHEBANG_FILES=	util/*.pl
USE_TEX=	latex
CONFLICTS=	hlatex-[0-9]*

NO_WRKSUBDIR=	yes

TEXMF=		${PREFIX}/share/texmf-local
BASE_MAP=	${LOCALBASE}/share/texmf-local/fonts/map/dvips/kotex/base/kotex-base.map
KOTEX_BIBTEX=	${TEXMF}/bibtex/bst/kotex
KOTEX_DOC=	${TEXMF}/doc/latex/kotex
KOTEX_LATEX=	${TEXMF}/tex/latex/kotex
KOTEX_MKIDX=	${TEXMF}/makeindex/kotex
KOTEX_PLAIN=	${TEXMF}/tex/plain/kotex
KOTEX_SFD=	${TEXMF}/fonts/sfd
KOTEX_UTIL=	${TEXMF}/scripts/kotex/perl
TEXHASH=	${PREFIX}/bin/texhash

PLIST_SUB+=	TEXHASH=${TEXHASH}

DOCS=		ChangLog INSTALL LICENSE VERSION manifest.txt news-0.1.0.txt \
		news-0.1.1.txt

OPTIONS_DEFINE=	DOCS

do-build:
	@${MKDIR} ${WRKSRC}/build
	@${CC} ${CFLAGS} -o ${WRKSRC}/build/hbibtex \
		${WRKSRC}/util/hbibtex.c
	@${CC} ${CFLAGS} -o ${WRKSRC}/build/hmakeindex \
		${WRKSRC}/util/hmakeindex.c

	@${RM} -r ${WRKSRC}/latex/euc/unfonts
	@${RM} -r ${WRKSRC}/latex/utf/unfonts

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${KOTEX_DOC}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${KOTEX_DOC})

	@${MKDIR} ${STAGEDIR}${KOTEX_BIBTEX}
	(cd ${WRKSRC}/bibtex && ${COPYTREE_SHARE} . ${STAGEDIR}${KOTEX_BIBTEX})

	@${MKDIR} ${STAGEDIR}${KOTEX_LATEX}
	(cd ${WRKSRC}/latex && ${COPYTREE_SHARE} . ${STAGEDIR}${KOTEX_LATEX})

	@${MKDIR} ${STAGEDIR}${KOTEX_MKIDX}
	(cd ${WRKSRC}/makeindex && ${COPYTREE_SHARE} . ${STAGEDIR}${KOTEX_MKIDX})

	@${MKDIR} ${STAGEDIR}${KOTEX_PLAIN}
	(cd ${WRKSRC}/plain && ${COPYTREE_SHARE} . ${STAGEDIR}${KOTEX_PLAIN})

	@${MKDIR} ${STAGEDIR}${KOTEX_SFD}
	(cd ${WRKSRC}/sfd && ${COPYTREE_SHARE} . ${STAGEDIR}${KOTEX_SFD})

	@${MKDIR} ${STAGEDIR}${KOTEX_UTIL}
	@${INSTALL_SCRIPT} ${WRKSRC}/util/*.pl ${STAGEDIR}${KOTEX_UTIL}
	@${INSTALL_PROGRAM} ${WRKSRC}/build/* ${STAGEDIR}${PREFIX}/bin

	@${CHMOD} a+x ${WRKSRC}/util/*.pl
	@${INSTALL_SCRIPT} ${WRKSRC}/util/*.pl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
