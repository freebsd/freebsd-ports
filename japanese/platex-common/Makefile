# New ports collection makefile for:	pLaTeX
# Version required:	?
# Date created:		5 Nov 1995
# Whom:			Hideaki Ohmon <ohmon@sfc.keio.ac.jp>
#
# $Id: Makefile,v 1.10 1996/11/02 05:28:19 max Exp $
#

DISTNAME=	platex2e
PKGNAME=	jp-platex2e-96.03
CATEGORIES+=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex2e/1996-03-05/ \
		ftp://ftp.iij.ad.jp/pub/TeX/CTAN/systems/knuth/lib/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/corresponding-sources/ \
		ftp://ftp.riken.go.jp/pub/tex-archive/systems/knuth/lib/ 
DISTFILES=	base-9512.tar.gz hyphen.tex.gz lib-6.9.tar.gz
EXTRACT_ONLY=	base-9512.tar.gz

MAINTAINER=	max@FreeBSD.ORG

BUILD_DEPENDS=  ptex:${PORTSDIR}/japanese/ptex2
RUN_DEPENDS=    ptex:${PORTSDIR}/japanese/ptex2

WRKSRC=		${WRKDIR}/9603

pre-fetch:
.if !defined(KANJI-CODE)
	@echo "You can set KANJI-CODE value to JIS, SJIS or EUC."
	@echo "Now JIS is used as default."
.if !defined(BATCH)
	@echo -n "Is JIS OK? (y/n) ==> "
	@(read ans; \
	  case x"$$ans" in \
	    xy*|xY*) \
	        return 0; \
	        ;; \
	    *) \
		echo "Ok, please rerun make with preferred KANJI-CODE specification"; \
		echo " like following example."; \
		echo "	make KANJI-CODE=EUC"; \
	        return 1; \
	        ;; \
	  esac)
.endif
KANJI-CODE=	JIS
.endif
.if ${KANJI-CODE} == JIS
PLIB_FILE=	pl9603j.tar.gz
.elif ${KANJI-CODE} == SJIS
PLIB_FILE=	pl9603s.tar.gz
.elif ${KANJI-CODE} == EUC
PLIB_FILE=	pl9603e.tar.gz
.elifdef KANJI-CODE
	@echo "Error: invalid value for KANJI-CODE: \"${KANJI-CODE}\""
	@echo "Possible values are: JIS (default), SJIS, EUC."
	@false
.endif
DISTFILES+=	${PLIB_FILE}
EXTRACT_ONLY+=	${PLIB_FILE}

post-extract:
	@${RM} ${WRKDIR}/base/hyphen.tex
	@gzip -cd ${DISTDIR}/hyphen.tex.gz > ${WRKDIR}/base/hyphen.tex

do-build:
	@(cd ${PREFIX}/lib ; \
	  tar zxf ${DISTDIR}/lib-6.9.tar.gz texmf/tex/latex2e/base)
	@(cd ${WRKDIR}/base ; yes | initex unpack.ins ; initex latex.ltx)
	@(cd ${WRKSRC} ; TEXINPUTS=".:${WRKDIR}/base" ; export TEXINPUTS ; \
	  yes | iniptex plcore.ins ; iniptex platex.ltx) 

do-install:
	@${RM} -rf ${PREFIX}/lib/texmf/tex/latex2e/base/*
	@${MKDIR} ${PREFIX}/lib/texmf/tex/latex2e/base
	(cd ${WRKDIR}/base ; 						\
	 for f in *.cls *.clo *.sty *.fd *.def *.ltx ; do 		\
	   ${INSTALL_DATA} $$f ${PREFIX}/lib/texmf/tex/latex2e/base ; 	\
	 done ;								\
	 ${INSTALL_DATA} latex.fmt ${PREFIX}/lib/texmf/ini)
	@${RM} -f ${PREFIX}/bin/latex
	@ln -s ${PREFIX}/bin/virtex ${PREFIX}/bin/latex
	@${MKDIR} ${PREFIX}/lib/texmf/tex/platex2e/base
	(cd ${WRKSRC} ; 						\
	 for f in *.cls *.clo *.sty *.fd *.def *.ltx *.cfg ; do 	\
	   ${INSTALL_DATA} $$f ${PREFIX}/lib/texmf/tex/platex2e/base ; 	\
	 done ;								\
	 ${INSTALL_DATA} platex.fmt ${PREFIX}/lib/texmf/ini)
	@${RM} -f ${PREFIX}/bin/platex
	@ln -s ${PREFIX}/bin/virptex ${PREFIX}/bin/platex

.include <bsd.port.mk>
