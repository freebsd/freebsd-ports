# New ports collection makefile for:	Judy
# Date created:	   19 August 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Judy
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	judy

MAINTAINER=	skv@FreeBSD.org
COMMENT=	General purpose dynamic array

GNU_CONFIGURE=	YES
USE_LIBTOOL_VER=15
USE_GMAKE=	YES
INSTALLS_SHLIB=	YES
USE_REINPLACE=	YES

MAN3=	Judy.3x Judy1.3x Judy1_funcs.3x JudyHS.3x JudyHS_funcs.3x \
	JudyL.3x JudyL_funcs.3x JudySL.3x JudySL_funcs.3x

MLINKS=	Judy.3x J1T.3x Judy.3x J1S.3x Judy.3x J1U.3x Judy.3x J1F.3x \
	Judy.3x J1N.3x Judy.3x J1L.3x Judy.3x J1P.3x Judy.3x J1FE.3x \
	Judy.3x J1NE.3x Judy.3x J1LE.3x Judy.3x J1PE.3x Judy.3x J1C.3x \
	Judy.3x J1BC.3x Judy.3x J1FA.3x Judy.3x J1MU.3x \
	Judy1_funcs.3x Judy1Test.3x Judy1_funcs.3x Judy1Set.3x \
	Judy1_funcs.3x Judy1Unset.3x Judy1_funcs.3x Judy1First.3x \
	Judy1_funcs.3x Judy1Next.3x Judy1_funcs.3x Judy1Last.3x \
	Judy1_funcs.3x Judy1Prev.3x Judy1_funcs.3x Judy1FirstEmpty.3x \
	Judy1_funcs.3x Judy1NextEmpty.3x Judy1_funcs.3x Judy1LastEmpty.3x \
	Judy1_funcs.3x Judy1PrevEmpty.3x Judy1_funcs.3x Judy1Count.3x \
	Judy1_funcs.3x Judy1ByCount.3x Judy1_funcs.3x Judy1FreeArray.3x \
	Judy1_funcs.3x Judy1MemUsed.3x \
	JudyHS.3x JHSG.3x JudyHS.3x JHSI.3x JudyHS.3x JHSD.3x \
	JudyHS.3x JHSFA.3x \
	JudyHS_funcs.3x JudyHSGet.3x JudyHS_funcs.3x JudyHSIns.3x \
	JudyHS_funcs.3x JudyHSDel.3x JudyHS_funcs.3x JudyHSFreeArray.3x \
	JudyL.3x JLG.3x JudyL.3x JLI.3x JudyL.3x JLD.3x JudyL.3x JLF.3x \
	JudyL.3x JLN.3x JudyL.3x JLL.3x JudyL.3x JLP.3x JudyL.3x JLFE.3x \
	JudyL.3x JLNE.3x JudyL.3x JLLE.3x JudyL.3x JLPE.3x JudyL.3x JLC.3x \
	JudyL.3x JLBC.3x JudyL.3x JLFA.3x JudyL.3x JLMU.3x \
	JudyL_funcs.3x JudyLGet.3x JudyL_funcs.3x JudyLIns.3x \
	JudyL_funcs.3x JudyLDel.3x JudyL_funcs.3x JudyLFirst.3x \
	JudyL_funcs.3x JudyLNext.3x JudyL_funcs.3x JudyLLast.3x \
	JudyL_funcs.3x JudyLPrev.3x JudyL_funcs.3x JudyLFirstEmpty.3x \
	JudyL_funcs.3x JudyLNextEmpty.3x JudyL_funcs.3x JudyLLastEmpty.3x \
	JudyL_funcs.3x JudyLPrevEmpty.3x JudyL_funcs.3x JudyLCount.3x \
	JudyL_funcs.3x JudyLByCount.3x JudyL_funcs.3x JudyLFreeArray.3x \
	JudyL_funcs.3x JudyLMemUsed.3x \
	JudySL.3x JSLG.3x JudySL.3x JSLI.3x JudySL.3x JSLD.3x \
	JudySL.3x JSLF.3x JudySL.3x JSLN.3x JudySL.3x JSLL.3x \
	JudySL.3x JSLP.3x JudySL.3x JSLFA.3x \
	JudySL_funcs.3x JudySLGet.3x JudySL_funcs.3x JudySLIns.3x \
	JudySL_funcs.3x JudySLDel.3x JudySL_funcs.3x JudySLFirst.3x \
	JudySL_funcs.3x JudySLNext.3x JudySL_funcs.3x JudySLLast.3x \
	JudySL_funcs.3x JudySLPrev.3x JudySL_funcs.3x JudySLFreeArray.3x

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
