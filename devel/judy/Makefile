# New ports collection makefile for:	Judy
# Date created:	   19 August 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Judy
PORTVERSION=	1.0.5
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	General purpose dynamic array

GNU_CONFIGURE=	yes
USE_GMAKE=	YES
USE_LDCONFIG=	YES

WRKSRC=	${WRKDIR}/${PORTNAME:L}-${PORTVERSION}

MAN3=	Judy.3 Judy1.3 Judy1_funcs.3 JudyHS.3 JudyHS_funcs.3 \
	JudyL.3 JudyL_funcs.3 JudySL.3 JudySL_funcs.3

MLINKS=	Judy.3 J1T.3 Judy.3 J1S.3 Judy.3 J1U.3 Judy.3 J1F.3 \
	Judy.3 J1N.3 Judy.3 J1L.3 Judy.3 J1P.3 Judy.3 J1FE.3 \
	Judy.3 J1NE.3 Judy.3 J1LE.3 Judy.3 J1PE.3 Judy.3 J1C.3 \
	Judy.3 J1BC.3 Judy.3 J1FA.3 Judy.3 J1MU.3 \
	Judy1_funcs.3 Judy1Test.3 Judy1_funcs.3 Judy1Set.3 \
	Judy1_funcs.3 Judy1Unset.3 Judy1_funcs.3 Judy1First.3 \
	Judy1_funcs.3 Judy1Next.3 Judy1_funcs.3 Judy1Last.3 \
	Judy1_funcs.3 Judy1Prev.3 Judy1_funcs.3 Judy1FirstEmpty.3 \
	Judy1_funcs.3 Judy1NextEmpty.3 Judy1_funcs.3 Judy1LastEmpty.3 \
	Judy1_funcs.3 Judy1PrevEmpty.3 Judy1_funcs.3 Judy1Count.3 \
	Judy1_funcs.3 Judy1ByCount.3 Judy1_funcs.3 Judy1FreeArray.3 \
	Judy1_funcs.3 Judy1MemUsed.3 \
	JudyHS.3 JHSG.3 JudyHS.3 JHSI.3 JudyHS.3 JHSD.3 \
	JudyHS.3 JHSFA.3 \
	JudyHS_funcs.3 JudyHSGet.3 JudyHS_funcs.3 JudyHSIns.3 \
	JudyHS_funcs.3 JudyHSDel.3 JudyHS_funcs.3 JudyHSFreeArray.3 \
	JudyL.3 JLG.3 JudyL.3 JLI.3 JudyL.3 JLD.3 JudyL.3 JLF.3 \
	JudyL.3 JLN.3 JudyL.3 JLL.3 JudyL.3 JLP.3 JudyL.3 JLFE.3 \
	JudyL.3 JLNE.3 JudyL.3 JLLE.3 JudyL.3 JLPE.3 JudyL.3 JLC.3 \
	JudyL.3 JLBC.3 JudyL.3 JLFA.3 JudyL.3 JLMU.3 \
	JudyL_funcs.3 JudyLGet.3 JudyL_funcs.3 JudyLIns.3 \
	JudyL_funcs.3 JudyLDel.3 JudyL_funcs.3 JudyLFirst.3 \
	JudyL_funcs.3 JudyLNext.3 JudyL_funcs.3 JudyLLast.3 \
	JudyL_funcs.3 JudyLPrev.3 JudyL_funcs.3 JudyLFirstEmpty.3 \
	JudyL_funcs.3 JudyLNextEmpty.3 JudyL_funcs.3 JudyLLastEmpty.3 \
	JudyL_funcs.3 JudyLPrevEmpty.3 JudyL_funcs.3 JudyLCount.3 \
	JudyL_funcs.3 JudyLByCount.3 JudyL_funcs.3 JudyLFreeArray.3 \
	JudyL_funcs.3 JudyLMemUsed.3 \
	JudySL.3 JSLG.3 JudySL.3 JSLI.3 JudySL.3 JSLD.3 \
	JudySL.3 JSLF.3 JudySL.3 JSLN.3 JudySL.3 JSLL.3 \
	JudySL.3 JSLP.3 JudySL.3 JSLFA.3 \
	JudySL_funcs.3 JudySLGet.3 JudySL_funcs.3 JudySLIns.3 \
	JudySL_funcs.3 JudySLDel.3 JudySL_funcs.3 JudySLFirst.3 \
	JudySL_funcs.3 JudySLNext.3 JudySL_funcs.3 JudySLLast.3 \
	JudySL_funcs.3 JudySLPrev.3 JudySL_funcs.3 JudySLFreeArray.3

SHLIB_MAJOR=	1
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

LIST_DOCS=	COPYRIGHT README *.htm

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${LIST_DOCS:S!^!${WRKSRC}/doc/ext/!} ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-32-bit
.elif ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "sparc64" || ${ARCH} == "alpha"
CONFIGURE_ARGS+=	--enable-64-bit
.endif

.include <bsd.port.post.mk>
