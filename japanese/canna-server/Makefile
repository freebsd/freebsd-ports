# New ports collection makefile for:	canna-server
# Date created:		7 September 2008
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	canna
PORTVERSION=	3.7p3
PORTREVISION=	9
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	canna/9565/
PKGNAMESUFFIX=	-server
DISTNAME=	Canna${PORTVERSION:S/.//g}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A Kana-to-Kanji conversion system, binary part

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/canna-lib

USE_RC_SUBR=	canna
USE_BZIP2=	yes
USE_IMAKE=	yes
ALL_TARGET=	canna
INSTALL_TARGET=	instserver instclient
PLIST_SUB=	METAFILE="${METAFILE}" \
		MTREE_CMD="${MTREE_CMD}"

PORTDOCS=	canna.bib canna.sty Imakefile README.jp Makefile \
		intern lisp man

MANLANG=	"" ja
MANCOMPRESSED=	no
MAN1=	addwords.1 cannacheck.1 cannakill.1 cannaserver.1 cannastat.1	\
	catdic.1 chmoddic.1 cpdic.1 cshost.1 ctow.1 delwords.1 dicar.1	\
	dpbindic.1 dpromdic.1 lsdic.1 mkbindic.1 mkdic.1 mkromdic.1	\
	mvdic.1 rmdic.1 splitword.1 wtoc.1
MAN3=	RkCloseRoma.3 RkCvtEuc.3 RkCvtHan.3 RkCvtHira.3 RkCvtKana.3	\
	RkCvtRoma.3 RkCvtZen.3 RkDefineDic.3 RkDeleteDic.3 RkEndBun.3	\
	RkEnlarge.3 RkFinalize.3 RkGetDicList.3 RkGetKanji.3		\
	RkGetLex.3 RkGetStat.3 RkGetYomi.3 RkGoto.3 RkInitialize.3	\
	RkIntro.3 RkLeft.3 RkMapPhonogram.3 RkMapRoma.3 RkMountDic.3	\
	RkNext.3 RkNfer.3 RkOpenRoma.3 RkPrev.3 RkRemountDic.3		\
	RkResize.3 RkBgnBun.3 RkRight.3 RkShorten.3 RkStoreYomi.3	\
	RkUnmountDic.3 RkXfer.3 cannalib.3 uilib.3
MLINKS= uilib.3 XKanjiControl.3 uilib.3 XLookupKanjiString.3 uilib.3	\
	jrKanjiControl.3 uilib.3 jrKanjiString.3

METAFILE=	${DATADIR_REL}/canna-server-dic.meta

post-configure:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${MAKE_ENV} ${XMKMF}

post-install:
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install.man
	${MTREE_CMD} -cdink uname,gname,mode,nochange \
		-p ${DATADIR}/dic > ${PREFIX}/${METAFILE}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${CP} -R ${PORTDOCS} ${DOCSDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
