# New ports collection makefile for:    HLaTeX(UHC encoding)
# Date created:                 2 Jul 2000
# Whom:                         CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HLaTeX
PORTVERSION=	0.991
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/hlatex/
DISTFILES=	HLaTeX-0.991.tar.gz ${HLATEX_FONTS_BASE}
DIST_SUBDIR=	hlatex
EXTRACT_ONLY=	HLaTeX-0.991.tar.gz

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	LaTeX package to use Hangul(UHC/KSX1001)

# it depends on teTeX(lambda)
BUILD_DEPENDS=	texhash:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

BROKEN=		Does not build

TEXMF=		${PREFIX}/share/texmf

# default fonts.
HLATEX_FONTS_BASE=	uhc-myoungjo.tar.gz \
			uhc-gothic.tar.gz \
			uhc-taza.tar.gz
# documents.
HLATEX_DOC_BASE=	VERSION0.991 changelog.ks complang.tex \
			hlatex-en.html hlatex-ko.html hlatex.html \
			hlguide.bib hlguide.dvi hlguide.tex \
			news.098 news.099 readme.eng \
			uhc/uhc.ks moonttf/moonttf.ks \
			doc/compword.pdf.gz doc/compword.ps.gz \
			doc/dot.js doc/font-exam.jpg doc/hlguide.html \
			doc/hlguide.ps.gz doc/hlogo-bg.jpg doc/hlogo.jpg

HLATEX_SAMPLE_BASE=	sample/a.tex sample/p.tex sample/f.tex sample/readme.ks

# psfonts.map, special.map
# it should be downloadable, so use uhc-down.map
# why? otherwise you need nasty gs Fontmap setup...
do-build:
	${CAT}  ${TEXMF}/dvips/config/psfonts.map \
		${WRKDIR}/uhc/config/uhc-down.map \
		> ${WRKDIR}/psfonts.map
	${SED} 's@/usr/tex/share/texmf.local@${PREFIX}/share/texmf@' \
		${WRKDIR}/uhc/config/Fontmap.uhc \
		> ${WRKDIR}/Fontmap

# Installation according to readme.ks
do-install:
	# Part 1: install psfonts
	# psfonts.map
	${MV} ${TEXMF}/dvips/config/psfonts.map \
		${TEXMF}/dvips/config/psfonts.map.beforehlatex
	${INSTALL_DATA} ${WRKDIR}/psfonts.map ${TEXMF}/dvips/config

	# Part 2: macros, style, font descriptions
	${MKDIR} ${TEXMF}/tex/latex/hlatex
	${MKDIR} ${TEXMF}/omega/lambda/hlatex
	${MKDIR} ${TEXMF}/omega/otp/hlatex
	${MKDIR} ${TEXMF}/omega/ocp/hlatex

	${INSTALL_DATA} ${WRKDIR}/hfont.tex \
			${WRKDIR}/hfont.sty \
			${WRKDIR}/hfont.cfg \
			${WRKDIR}/hangul.sty \
			${WRKDIR}/josa.tab \
			${WRKDIR}/uhc/latex/* \
			${WRKDIR}/moonttf/*.fd \
			${WRKDIR}/moonttf/moonttf.sty \
			${TEXMF}/tex/latex/hlatex

	${INSTALL_DATA} ${WRKDIR}/uhc/lambda/*.tex \
			${WRKDIR}/uhc/lambda/*.fd \
			${TEXMF}/omega/lambda/hlatex

	${INSTALL_DATA} ${WRKDIR}/uhc/lambda/ksx1001.otp \
			${TEXMF}/omega/otp/hlatex

	${INSTALL_DATA} ${WRKDIR}/uhc/lambda/ksx1001.ocp \
			${TEXMF}/omega/ocp/hlatex

	${INSTALL_DATA} ${WRKDIR}/contrib/halpha.bst \
			${TEXMF}/bibtex/bst/misc

	${INSTALL_DATA} ${WRKDIR}/contrib/hind.ist \
			${WRKDIR}/contrib/hglo.ist \
			${TEXMF}/makeindex

	# Part 3: documents and samples
	${MKDIR} ${TEXMF}/doc/latex/hlatex/
	for file in ${HLATEX_DOC_BASE}; \
	do \
		${INSTALL_DATA} \
		  ${WRKDIR}/$$file ${TEXMF}/doc/latex/hlatex; \
	done
	${MKDIR} ${TEXMF}/doc/latex/hlatex/sample
	for file in ${HLATEX_SAMPLE_BASE}; \
	do \
		${INSTALL_DATA} \
		  ${WRKDIR}/$$file ${TEXMF}/doc/latex/hlatex/sample; \
	done
	# fontmap...
	${INSTALL_DATA} ${WRKDIR}/Fontmap \
			${TEXMF}/doc/latex/hlatex/sample/Fontmap.uhc

	# Part 4: default mf fonts
	cd ${TEXMF}/fonts/; \
	for fonts in ${HLATEX_FONTS_BASE}; \
	do \
		${EXTRACT_CMD} \
			${EXTRACT_BEFORE_ARGS} \
			${_DISTDIR}/$$fonts ${EXTRACT_AFTER_ARGS}; \
	done
	# Part 5: rehash
	${PREFIX}/bin/texhash

.include <bsd.port.mk>
