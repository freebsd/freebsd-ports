# New ports collection makefile for:	Canna
# Date created:		3 November 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#			NIIMI Satoshi <sa2c@and.or.jp>
#
# $FreeBSD$
#

PORTNAME=	Canna
PORTVERSION=	3.6
CATEGORIES=	japanese
MASTER_SITES=	http://downloads.sourceforge.jp/canna/1425/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	max@FreeBSD.org

USE_IMAKE=	yes
USE_X_PREFIX=	no
ALL_TARGET=	canna
INSTALLS_SHLIB=	yes

MANLANG=ja ""
MAN1=	addwords.1 cannacheck.1 cannakill.1 cannaserver.1 cannastat.1 \
	catdic.1 cpdic.1 cshost.1 ctow.1 delwords.1 dicar.1 \
	dpbindic.1 dpromdic.1 lsdic.1 mkbindic.1 mkdic.1 mkromdic.1 \
	mvdic.1 rmdic.1 splitword.1 wtoc.1
MAN3=	RkCloseRoma.3 RkCvtEuc.3 RkCvtHan.3 RkCvtHira.3 RkCvtKana.3 \
	RkCvtRoma.3 RkCvtZen.3 RkDefineDic.3 RkDeleteDic.3 RkEndBun.3 \
	RkEnlarge.3 RkFinalize.3 RkGetDicList.3 RkGetKanji.3 RkGetLex.3 \
	RkGetStat.3 RkGetYomi.3 RkGoto.3 RkInitialize.3 RkIntro.3 RkLeft.3 \
	RkMapPhonogram.3 RkMapRoma.3 RkMountD.3 RkNext.3 RkNfer.3 \
	RkOpenRoma.3 RkPrev.3 RkRemountDic.3 RkResize.3 RkRgnBun.3 RkRight.3 \
	RkShorten.3 RkStoreYomi.3 RkUnmountDic.3 RkXfer.3 cannalib.3 uilib.3
MANCOMPRESSED=	no
XFREE86_HTML_MAN=	no

MLINKS=		uilib.3 XKanjiControl.3  uilib.3 XLookupKanjiString.3 \
		uilib.3 jrKanjiControl.3  uilib.3 jrKanjiString.3

post-build:
	@${SED} -e "s,@RM@,${RM},g; s,@TOUCH@,${TOUCH},g; \
		s,@CHOWN@,${CHOWN},g" ${FILESDIR}/canna.sh.in \
		> ${WRKDIR}/canna.sh.sample

post-install:
.for f in user user/user group
	@${MKDIR} ${PREFIX}/lib/canna/dic/$f
	@${CHOWN} bin:bin ${PREFIX}/lib/canna/dic/$f
	@${CHMOD} 775 ${PREFIX}/lib/canna/dic/$f
.endfor
	@${ECHO} "Installing a sample startup script as ${PREFIX}/etc/rc.d/canna.sh.sample."
	@${INSTALL_SCRIPT} ${WRKDIR}/canna.sh.sample ${PREFIX}/etc/rc.d/canna.sh.sample
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
