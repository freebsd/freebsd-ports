# New ports collection makefile for: Japanese ghostscript + vector font library
# Version required:	2.6.2
# Date created:		14 May 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.14 1998/10/16 05:19:15 jseger Exp $
#

DISTNAME=	ghostscript2.6.2
PKGNAME=	ja-vfghostscript-2.6.2
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.iis.u-tokyo.ac.jp/GNU/ \
		ftp://ftp.ae.keio.ac.jp/pub/msdos/gnu/ghostscript/ \
		ftp://i1nws2.fukui-u.ac.jp/pub/TeX/dvipr/ \
		ftp://ftp.mei.co.jp/free/gnu/util/ghostscript/drivers/
DISTFILES=	ghostscript-2.6.2.tar.gz ghostscript-fonts-2.6.2.tar.gz \
		ghostscript-fonts-4.0.tar.gz gs261j10.tar.gz \
		gs261d13.tar.gz \
		gdevlips4-1.1.0.tar.gz \
		bjc600j-0.9.tar.gz gdevmjc-0.7.tar.gz

MAINTAINER=	mita@jp.FreeBSD.org

LIB_DEPENDS=	VFlib2.23:${PORTSDIR}/japanese/vflib

NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/gs262
EXTRACT_ONLY=	ghostscript-2.6.2.tar.gz
MAN1=		gs.1

DOC_DIR=${PREFIX}/lib/ghostscript/doc 

# Note: unix-gcc.mak.patch can't be put in patches/ because it should
# be applied after gs261j.diff, which should, in turn, be applied
# after the distributed patches
pre-patch:
	@(cd ${WRKSRC} ; \
	  tar xzf ${DISTDIR}/gs261j10.tar.gz ; \
	  tar xzf ${DISTDIR}/gs261d13.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevmjc-0.7.tar.gz ; \
	  tar xzf ${DISTDIR}/bjc600j-0.9.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevlips4-1.1.0.tar.gz ; \
	  ${PATCH} ${PATCH_ARGS} < gs261j.diff ; \
	  ${PATCH} ${PATCH_ARGS} <${FILESDIR}/gdevep82.patch ; \
	  ${PATCH} ${PATCH_ARGS} <${FILESDIR}/bjc600j.dif.patch >/dev/null 2>&1; \
	  ${PATCH} ${PATCH_ARGS} <${FILESDIR}/bjc600j.mak.patch >/dev/null 2>&1; \
	  ${CP} gdevmjc-0.7/gdevmjc.c gdevmjc-0.7/mjc.dev .; \
	  ${CP} bjc600j/paramod.c . ; \
	  ${CP} gdevlips4-1.1.0/gdevlips4.c gdevlips4-1.1.0/gdevlips4.mak .; \
	  cd drivers ; \
	  ${CP} gdev10v/gdev10v.c gdev10v/gdev10v.mak .. ; \
	  ${CP} gdevdmpr/gdevdmpr.c gdevdmpr/gdevdmpr.mak .. ; \
	  ${CP} gdevdmpr/dviprlib.c gdevdmpr/dviprlib.h .. ; \
	  ${CP} gdevep82/gdevep82.c gdevep82/gdevep82.mak ..; \
	  ${CP} gdevepag/gdevepag.c gdevepag/gdevepag.mak .. ; \
	  ${CP} gdevj100/gdevj100.c gdevj100/gdevj100.mak .. ; \
	  ${CP} gdevmag/gdevmag.c gdevmag/gdevmag.mak .. ; \
	  ${CP} gdevp201/gdevp201.c gdevp201/gdevp201.mak ..; )
	@${PATCH} ${PATCH_ARGS} < ${WRKSRC}/drivers/gdevp201/gdevp201.dif
	@${PATCH} ${PATCH_ARGS} <${FILESDIR}/unix-gcc.mak.patch >/dev/null 2>&1
	@${PATCH}  ${PATCH_ARGS} <${FILESDIR}/kfvflib.mak.patch >/dev/null 2>&1
	@${PATCH} ${PATCH_ARGS} < ${WRKSRC}/bjc600j/gdevcdj.dif >/dev/null 2>&1
	@${PATCH} ${PATCH_ARGS} < ${WRKSRC}/bjc600j/devsmak.dif >/dev/null 2>&1
	@${CP} ${WRKSRC}/unix-gcc.mak ${WRKSRC}/Makefile
.if defined(BATCH)
	@(cd ${WRKSRC} ; \
	  ${SH} ${FILESDIR}/printer.sh BATCH; \
	 )
.else
	@(cd ${WRKSRC} ; \
	  ${SH} ${FILESDIR}/printer.sh; \
	 )
.endif
	@${CAT} ${WRKSRC}/kfvflib.mak >> ${WRKSRC}/Makefile
	@${CAT} ${WRKSRC}/gdev10v.mak >> ${WRKSRC}/Makefile
	@${CAT} ${WRKSRC}/bjc600j.mak >> ${WRKSRC}/Makefile
	@${CAT} ${WRKSRC}/gdevdmpr.mak >> ${WRKSRC}/Makefile
	@${CAT} ${WRKSRC}/gdevep82.mak >> ${WRKSRC}/Makefile
	@${CAT} ${WRKSRC}/gdevepag.mak >> ${WRKSRC}/Makefile
	@${CAT} ${WRKSRC}/gdevj100.mak >> ${WRKSRC}/Makefile
	@${CAT} ${WRKSRC}/gdevlips4.mak >> ${WRKSRC}/Makefile
	@${CAT} ${WRKSRC}/gdevmag.mak >> ${WRKSRC}/Makefile
	@${CAT} ${WRKSRC}/mjc.dev >> ${WRKSRC}/Makefile
	@${CAT} ${WRKSRC}/gdevp201.mak >> ${WRKSRC}/Makefile

post-build:
	@(cd ${WRKSRC}; \
	  ${CC} -o paramod paramod.c \
	)

post-install:
	@strip ${PREFIX}/bin/gs ;
	@${INSTALL_PROGRAM} ${WRKSRC}/paramod ${PREFIX}/bin ;
	@(cd ${PREFIX}/lib/ghostscript ; \
	  ${CP} ${WRKSRC}/bjc600j/*.ps . ; \
	tar xzf ${DISTDIR}/ghostscript-fonts-2.6.2.tar.gz ; \
	${CP} ${PREFIX}/lib/ghostscript/kanji/vflib.ps ${PREFIX}/lib/ghostscript/kanji/kconfig.ps ; \
	cd fonts ;\
	tar xzf ${DISTDIR}/ghostscript-fonts-4.0.tar.gz ; \
	${PATCH} < ${FILESDIR}/Fontmap.diff ; \
	${CAT} Fontmap >> ../Fontmap ; \
	${RM} Fontmap* ; \
	${RM} pag* pbk* phv* pnc* ppl* ptm* ; \
	)
	@(cd ${WRKSRC}/drivers/gdevdmpr ; \
	  ${CP} dmp_init.ps dmp_site.ps testpage.ps ${PREFIX}/lib/ghostscript ; \
	  ${CP} escp_24.src ${PREFIX}/lib/ghostscript/doc ; \
	  )
	@(${MKDIR} ${PREFIX}/man/man1 ; \
	  ${CP} ${WRKSRC}/gs.1 ${PREFIX}/man/man1/ ; \
	  ${CP} ${WRKSRC}/gs261j.jis ${DOC_DIR} ; \
	  ${CP} ${WRKSRC}/printers.jis ${DOC_DIR} ; \
	  ${CP} ${WRKSRC}/gdevmjc-0.7/README.jis ${DOC_DIR}/gdevmjc.jis ; \
	  ${CP} ${WRKSRC}/gdevmjc-0.7/MJ700V2C.FAQ ${DOC_DIR} ; \
	  ${CP} ${WRKSRC}/bjc600j/bjc600j.jis  ${DOC_DIR} ; \
	  ${CP} ${WRKSRC}/bjc600j/cmds.doc  ${DOC_DIR} ; \
	  ${CP} ${WRKSRC}/gdevlips4-1.1.0/Readme ${DOC_DIR}/gdevlips4.euc ; \
	  cd ${WRKSRC}/drivers ; \
	  ${CP} gdev10v/gdev10v.jis ${DOC_DIR} ; \
	  ${CP} gdevcdj/gdev505j.sj ${DOC_DIR} ; \
	  ${CP} gdevdmpr/gdevdmpr.sj ${DOC_DIR} ; \
	  ${CP} gdevep82/gdevep82.jis ${DOC_DIR} ; \
	  ${CP} gdevepag/gdevepag.jis ${DOC_DIR} ; \
	  ${CP} gdevj100/gdevj100.jis ${DOC_DIR} ; \
	  ${CP} gdevmag/gdevmag.sj ${DOC_DIR} ; \
	  ${CP} gdevp201/gdevp201.jis ${DOC_DIR} ; \
	  ${CAT} gdevp201/gdevp201.add >> ${DOC_DIR}/gdevp201.jis ; \
	)

.include <bsd.port.mk>
