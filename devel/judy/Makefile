# New ports collection makefile for:	Judy
# Date created:	   19 August 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Judy
PORTVERSION=	0.1.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://judy.sourceforge.net/downloads/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tar.bz

MAINTAINER=	skv@FreeBSD.org
COMMENT=	General purpose dynamic array

USE_BZIP2=	YES
HAS_CONFIGURE=	YES
INSTALLS_SHLIB=	YES
USE_REINPLACE=	YES

MAN3=	Judy.3x Judy1.3x Judy1_funcs.3x JudyHS.3x JudyHS_funcs.3x \
	JudyL.3x JudyL_funcs.3x JudySL.3x JudySL_funcs.3x

MLINKS=	Judy1.3x J1T.3x Judy1.3x J1S.3x Judy1.3x J1U.3x Judy1.3x J1F.3x \
	Judy1.3x J1N.3x Judy1.3x J1L.3x Judy1.3x J1P.3x Judy1.3x J1FE.3x \
	Judy1.3x J1NE.3x Judy1.3x J1LE.3x Judy1.3x J1PE.3x Judy1.3x J1C.3x \
	Judy1.3x J1BC.3x Judy1.3x J1FA.3x Judy1.3x J1MU.3x \
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

SHLIB_MAJOR=	0
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

DLVDIR=		${WRKSRC}/src/bsd_ia32/product/deliver/usr

LIST_DOCS=	COPYRIGHT README *.htm
LIST_EXAMPLES=	Makefile README *.c

post-patch:
	@${REINPLACE_CMD} -e 's!%%CC%%!${CC}!' \
		${WRKSRC}/make_includes/platform.bsd_ia32.mk

do-install:
	${INSTALL_DATA} ${DLVDIR}/include/Judy.h ${PREFIX}/include
	${INSTALL_DATA} ${DLVDIR}/lib/libJudy.a ${PREFIX}/lib
	${INSTALL_DATA} ${DLVDIR}/lib/libJudy.so \
		${PREFIX}/lib/libJudy.so.${SHLIB_MAJOR}
	${LN} -sf libJudy.so.${SHLIB_MAJOR} ${PREFIX}/lib/libJudy.so
	${INSTALL_MAN} ${DLVDIR}/share/man/man3/*.3x ${MANPREFIX}/man/man3
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${LIST_DOCS:S!^!${DLVDIR}/share/doc/Judy/!} ${DOCSDIR}
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${LIST_EXAMPLES:S!^!${DLVDIR}/share/doc/Judy/demo/!} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${DLVDIR}/share/doc/Judy/demo/run_demo ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
