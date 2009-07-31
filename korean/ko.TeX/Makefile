# New ports collection makefile for:	ko.TeX
# Date created: 			7 January 2008
# Whom:					Hyogeol Lee <hyogeollee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ko.TeX
PORTVERSION=	0.1.1.20080329
PORTREVISION=	1
CATEGORIES=	korean print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/ko.TeX/current/
DISTNAME=	ko.tex-macro-20080329

MAINTAINER=	hyogeollee@gmail.com
COMMENT=	Korean TeX macro and utilities

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		${BASE_MAP}:${PORTSDIR}/korean/ko.TeX-fonts-base
BUILD_DEPENDS=	texhash:${PORTSDIR}/print/teTeX

CONFLICTS=	hlatex-[0-9]*

NO_WRKSUBDIR=	yes

TEXMF=		${PREFIX}/share/texmf-local
BASE_MAP=	${TEXMF}/fonts/map/dvips/kotex/base/kotex-base.map
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

do-build:
	@${MKDIR} ${WRKDIR}/build
	@${CC} ${CFLAGS} -o ${WRKDIR}/build/hbibtex \
		${WRKDIR}/util/hbibtex.c
	@${CC} ${CFLAGS} -o ${WRKDIR}/build/hmakeindex \
		${WRKDIR}/util/hmakeindex.c

	@${RM} -rf ${WRKDIR}/latex/euc/unfonts
	@${RM} -rf ${WRKDIR}/latex/utf/unfonts

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${MKDIR} ${KOTEX_DOC}
	(cd ${WRKDIR}/doc/ && ${COPYTREE_SHARE} \* ${KOTEX_DOC})
.endif

	@${MKDIR} ${KOTEX_BIBTEX}
	(cd ${WRKDIR}/bibtex/ && ${COPYTREE_SHARE} \* ${KOTEX_BIBTEX})

	@${MKDIR} ${KOTEX_LATEX}
	(cd ${WRKDIR}/latex/ && ${COPYTREE_SHARE} \* ${KOTEX_LATEX})

	@${MKDIR} ${KOTEX_MKIDX}
	(cd ${WRKDIR}/makeindex/ && ${COPYTREE_SHARE} \* ${KOTEX_MKIDX})

	@${MKDIR} ${KOTEX_PLAIN}
	(cd ${WRKDIR}/plain/ && ${COPYTREE_SHARE} \* ${KOTEX_PLAIN})

	@${MKDIR} ${KOTEX_SFD}
	(cd ${WRKDIR}/sfd/ && ${COPYTREE_SHARE} \* ${KOTEX_SFD})

	@${MKDIR} ${KOTEX_UTIL}
	@${INSTALL_SCRIPT} ${WRKDIR}/util/*.pl ${KOTEX_UTIL}
	@${INSTALL_PROGRAM} ${WRKDIR}/build/* ${PREFIX}/bin

	@${CHMOD} a+x ${WRKDIR}/util/*.pl
	@${INSTALL_SCRIPT} ${WRKDIR}/util/*.pl ${PREFIX}/bin

post-install:
	${TEXHASH}

.include <bsd.port.mk>
