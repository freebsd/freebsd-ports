# New ports collection makefile for:	Canna
# Version required:	3.2p2
# Date created:		3 November 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#			NIIMI Satoshi <sa2c@and.or.jp>
#
# $Id: Makefile,v 1.23 1998/11/14 09:43:14 asami Exp $
#

DISTNAME=	Canna32p2
PKGNAME=	ja-Canna-3.2.2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/Canna/Canna32/

MAINTAINER=	max@FreeBSD.ORG

BUILD_DEPENDS=	imake:${PORTSDIR}/x11/XFree86

ALL_TARGET=	canna
MAN1=	addwords.1 cannacheck.1 cannakill.1 cannaserver.1 cannastat.1 \
	canvert.1 catdic.1 cpdic.1 cshost.1 ctow.1 delwords.1 dicar.1 \
	dpbindic.1 dpromdic.1 lsdic.1 mkbindic.1 mkdic.1 mkromdic.1 \
	mvdic.1 rmdic.1 splitword.1 wtoc.1
MAN3=	RkCloseRoma.3 RkCvtEuc.3 RkCvtHan.3 RkCvtHira.3 RkCvtKana.3 \
	RkCvtRoma.3 RkCvtZen.3 RkDefineDic.3 RkDeleteDic.3 RkEndBun.3 \
	RkEnlarge.3 RkFinalize.3 RkGetDicList.3 RkGetKanji.3 RkGetLex.3 \
	RkGetStat.3 RkGetYomi.3 RkGoto.3 RkInitialize.3 RkIntro.3 RkLeft.3 \
	RkMapPhonogram.3 RkMapRoma.3 RkMountD.3 RkNext.3 RkNfer.3 \
	RkOpenRoma.3 RkPrev.3 RkRemountDic.3 RkResize.3 RkRgnBun.3 RkRight.3 \
	RkShorten.3 RkStoreYomi.3 RkUnmountDic.3 RkXfer.3 cannalib.3 uilib.3
MANCOMPRESSED=	yes

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/canna.sh

.SILENT:

.include <bsd.port.pre.mk>

do-configure:
	@(cd ${WRKSRC}; ${XMKMF})
	@${SED} -e "s;@PREFIX@;${PREFIX};g" ${FILESDIR}/canna.sh.in \
		>${WRKDIR}/canna.sh

pre-install:
	${MKDIR} /var/run/canna
	chown bin.bin /var/run/canna

post-install:
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libRKC.so.1.0 ${PREFIX}/lib/libRKC.so
	${LN} -sf libRKC16.so.1.0 ${PREFIX}/lib/libRKC16.so
	${LN} -sf libcanna.so.1.0 ${PREFIX}/lib/libcanna.so
	${LN} -sf libcanna16.so.1.0 ${PREFIX}/lib/libcanna16.so
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	if [ ! -f ${STARTUP_SCRIPT} ]; then 				\
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file."; 	\
		${INSTALL_SCRIPT} ${WRKDIR}/canna.sh ${STARTUP_SCRIPT};	\
	fi
	${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
