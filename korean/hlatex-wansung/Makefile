# New ports collection makefile for:    HLaTeX PS fonts-wansungstd
# Date created:                 Sun Aug  9 18:05:29 KST 1998
# Whom:                         CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		HLaTeX-${HLATEX_ENCODING}std
PORTVERSION=		0.98
CATEGORIES=             korean print
MASTER_SITES=           ftp://ftp.linguistik.uni-erlangen.de/pub/HLaTeX/ \
			ftp://ftp.linguistik.uni-erlangen.de/pub/HLaTeX/${HLATEX_ENCODING}/
DISTNAME=               HLaTeX-${HLATEX_ENCODING}-0.98
DISTFILES=              HLaTeX-0.98.tar.bz2 ${HLATEX_FONTS_BASE}

MAINTAINER=             cjh@kr.freebsd.org

# in fact, it need to install.
# and it depends teTeX.
BUILD_DEPENDS=        	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=		latex:${PORTSDIR}/print/teTeX

USE_BZIP2=		YES
DIST_SUBDIR=            hlatex98        # too many distfiles
EXTRACT_ONLY=		HLaTeX-0.98.tar.bz2

TEXMF=                  ${PREFIX}/share/texmf
HLATEX_ENCODING=        wansung
# default font. includes complete Myoungjo and Gothic fonts.
HLATEX_FONTS_BASE	= common.tar.bz2 \
			  wsmj.tar.bz2 wsgt.tar.bz2 \
			  hanja-myoungjo.tar.bz2 hanja-gothic.tar.bz2 \
			  hsym.tar.bz2 taza.tar.bz2
# installation files
HLATEX_BASE		= \
	hfont.tex hangul.sty hfont.sty josa.tab hfont.cfg hltx209.cfg \
	hsfonts.def VERSION0.98
HLATEX_FD_BASE	= \
	hhgs.fd hhgt.fd hhpgs.fd hhpgt.fd hhpsm.fd hhptt.fd hhsm.fd \
	hhtt.fd hsgt.fd hspgt.fd hspsm.fd hsptt.fd hssm.fd hstt.fd \
	hwbm.fd hwgr.fd hwgs.fd hwgt.fd hwmg.fd hwmgt.fd hwmj.fd \
	hwmmj.fd hwmnv.fd hwmsr.fd hwmtt.fd hwol.fd hwpbm.fd hwpg.fd \
	hwpgr.fd hwpgs.fd hwpgt.fd hwpmg.fd hwpmgt.fd hwpmj.fd hwpmmj.fd \
	hwpmnv.fd hwpmsr.fd hwpmtt.fd hwpn.fd hwpol.fd hwppg.fd hwppn.fd \
	hwpsm.fd hwpyt.fd hwsm.fd hwyt.fd
HLATEX_DOC_BASE = \
	changelog.ks complang.tex hlguide.tex hlguide.dvi hlguide.bib \
	doc/compword.pdf.bz2 doc/compword.ps.bz2 doc/hlguide.ps.bz2 \
	news.ks onews.ks readme.eng readme.ks \
	${HLATEX_ENCODING}/${HLATEX_ENCODING}.ks Fontmap
HLATEX_SAMPLE_BASE = \
	sample/a.tex sample/p.tex sample/f.tex sample/readme.ks

# psfonts.map, special.map
# it should be downloadable, so use wan-down.map
do-build:
	${CAT}  ${TEXMF}/fontname/special.map \
		${WRKDIR}/${HLATEX_ENCODING}/config/special.map \
		> ${WRKDIR}/special.map
	${CAT}  ${TEXMF}/dvips/config/psfonts.map \
		${WRKDIR}/${HLATEX_ENCODING}/config/wan-down.map \
		> ${WRKDIR}/psfonts.map
	${SED} 's@/usr/tex@/usr/local@' \
		${WRKDIR}/${HLATEX_ENCODING}/config/Fontmap.wan \
		> ${WRKDIR}/Fontmap

# Installation according to readme.ks
do-install:
	# Part 1: install psfonts, special, Fontmap
	# psfonts
	${MV} ${TEXMF}/fontname/special.map \
	      ${TEXMF}/fontname/special.map.beforehlatex
	${INSTALL_DATA} ${WRKDIR}/special.map ${TEXMF}/fontname
	# special
	${MV} ${TEXMF}/dvips/config/psfonts.map \
	      ${TEXMF}/dvips/config/psfonts.map.beforehlatex
	${INSTALL_DATA} ${WRKDIR}/psfonts.map ${TEXMF}/dvips/config
	# Fontmap
	#[ -d ${PREFIX}/share/ghostscript/fonts ] && \
	#	${CP} ${WRKDIR}/Fontmap \
	#	   ${PREFIX}/share/ghostscript/fonts
	# Part 2: macros
	${MKDIR} ${TEXMF}/tex/latex/hlatex
	for file in ${HLATEX_BASE}; \
	do \
		${INSTALL_DATA} \
		  ${WRKDIR}/$$file ${TEXMF}/tex/latex/hlatex; \
	done
	for file in ${HLATEX_FD_BASE}; \
	do \
	  ${INSTALL_DATA} \
	    ${WRKDIR}/${HLATEX_ENCODING}/$$file ${TEXMF}/tex/latex/hlatex; \
	done

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
