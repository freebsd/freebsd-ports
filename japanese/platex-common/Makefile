# New ports collection makefile for:	pLaTeX
# Version required:	?
# Date created:		5 Nov 1995
# Whom:			Hideaki Ohmon <ohmon@sfc.keio.ac.jp>
#
# $Id: Makefile,v 1.3 1996/04/26 08:18:24 asami Exp $
#

DISTNAME=	platex2e
PKGNAME=	jp-platex2e-95.09
CATEGORIES+=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ \
	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/corresponding-sources/ \
	ftp://ftp.iij.ad.jp/pub/TeX/ASCII-pTeX/2.1.1/ \
	ftp://ftp.iij.ad.jp/pub/TeX/ASCII-pTeX/2.1.1/corresponding-sources/ \
	ftp://ftp.iij.ad.jp/pub/TeX/CTAN/systems/knuth/lib/ \
	ftp://bash.cc.keio.ac.jp/pub/TeX/ASCII-pTeX-2.1.1/ \
	ftp://bash.cc.keio.ac.jp/pub/TeX/ASCII-pTeX-2.1.1/corresponding-sources/ \
	ftp://ftp.riken.go.jp/pub/tex-archive/systems/knuth/lib/ 
DISTFILES=	base-9506.tar.gz hyphen.tex
EXTRACT_ONLY=	base-9506.tar.gz

# base-9506.tar.gz is in */corresponding-sources/ 
# hyphen.tex is in */systems/knuth/lib/ 
# pl2e-jis.tar.gz, pl2e-sj.tar.gz and pl2e-euc.tar.gz are in 
# */corresponding-sources/ 

MAINTAINER=	max@sfc.wide.ad.jp

BUILD_DEPENDS=  ptex:${PORTSDIR}/japanese/ptex2
RUN_DEPENDS=    ptex:${PORTSDIR}/japanese/ptex2

WRKSRC=		${WRKDIR}/9509b

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
DISTFILES+=	pl2e-jis.tar.gz
EXTRACT_ONLY+=	pl2e-jis.tar.gz
.endif
.if ${KANJI-CODE} == SJIS
DISTFILES+=	pl2e-sj.tar.gz
EXTRACT_ONLY+=	pl2e-sj.tar.gz
.endif
.if ${KANJI-CODE} == EUC
DISTFILES+=	pl2e-euc.tar.gz
EXTRACT_ONLY+=	pl2e-euc.tar.gz
.endif
.if ${KANJI-CODE} != JIS && ${KANJI-CODE} != SJIS && ${KANJI-CODE} != EUC
	@echo "Error: invalid value for KANJI-CODE: \"${KANJI-CODE}\""
	@echo "Possible values are: JIS (default), SJIS, EUC."
	exit 1
.endif

post-extract:
	@rm ${WRKDIR}/base/hyphen.tex
	@cp ${DISTDIR}/hyphen.tex ${WRKDIR}/base/hyphen.tex

do-build:
	@(cd ${WRKDIR}/base ; yes | initex unpack.ins ; initex latex.ltx)
	@(cd ${WRKSRC} ; TEXINPUTS=".:${WRKDIR}/base" ; export TEXINPUTS ; \
	yes | iniptex plcore.ins ; iniptex platex.ltx) 

do-install:
	@rm -rf /usr/local/lib/texmf/tex/latex2e/base/*
.if !exists(/usr/local/lib/texmf/tex/latex2e)
	@mkdir /usr/local/lib/texmf/tex/latex2e
.endif 
.if !exists(/usr/local/lib/texmf/tex/latex2e/base)
	@mkdir /usr/local/lib/texmf/tex/latex2e/base
.endif 
	@(cd ${WRKDIR}/base ; cp -f *.cls *.clo *.sty *.fd *.def *.ltx \
	/usr/local/lib/texmf/tex/latex2e/base ; \
	mv latex.fmt /usr/local/lib/texmf/ini)
	@rm -f  /usr/local/bin/latex
	@ln -s /usr/local/bin/virtex /usr/local/bin/latex
.if !exists(/usr/local/lib/texmf/tex/platex2e)
	@mkdir /usr/local/lib/texmf/tex/platex2e
.endif 
.if !exists(/usr/local/lib/texmf/tex/platex2e/base)
	@mkdir /usr/local/lib/texmf/tex/platex2e/base
.endif 
	@(cd ${WRKSRC} ; cp -f *.cls *.clo *.sty *.fd *.def *.ltx *.cfg \
	/usr/local/lib/texmf/tex/platex2e/base ; \
	cp -f platex.fmt /usr/local/lib/texmf/ini)
	@rm -f /usr/local/bin/platex
	@ln -s /usr/local/bin/virptex /usr/local/bin/platex

.include <bsd.port.mk>
