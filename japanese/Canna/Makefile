# New ports collection makefile for:	Canna
# Date created:		3 November 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#			NIIMI Satoshi <sa2c@and.or.jp>
#
# $FreeBSD$
#

PORTNAME=	Canna
PORTVERSION=	3.5b2
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.tokyonet.ad.jp/pub/misc/Canna/Canna35/ \
		ftp://ftp.meshnet.or.jp/pub/tool/Canna/Canna35/ \
		ftp://ftp.sra.co.jp/pub/misc/canna/ \
		ftp://ftp.habi.or.jp/pub/Tools/Canna/Canna35/ \
		ftp://ftp.hans.or.jp/pub/Tools/Canna/Canna35/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

PATCH_SITES=	http://www.jaist.ac.jp/~fujieda/canna/
PATCHFILES=	Canna35b2-unoff1.patch.gz Canna35b2-unoff2.patch.gz \
		Canna35b2-hack1.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	max@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
BUILD_DEPENDS=	xmkmf:${PORTSDIR}/devel/imake
.endif

USE_IMAKE=	yes
USE_X_PREFIX=	no
ALL_TARGET=	canna
INSTALLS_SHLIB=	yes

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

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/canna.sh

post-install:
	${MKDIR} /var/run/canna
	${CHOWN} bin:bin /var/run/canna
.for f in user user/user group
	${MKDIR} ${PREFIX}/lib/canna/dic/$f
	${CHOWN} bin:bin ${PREFIX}/lib/canna/dic/$f
	${CHMOD} 775 ${PREFIX}/lib/canna/dic/$f
.endfor
	@${SED} -e "s;@PREFIX@;${PREFIX};g" ${FILESDIR}/canna.sh.in \
		>${WRKDIR}/canna.sh
	if [ ! -f ${STARTUP_SCRIPT} ]; then 				\
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file."; 	\
		${INSTALL_SCRIPT} ${WRKDIR}/canna.sh ${STARTUP_SCRIPT};	\
	fi
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
