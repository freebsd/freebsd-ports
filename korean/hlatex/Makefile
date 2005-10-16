# New ports collection makefile for:    HLaTeX(UHC encoding)
# Date created:                 2 Jul 2000
# Whom:                         CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HLaTeX
PORTVERSION=	1.0.1
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.ktug.or.kr/pub/ktug/hlatex/ \
		ftp://ftp.ktug.or.kr/pub/ktug/hlatex/fonts/
DISTFILES=	HLaTeX-1.0.1.tar.gz uhc-fonts-1.0.tar.gz ${HLATEX_FONTS_BASE}
DIST_SUBDIR=	hlatex
EXTRACT_ONLY=	HLaTeX-1.0.1.tar.gz uhc-fonts-1.0.tar.gz

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	LaTeX package to use Hangul(UTF-8/UHC/KSX1001)

# it depends on teTeX(lambda)
BUILD_DEPENDS=	texhash:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

BROKEN=		Broken dependency

MACRO_DIR=	${WRKDIR}/HLaTeX
FONT_DIR=	${WRKDIR}/uhc-fonts-1.0
TEXMF=		${PREFIX}/share/texmf
TEXMF_HLATEX=	${PREFIX}/share/texmf-hlatex

# default fonts.
HLATEX_FONTS_BASE=	uhc-myoungjo-1.0.tar.gz \
			uhc-gothic-1.0.tar.gz \
			uhc-taza-1.0.tar.gz
# documents.
HLATEX_DOC_BASE=	ChangeLog.ko NEWS-0.98.ko NEWS-0.99.ko NEWS-1.0.ko \
			README.en VERSION-1.0.1 \
			hlguide-k.bib hlguide-k.tex hlguide-u.bib \
			hlguide-u.tex hlguide.bbl hlguide.ind hlguide.pdf \
			hlguide.tex 
HLATEX_DOC_FONT_BASE=	README hfontlist.pdf

# Build hbibtex and hmakeindex
do-build:
	${CC} -O2 -pipe -o ${MACRO_DIR}/contrib/hbibtex \
		${MACRO_DIR}/contrib/hbibtex.c
	${CC} -O2 -pipe -o ${MACRO_DIR}/contrib/hmakeindex \
		${MACRO_DIR}/contrib/hmakeindex.c
	${AWK} 'BEGIN { FS = " |\{|\}" } \
		{if ( $$1 == "TEXMF" ) \
			{print "TEXMFHLATEX = ${TEXMF_HLATEX}"; \
			 printf "%s%s%s", "TEXMF = {!!$$TEXMFHLATEX,", $$4, \
			 "}"} \
		 else print }' ${TEXMF}/web2c/texmf.cnf > ${WRKDIR}/texmf.cnf

# Installation according to readme.ks
do-install:
	# Part 1: install directories
	${MKDIR} ${TEXMF_HLATEX}/tex/latex/hlatex
	${MKDIR} ${TEXMF_HLATEX}/tex/lambda/hlatex
	${MKDIR} ${TEXMF_HLATEX}/omega/otp/hlatex
	${MKDIR} ${TEXMF_HLATEX}/omega/ocp/hlatex
	${MKDIR} ${TEXMF_HLATEX}/bibtex/bst/hlatex
	${MKDIR} ${TEXMF_HLATEX}/makeindex
	${MKDIR} ${TEXMF_HLATEX}/fonts/map/hlatex
	${MKDIR} ${TEXMF_HLATEX}/doc/latex/hlatex/
	${MKDIR} ${TEXMF_HLATEX}/doc/latex/hlatex/fonts

	# Part 2: macros, style, font descriptions
	${INSTALL_DATA} ${MACRO_DIR}/latex/* ${TEXMF_HLATEX}/tex/latex/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/lambda/u8hangul.tex \
		${TEXMF_HLATEX}/tex/lambda/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/lambda/uhc-test.tex \
		${TEXMF_HLATEX}/tex/lambda/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/lambda/*.fd \
		${TEXMF_HLATEX}/tex/lambda/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/lambda/hlatex.otp \
		${TEXMF_HLATEX}/omega/otp/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/lambda/hlatex.ocp \
		${TEXMF_HLATEX}/omega/ocp/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/contrib/hbname-k.tex \
		${TEXMF_HLATEX}/tex/latex/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/contrib/hbname-u.tex \
		${TEXMF_HLATEX}/tex/lambda/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/contrib/halpha.bst \
		${TEXMF_HLATEX}/bibtex/bst/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/contrib/*.ist \
		${TEXMF_HLATEX}/makeindex
	${INSTALL_DATA} ${MACRO_DIR}/contrib/khyper.sty \
		${TEXMF_HLATEX}/tex/latex/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/contrib/showhkeys.sty \
		${TEXMF_HLATEX}/tex/latex/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/contrib/showhtags.sty \
		${TEXMF_HLATEX}/tex/latex/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/contrib/hangulfn.sty \
		${TEXMF_HLATEX}/tex/latex/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/contrib/hfn-k.tex \
		${TEXMF_HLATEX}/tex/latex/hlatex
	${INSTALL_DATA} ${MACRO_DIR}/contrib/hfn-u.tex \
		${TEXMF_HLATEX}/tex/lambda/hlatex

	# Part 3: binaries
	${INSTALL_PROGRAM} ${MACRO_DIR}/contrib/hbibtex ${PREFIX}/bin
	${INSTALL_PROGRAM} ${MACRO_DIR}/contrib/hmakeindex ${PREFIX}/bin

	# Part 4: fontmap
	${INSTALL_DATA} ${FONT_DIR}/uhc-base.map \
		${TEXMF_HLATEX}/fonts/map/hlatex
	${INSTALL_DATA} ${FONT_DIR}/uhc-extra.map \
		${TEXMF_HLATEX}/fonts/map/hlatex

	# Part 5: documents and samples
	for file in ${HLATEX_DOC_BASE}; \
	do \
		${INSTALL_DATA} \
		  ${MACRO_DIR}/$$file ${TEXMF_HLATEX}/doc/latex/hlatex; \
	done
	for file in ${HLATEX_DOC_FONT_BASE}; \
	do \
		${INSTALL_DATA} \
		  ${FONT_DIR}/$$file ${TEXMF_HLATEX}/doc/latex/hlatex/fonts; \
	done

	# Part 6: fonts
	cd ${TEXMF_HLATEX}/fonts/; \
	for fonts in ${HLATEX_FONTS_BASE}; \
	do \
		${EXTRACT_CMD} \
			${EXTRACT_BEFORE_ARGS} \
			${_DISTDIR}/$$fonts ${EXTRACT_AFTER_ARGS}; \
	done

	# Part 7: update texmf.cnf
	${MV} ${TEXMF}/web2c/texmf.cnf ${TEXMF}/web2c/texmf.cnf.beforehlatex
	${INSTALL_DATA} ${WRKDIR}/texmf.cnf ${TEXMF}/web2c
	
	# Part 8: rehash
	${PREFIX}/bin/texhash

.include <bsd.port.mk>
