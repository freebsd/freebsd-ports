# New ports collection makefile for:	pLaTeX
# Version required:	?
# Date created:		5 Nov 1995
# Whom:			Hideaki Ohmon <ohmon@sfc.keio.ac.jp>
#
# $Id: Makefile,v 1.9 1996/10/27 00:20:25 max Exp $
#

DISTNAME=	platex2e
PKGNAME=	jp-platex2e-96.03
CATEGORIES+=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex2e/1996-03-05/ \
	ftp://ftp.iij.ad.jp/pub/TeX/CTAN/systems/knuth/lib/ \
	ftp://ftp.riken.go.jp/pub/tex-archive/systems/knuth/lib/ 
DISTFILES=	base-9512.tar.gz hyphen.tex.gz
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
DISTFILES+=	pl9603j.tar.gz
EXTRACT_ONLY+=	pl9603j.tar.gz
.endif
.if ${KANJI-CODE} == SJIS
DISTFILES+=	pl9603s.tar.gz
EXTRACT_ONLY+=	pl9603s.tar.gz
.endif
.if ${KANJI-CODE} == EUC
DISTFILES+=	pl9603e.tar.gz
EXTRACT_ONLY+=	pl9603e.tar.gz
.endif
.if ${KANJI-CODE} != JIS && ${KANJI-CODE} != SJIS && ${KANJI-CODE} != EUC
	@echo "Error: invalid value for KANJI-CODE: \"${KANJI-CODE}\""
	@echo "Possible values are: JIS (default), SJIS, EUC."
	exit 1
.endif

post-extract:
	@rm ${WRKDIR}/base/hyphen.tex
	@gzip -cd ${DISTDIR}/hyphen.tex.gz > ${WRKDIR}/base/hyphen.tex

do-build:
	@(cd ${WRKDIR}/base ; yes | initex unpack.ins ; initex latex.ltx)
	@(cd ${WRKSRC} ; TEXINPUTS=".:${WRKDIR}/base" ; export TEXINPUTS ; \
	  yes | iniptex plcore.ins ; iniptex platex.ltx) 

do-install:
	@rm -rf ${PREFIX}/lib/texmf/tex/latex2e/base/*
	@${MKDIR} ${PREFIX}/lib/texmf/tex/latex2e/base
	(cd ${WRKDIR}/base ; 						\
	 for f in *.cls *.clo *.sty *.fd *.def *.ltx ; do 		\
	   ${INSTALL_DATA} $$f ${PREFIX}/lib/texmf/tex/latex2e/base ; 	\
	 done ;								\
	 ${INSTALL_DATA} latex.fmt ${PREFIX}/lib/texmf/ini)
	@rm -f ${PREFIX}/bin/latex
	@ln -s ${PREFIX}/bin/virtex ${PREFIX}/bin/latex
	@${MKDIR} ${PREFIX}/lib/texmf/tex/platex2e/base
	(cd ${WRKSRC} ; 						\
	 for f in *.cls *.clo *.sty *.fd *.def *.ltx *.cfg ; do 	\
	   ${INSTALL_DATA} $$f ${PREFIX}/lib/texmf/tex/platex2e/base ; 	\
	 done ;								\
	 ${INSTALL_DATA} platex.fmt ${PREFIX}/lib/texmf/ini)
	@rm -f ${PREFIX}/bin/platex
	@ln -s ${PREFIX}/bin/virptex ${PREFIX}/bin/platex

.include <bsd.port.mk>
