# New ports collection makefile for:    HLaTeX wansung extension
# Date created:                 2 Jul 2000
# Whom:                         CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HLaTeX-wansung
PORTVERSION=	0.991
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.linguistik.uni-erlangen.de/pub/hangul/HLaTeX/packed/unsupported/
DISTNAME=	wansung
DIST_SUBDIR=	hlatex

MAINTAINER=	cjh@FreeBSD.org

# it depends on HLaTeX(uhc)
RUN_DEPENDS=	${LOCALBASE}/share/texmf/doc/latex/hlatex/uhc.ks:${PORTSDIR}/korean/hlatex

TEXMF=		${PREFIX}/share/texmf
WRKSRC=		${WRKDIR}/wansung

# documents.
HLATEX_DOC_BASE=	wansung.ks fonts/mkhfonts.tex

# psfonts.map, special.map
# it should be downloadable, so use wan-down.map
# why? otherwise you need nasty gs Fontmap setup...
do-build:
	${CAT}  ${TEXMF}/dvips/config/psfonts.map \
		${WRKSRC}/config/wan-down.map \
		> ${WRKDIR}/psfonts.map
	${SED} 's@/usr/tex/share/texmf@${PREFIX}/share/texmf@' \
		${WRKSRC}/config/Fontmap.wan \
		> ${WRKDIR}/Fontmap

# Installation according to readme.ks
do-install:
	# Part 1: install psfonts.map
	# psfonts.map
	${MV} ${TEXMF}/dvips/config/psfonts.map \
	      ${TEXMF}/dvips/config/psfonts.map.beforehlatex-wansung
	${INSTALL_DATA} ${WRKDIR}/psfonts.map ${TEXMF}/dvips/config

	# Part 2: macros, style, font descriptions
	${MKDIR} ${TEXMF}/tex/latex/hlatex/wansung

	## fd files
	${INSTALL_DATA} ${WRKSRC}/*.fd \
			${TEXMF}/tex/latex/hlatex/wansung

	## style, defs
	${INSTALL_DATA} ${WRKSRC}/wanfont.sty \
			${WRKSRC}/hsfonts.def \
			${TEXMF}/tex/latex/hlatex/wansung

	# Part 3: documents and samples
	for file in ${HLATEX_DOC_BASE}; \
	do \
		${INSTALL_DATA} \
		  ${WRKSRC}/$$file ${TEXMF}/doc/latex/hlatex; \
	done

	### Fontmap...
	${INSTALL_DATA} ${WRKDIR}/Fontmap \
			${TEXMF}/doc/latex/hlatex/sample/Fontmap.wansung

	# Part 4: rehash
	${PREFIX}/bin/texhash

.include <bsd.port.mk>
