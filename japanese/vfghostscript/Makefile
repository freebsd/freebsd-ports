# New ports collection makefile for: Japanese ghostscript + vector font library
# Version required:	2.6.2
# Date created:		14 May 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id$
#

DISTNAME=	ghostscript2.6.2
PKGNAME=	jp-vfghostscript-2.6.2
CATEGORIES+=	japanese print
MASTER_SITES=	ftp://ftp.iis.u-tokyo.ac.jp/GNU/ \
		ftp://ftp.ae.keio.ac.jp/pub/msdos/gnu/ghostscript/ \
		ftp://i1nws2.fukui-u.ac.jp/pub/TeX/dvipr/ \
		ftp://ftp.mei.co.jp/free/gnu/util/ghostscript/drivers/
DISTFILES=	ghostscript-2.6.2.tar.gz ghostscript-fonts-2.6.2.tar.gz \
		ghostscript-fonts-4.0.tar.gz gs261j10.tar.gz \
		gs261d13.tar.gz \
		gdevlips4-current.tar.gz \
		bjc600j-0.9.tar.gz gdevmjc-0.7.tar.gz

MAINTAINER=	mita@jp.FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/libVFlib.a:${PORTSDIR}/japanese/vflib

WRKSRC=		${WRKDIR}/gs262
EXTRACT_ONLY=	ghostscript-2.6.2.tar.gz

DOC_DIR=/usr/local/lib/ghostscript/doc 

# Note: unix-gcc.mak.patch can't be put in patches/ because it should
# be applied after gs261j.diff, which should, in turn, be applied
# after the distributed patches
pre-patch:
	@(cd ${WRKSRC} ; \
	  tar xzf ${DISTDIR}/gs261j10.tar.gz ; \
	  tar xzf ${DISTDIR}/gs261d13.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevmjc-0.7.tar.gz ; \
	  tar xzf ${DISTDIR}/bjc600j-0.9.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevlips4-current.tar.gz ; \
	  ${PATCH} ${PATCH_ARGS} < gs261j.diff ; \
	  ${PATCH} ${PATCH_ARGS} <${FILESDIR}/gdevep82.patch ; \
	  ${PATCH} ${PATCH_ARGS} <${FILESDIR}/bjc600j.dif.patch >/dev/null 2>&1; \
	  ${PATCH} ${PATCH_ARGS} <${FILESDIR}/bjc600j.mak.patch >/dev/null 2>&1; \
	  cp gdevmjc-0.7/gdevmjc.c gdevmjc-0.7/mjc.dev .; \
	  cp bjc600j/paramod.c . ; \
	  cp gdevlips4-1.0.1/gdevlips4.c gdevlips4-1.0.1/gdevlips4.mak .; \
	  cd drivers ; \
	  cp gdev10v/gdev10v.c gdev10v/gdev10v.mak .. ; \
	  cp gdevdmpr/gdevdmpr.c gdevdmpr/gdevdmpr.mak .. ; \
	  cp gdevdmpr/dviprlib.c gdevdmpr/dviprlib.h .. ; \
	  cp gdevep82/gdevep82.c gdevep82/gdevep82.mak ..; \
	  cp gdevepag/gdevepag.c gdevepag/gdevepag.mak .. ; \
	  cp gdevj100/gdevj100.c gdevj100/gdevj100.mak .. ; \
	  cp gdevmag/gdevmag.c gdevmag/gdevmag.mak .. ; \
	  cp gdevp201/gdevp201.c gdevp201/gdevp201.mak ..; )
	@${PATCH} ${PATCH_ARGS} < ${WRKSRC}/drivers/gdevp201/gdevp201.dif
	@${PATCH} ${PATCH_ARGS} <${FILESDIR}/unix-gcc.mak.patch >/dev/null 2>&1
	@${PATCH} ${PATCH_ARGS} < ${WRKSRC}/bjc600j/gdevcdj.dif >/dev/null 2>&1
	@${PATCH} ${PATCH_ARGS} < ${WRKSRC}/bjc600j/devsmak.dif >/dev/null 2>&1
	@cp ${WRKSRC}/unix-gcc.mak ${WRKSRC}/Makefile
.if defined(BATCH)
	@(cd ${WRKSRC} ; \
	  /bin/sh ${FILESDIR}/printer.sh BATCH; \
	 )
.else
	@(cd ${WRKSRC} ; \
	  /bin/sh ${FILESDIR}/printer.sh; \
	 )
.endif
	@cat ${WRKSRC}/kfvflib.mak >> ${WRKSRC}/Makefile
	@cat ${WRKSRC}/gdev10v.mak >> ${WRKSRC}/Makefile
	@cat ${WRKSRC}/bjc600j.mak >> ${WRKSRC}/Makefile
	@cat ${WRKSRC}/gdevdmpr.mak >> ${WRKSRC}/Makefile
	@cat ${WRKSRC}/gdevep82.mak >> ${WRKSRC}/Makefile
	@cat ${WRKSRC}/gdevepag.mak >> ${WRKSRC}/Makefile
	@cat ${WRKSRC}/gdevj100.mak >> ${WRKSRC}/Makefile
	@cat ${WRKSRC}/gdevlips4.mak >> ${WRKSRC}/Makefile
	@cat ${WRKSRC}/gdevmag.mak >> ${WRKSRC}/Makefile
	@cat ${WRKSRC}/mjc.dev >> ${WRKSRC}/Makefile
	@cat ${WRKSRC}/gdevp201.mak >> ${WRKSRC}/Makefile

post-build:
	@(cd ${WRKSRC}; \
	  ${CC} -o paramod paramod.c \
	)

post-install:
	@strip ${PREFIX}/bin/gs ;
	@${INSTALL_PROGRAM} ${WRKSRC}/paramod ${PREFIX}/bin ;
	@(cd ${PREFIX}/lib/ghostscript ; \
	  cp ${WRKSRC}/bjc600j/*.ps . ; \
	tar xzf ${DISTDIR}/ghostscript-fonts-2.6.2.tar.gz ; \
	cp ${PREFIX}/lib/ghostscript/kanji/vflib.ps ${PREFIX}/lib/ghostscript/kanji/kconfig.ps ; \
	cd fonts ;\
	tar xzf ${DISTDIR}/ghostscript-fonts-4.0.tar.gz ; \
	${PATCH} < ${FILESDIR}/Fontmap.diff ; \
	cat Fontmap >> ../Fontmap ; \
	rm Fontmap* ; \
	rm pag* pbk* phv* pnc* ppl* ptm* ; \
	)
	@(cd ${WRKSRC}/drivers/gdevdmpr ; \
	  cp dmp_init.ps dmp_site.ps testpage.ps ${PREFIX}/lib/ghostscript ; \
	  cp escp_24.src ${PREFIX}/lib/ghostscript/doc ; \
	  )
	@(if [ ! -d ${PREFIX}/man/man1 ] ; \
	    then mkdir -p ${PREFIX}/man/man1 ; fi ; \
	  cp ${WRKSRC}/gs.1 ${PREFIX}/man/man1/ ; \
	  gzip -9f ${PREFIX}/man/man1/gs.1 ; \
	  cp ${WRKSRC}/gs261j.jis ${DOC_DIR} ; \
	  cp ${WRKSRC}/printers.jis ${DOC_DIR} ; \
	  cp ${WRKSRC}/gdevmjc-0.7/README.jis ${DOC_DIR}/gdevmjc.jis ; \
	  cp ${WRKSRC}/gdevmjc-0.7/MJ700V2C.FAQ ${DOC_DIR} ; \
	  cp ${WRKSRC}/bjc600j/bjc600j.jis  ${DOC_DIR} ; \
	  cp ${WRKSRC}/bjc600j/cmds.doc  ${DOC_DIR} ; \
	  cp ${WRKSRC}/gdevlips4-1.0.1/Readme ${DOC_DIR}/gdevlips4.euc ; \
	  cd ${WRKSRC}/drivers ; \
	  cp gdev10v/gdev10v.jis ${DOC_DIR} ; \
	  cp gdevcdj/gdev505j.sj ${DOC_DIR} ; \
	  cp gdevdmpr/gdevdmpr.sj ${DOC_DIR} ; \
	  cp gdevep82/gdevep82.jis ${DOC_DIR} ; \
	  cp gdevepag/gdevepag.jis ${DOC_DIR} ; \
	  cp gdevj100/gdevj100.jis ${DOC_DIR} ; \
	  cp gdevmag/gdevmag.sj ${DOC_DIR} ; \
	  cp gdevp201/gdevp201.jis ${DOC_DIR} ; \
	  cat gdevp201/gdevp201.add >> ${DOC_DIR}/gdevp201.jis ; \
	)

.include <bsd.port.mk>
