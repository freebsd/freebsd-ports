# New ports collection makefile for:	pTeX
# Version required:	2.1.1
# Date created:		5 Nov 1995
# Whom:			Hideaki Ohmon <ohmon@sfc.keio.ac.jp>
#
# $Id$
#

DISTNAME=	ptex3.1415.p2.1.1
PKGNAME=	jp-ptex-2.1.1
CATEGORIES+=	japanese printing
MASTER_SITES=	ftp://bash.cc.keio.ac.jp/pub/TeX/ASCII-pTeX-2.1.1/ \
		ftp://bash.cc.keio.ac.jp/pub/TeX/ASCII-pTeX-2.1.1/corresponding-sources/ \
		ftp://ftp.iij.ad.jp/pub/TeX/ASCII-pTeX/2.1.1/ \
		ftp://ftp.iij.ad.jp/pub/TeX/ASCII-pTeX/2.1.1/coresponding-sources/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ASCII-pTeX-2.1.1/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ASCII-pTeX-2.1.1/coresponding-sources/
# ptex-2.1f2.tar.gz, plib-jis.tar.gz,  plib-sj.tar.gz and  plib-euc.tar.gz 
# are on */*2.1.1/
# web-6.1.tar.gz, web2c-6.1.tar.gz, web2c.kpathsea-2.6.help, 
# xdvik-18f.tar.gz and lib-6.9.tar.gz are on */*2.1.1/coresponding-sources/ 
DISTFILES=	ptex-2.1f2.tar.gz web-6.1.tar.gz web2c-6.1.tar.gz \
		web2c.kpathsea-2.6.help xdvik-18f.tar.gz lib-6.9.tar.gz
EXTRACT_ONLY=	ptex-2.1f2.tar.gz web-6.1.tar.gz web2c-6.1.tar.gz \
		xdvik-18f.tar.gz

MAINTAINER=	ohmon@sfc.keio.ac.jp

HAS_CONFIGURE=	yes
IS_INTERACTIVE=	yes
WRKSRC=		${WRKDIR}/kpathsea-2.6

pre-fetch:
.if !defined(KANJI-CODE)
	@echo "You can set KANJI-CODE value JIS, SJIS or EUC."
	@echo "Now default value JIS is setted."
KANJI-CODE=	JIS
.endif
.if ${KANJI-CODE} == JIS
DISTFILES+=	plib-jis.tar.gz
EXTRACT_ONLY+=  plib-jis.tar.gz
.endif
.if ${KANJI-CODE} == SJIS
DISTFILES+=	plib-sj.tar.gz
EXTRACT_ONLY+=  plib-sj.tar.gz
.endif
.if ${KANJI-CODE} == EUC
DISTFILES+=	plib-euc.tar.gz
EXTRACT_ONLY+=  plib-euc.tar.gz
.endif
.if ${KANJI-CODE} != JIS && ${KANJI-CODE} != SJIS && ${KANJI-CODE} != EUC
	@echo "Error: invalid value for KANJI-CODE: \"${KANJI-CODE}\""
	@echo "Possible values are: JIS (default), SJIS, EUC."
	exit 1
.endif

post-extract:
	@mv ${WRKDIR}/web2c-6.1/web2c ${WRKDIR}/xdvik-18f
	@mv ${WRKDIR}/xdvik-18f ${WRKDIR}/kpathsea-2.6
	@rm -fr ${WRKDIR}/web2c-6.1
	@rm -fr ${WRKDIR}/kpathsea-2.6/xdvik

pre-patch:
	@(cd ${WRKSRC} ; \
	patch -p -s < ${DISTDIR}/web2c.kpathsea-2.6.help)

pre-configure:
.if ${KANJI-CODE} == JIS
	@(cd ${WRKDIR}/ptex-2.1f2 ; ./pTeXsetup -jis)
.endif
.if ${KANJI-CODE} == SJIS
	@(cd ${WRKDIR}/ptex-2.1f2 ; ./pTeXsetup -sjis)
.endif
.if ${KANJI-CODE} == EUC
	@(cd ${WRKDIR}/ptex-2.1f2 ; ./pTeXsetup -euc)
.endif

post-configure:
	@touch ${WRKSRC}/web2c/web/tangleboot.p
	@touch ${WRKSRC}/web2c/web/tangleboot.[ch]

do-build:
	(cd ${WRKSRC} ; make)

pre-install:
	@echo "***********************************************************"
	@echo "*                      W a r n i n g                      *"
	@echo "* This port will overwrite the existing tex installation. *"
	@echo "***********************************************************"
	@echo -n "Is this ok? (y/n) ==> "
	@(read ans; \
	  case x"$$ans" in \
	    xy*|xY*) \
	        return 0; \
	        ;; \
	    *) \
	        echo "Okay, I won't install it then...."; \
	        echo "(Don't worry about the following \"*** Error code 1\"s)"; \
	        return 1; \
	        ;; \
	  esac)
	@(cd /usr/local/lib ; gzip -dc ${DISTDIR}/lib-6.9.tar.gz | tar xf -)
.if ${KANJI-CODE} == JIS
	@(cd /usr/local/lib ; gzip -dc ${DISTDIR}/plib-jis.tar.gz | tar xf -)
.endif
.if ${KANJI-CODE} == SJIS
	@(cd /usr/local/lib ; gzip -dc ${DISTDIR}/plib-sj.tar.gz | tar xf -)
.endif
.if ${KANJI-CODE} == EUC
	@(cd /usr/local/lib ; gzip -dc ${DISTDIR}/plib-euc.tar.gz | tar xf -)
.endif

MANPAGE=amslatex.1 amstex.1 bibtex.1 dvitype.1 etex.1 gftodvi.1 \
	gftopk.1 gftype.1 initex.1 lamstex.1 latex.1 mf.1 mft.1 \
	patgen.1 pktogf.1 pktype.1 pltotf.1 pooltype.1 slitex.1 \
	tangle.1 tex.1 tftopl.1 vftovp.1 virtex.1 vptovf.1 weave.1

post-install:
.if !defined(NOMANCOMPRESS)
	@for manpage in ${MANPAGE}; do \
		gzip -9nf /usr/local/man/man1/$$manpage ;\
	done 
.endif

.include <bsd.port.mk>

