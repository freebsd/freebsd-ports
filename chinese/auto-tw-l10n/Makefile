# New ports collection makefile for:	zh-auto-tw-l10n
# Date created:		7 Oct 2000
# Whom:			"Michael C . Wu" <keichii@iteration.net>
#
# $FreeBSD$

PORTNAME=	auto-tw-l10n
PORTVERSION=	1.0
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.iteration.net/pub/patch_chinese/
DISTNAME=	zh-tw-skel
EXTRACT_SUFX=	.tgz

MAINTAINER=	keichii@iteration.net

RUN_DEPENDS=	${X11BASE}/lib/aout/zh-XFree86-aoutlibs-3.3.6:${PORTSDIR}/chinese/XFree86-aoutlibs \
		cle_base:${PORTSDIR}/chinese/cle_base \
		big5fs:${PORTSDIR}/chinese/big5fs \
		kcfonts:${PORTSDIR}/chinese/kcfonts \
		arphicttf:${PORTSDIR}/chinese/arphicttf \
		moefonts-cid:${PORTSDIR}/chinese/moefonts-cid \
		moettf:${PORTSDIR}/chinese/moettf \
		autoconvert:${PORTSDIR}/chinese/autoconvert \
		bg5ps:${PORTSDIR}/chinese/bg5ps \
		acroread-chtfont:${PORTSDIR}/chinese/acroread-chtfont \
		big5con:${PORTSDIR}/chinese/big5con \
		libtabe:${PORTSDIR}/chinese/libtabe \
		linux-gtk:${PORTSDIR}/chinese/linux-gtk \
		mutt:${PORTSDIR}/chinese/mutt \
		netscape47-communicator:${PORTSDIR}/chinese/netscape47-communicator \
		nvi-big5:${PORTSDIR}/chinese/nvi-big5 \
		pine4:${PORTSDIR}/chinese/pine4 \
		pyDict:${PORTSDIR}/chinese/pyDict \
		rxvt-big5:${PORTSDIR}/chinese/rxvt-big5 \
		aterm:${PORTSDIR}/chinese/aterm \
		telnet:${PORTSDIR}/chinese/telnet \
		tin:${PORTSDIR}/chinese/tin \
		tintin++:${PORTSDIR}/chinese/tintin++ \
		ve:${PORTSDIR}/chinese/ve \
		xcin25:${PORTSDIR}/chinese/xcin25 \
		xemacs21:${PORTSDIR}/chinese/xemacs21 \
		xmms:${PORTSDIR}/chinese/xmms

NO_BUILD=       yes

post-install:
	@${ECHO} "*************************************************************"
	@${ECHO} "* English Instructions:                                     *"
	@${ECHO} "* After your install, you should type the following command *"
	@${ECHO} "* as the normal user.                                       *"
	@${ECHO} "* WARNING: You should back up your configuration dotfiles   *"
	@${ECHO} "* WARNING: BEFORE you type the following.                   *"
	@${ECHO} "* cd ${PORTSDIR}/chinese/auto-tw-l10n && make install-user   *"
	@${ECHO} "*************************************************************"
	@${ECHO} "* 中文大五碼說明：(English users ignore following           *"
	@${ECHO} "* 在您安裝完畢後，請以您平常的使用者shell打下面這行指令     *"
	@${ECHO} "* 注意：請將您的使用者目錄各設定檔先備份                    *"
	@${ECHO} "* cd ${PORTSDIR}/chinese/auto-tw-l10n && make install-user   *"
	@${ECHO} "*************************************************************"

install-user:
#Temporary hack before adduser is modified
#	For future adduser
#	adduser -l10n -v $HOME
	${CP} ${WRKDIR}/zh_TW.Big5/* ${HOME}/
	@${ECHO} "*************************************************************"
	@${ECHO} "* English Instructions:                                     *"
	@${ECHO} "* Merge your backed up old dotfiles with the new ones.      *"
	@${ECHO} "*************************************************************"
	@${ECHO} "* 中文大五碼說明：(English users ignore following           *"
	@${ECHO} "* 請比對您的舊設定跟新設定                                  *"
	@${ECHO} "*************************************************************"

.include <bsd.port.mk>
