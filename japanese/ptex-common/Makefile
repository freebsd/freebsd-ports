# New ports collection makefile for:	pTeX
# Version required:	2.1.4
# Date created:		5 Nov 1995
# Whom:			Hideaki Ohmon <ohmon@sfc.keio.ac.jp>
#
# $Id: Makefile,v 1.16 1997/02/04 11:09:38 max Exp $
#

DISTNAME=	ptex3.1415.p2.1.4
PKGNAME=	jp-ptex-2.1.4
CATEGORIES=	japanese print
MASTER_SITES=			ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/corresponding-sources/ \
		ftp://bash.cc.keio.ac.jp/pub/TeX/ascii-ptex/ \
		ftp://bash.cc.keio.ac.jp/pub/TeX/ascii-ptex/corresponding-sources/ 
# ptex-2.1.4.tar.gz, plib-jis.tar.gz,  plib-sj.tar.gz and  plib-euc.tar.gz 
# are in */ascii-ptex/ and
# web-6.1.tar.gz, web2c-6.1.tar.gz, web2c.kpathsea-2.6.help, 
# xdvik-18f.tar.gz and lib-6.9.tar.gz are in 
#  */ascii-ptex/corresponding-sources/ 

DISTFILES=	ptex-2.1.4.tar.gz web-6.1.tar.gz web2c-6.1.tar.gz \
		web2c.kpathsea-2.6.help xdvik-18f.tar.gz lib-6.9.tar.gz

MAINTAINER=	max@FreeBSD.ORG

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/kpathsea-2.6
STRIP=		# some shell scripts
EXTRACT_ONLY=	ptex-2.1.4.tar.gz web-6.1.tar.gz web2c-6.1.tar.gz \
		xdvik-18f.tar.gz

BINARIES=kpsewhich dvicopy dvitype pdvitype gftodvi gftopk \
	mft pktogf pktype vftovp vptovf gftype pltotf tftopl initex \
	virtex patgen iniptex virptex inimf virmf bibtex jbibtex \
	tangle weave pooltype

MAN1=	amslatex.1 amstex.1 bibtex.1 dvitype.1 etex.1 gftodvi.1 \
	gftopk.1 gftype.1 initex.1 lamstex.1 latex.1 mf.1 mft.1 \
	patgen.1 pktogf.1 pktype.1 pltotf.1 pooltype.1 slitex.1 \
	tangle.1 tex.1 tftopl.1 vftovp.1 virtex.1 vptovf.1 weave.1

pre-fetch:
.if !defined(KANJI-CODE)
	@echo "You can set KANJI-CODE value to JIS, SJIS or EUC."
	@echo "Now JIS is used as default."
.if !defined(BATCH) && !defined(FOR_CDROM)
	@(read -p "Is JIS OK? (y/n) ==> " ans; \
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
LIB_FILE=	plib-jis.tar.gz
.elif ${KANJI-CODE} == SJIS
LIB_FILE=	plib-sj.tar.gz
.elif ${KANJI-CODE} == EUC
LIB_FILE=	plib-euc.tar.gz
.elifdef KANJI-CODE
	@echo "Error: invalid value for KANJI-CODE: \"${KANJI-CODE}\""
	@echo "Possible values are: JIS (default), SJIS, EUC."
	@false
.endif
.if !defined(FOR_CDROM)
DISTFILES+=	${LIB_FILE}
.else
DISTFILES+=	plib-jis.tar.gz plib-sj.tar.gz plib-euc.tar.gz
.endif
EXTRACT_ONLY+=	${LIB_FILE}

post-extract:
	@${MV} ${WRKDIR}/web2c-6.1/web2c ${WRKDIR}/xdvik-18f
	@${MV} ${WRKDIR}/xdvik-18f ${WRKDIR}/kpathsea-2.6
	@${RM} -fr ${WRKDIR}/web2c-6.1 ${WRKDIR}/kpathsea-2.6/xdvik

pre-patch:
	@${PATCH} -p -s -d ${WRKSRC} < ${DISTDIR}/web2c.kpathsea-2.6.help

pre-configure:
	@(cd ${WRKDIR}/ptex-2.1.4 ; \
	  ./pTeXsetup -`echo ${KANJI-CODE} | tr A-Z a-z`)

post-configure:
	@touch ${WRKSRC}/web2c/web/tangleboot.p
	@touch ${WRKSRC}/web2c/web/tangleboot.[ch]

do-build:
	@(cd ${WRKSRC} ; ${MAKE})

pre-install:
.if !defined(BATCH)
	@/bin/sh ${PKGDIR}/REQ ${PKGNAME} INSTALL || \
	(echo "(Don't worry about the following \"*** Error code 1\"s)" ; \
	 exit 1)
.endif
	@tar --exclude 'texmf/tex/latex2e/base/*' -zx -C ${PREFIX}/lib \
	  -f ${DISTDIR}/lib-6.9.tar.gz
	@tar -zx -C ${PREFIX}/lib -f ${DISTDIR}/${LIB_FILE}

post-install:
	@echo -n "Stripping the binary files...."
.for bin in ${BINARIES}
	@strip ${PREFIX}/bin/${bin}
.endfor
	@echo "done."

.include <bsd.port.mk>
