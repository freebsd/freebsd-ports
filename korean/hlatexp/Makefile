# New ports collection makefile for:    hLaTeXp
# Date created:                 Jun 28 2000
# Whom:                         CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hLaTeXp
PORTVERSION=	1998.11.20
CATEGORIES=	korean print
MASTER_SITES=	ftp://knot.kaist.ac.kr/pub/htex/hlatexp/ \
		ftp://knot.kaist.ac.kr/pub/htex/htex-fonts/
DISTFILES=	unpacked.tar.gz htex.tfm.tar.gz
DIST_SUBDIR=	htex

MAINTAINER=	cjh@FreeBSD.org

# it depends teTeX.
RUN_DEPENDS=	virtex:${PORTSDIR}/print/teTeX

NO_BUILD=	YES

TEXMF=		${PREFIX}/share/texmf
TEXMFCNF=	${TEXMF}/web2c/texmf.cnf
PKFONTSUB=	's@(^PKFONTS\s+=\s+\.)@\1;\$$TEXMF/fonts/pk/\{xhan300,xhan600,xhan1200\}@g'

do-install:
	### pk dir
	${MKDIR} ${TEXMF}/fonts/pk
	### TFM files
	${MKDIR} ${TEXMF}/fonts/tfm/public/xhan
	${INSTALL_DATA} ${WRKDIR}/htex.tfm/* ${TEXMF}/fonts/tfm/public/xhan/
	### build hlatex script
	${SED} -e "s@%%PATH_HTEXPINI%%@${PREFIX}/bin/htexpini@g" \
	       -e "s@%%PK300_SAMPLE%%@${TEXMF}/fonts/pk/xhan300@g" \
	       -e "s@%%PK600_SAMPLE%%@${TEXMF}/fonts/pk/xhan600@g" \
	       -e "s@%%PK1200_SAMPLE%%@${TEXMF}/fonts/pk/xhan1200@g" \
	          < ${FILESDIR}/hlatex.in > ${WRKDIR}/hlatex
	${INSTALL_SCRIPT} ${WRKDIR}/hlatex ${PREFIX}/bin
	### build hlatex.fmt
	( cd ${WRKDIR}/unpacked && \
	  ${PREFIX}/bin/initex --interaction batchmode hlatex.ltx || \
	  ${TRUE} )
	${INSTALL_DATA} ${WRKDIR}/unpacked/hlatex.fmt \
			${TEXMF}/web2c/
	### install under unpacked/
	${MKDIR} ${TEXMF}/tex/latex/hlatexp
.for file in 	hlatex.ltx hlatexp.ltx dbfont.map hltxman.tex latex.ltx \
		latexbug.tex testpage.tex lablst.tex idx.tex nfssfont.tex \
		small2e.tex sample2e.tex docstrip.tex \
		*.sty *.cls *.clo *.fd *.def *.cfg
	${INSTALL_DATA} ${WRKDIR}/unpacked/${file} ${TEXMF}/tex/latex/hlatexp
.endfor
	### rehash
	${PREFIX}/bin/texhash
	### modify texmf.cnf
	${PERL} -pi -e ${PKFONTSUB} ${TEXMFCNF}

.include <bsd.port.mk>
