# New ports collection makefile for:	zh-auto-tw-l10n
# Date created:		7 Oct 2000
# Whom:			"Michael C . Wu" <keichii@iteration.net>
#
# $FreeBSD$

PORTNAME=	auto-tw-l10n
PORTVERSION=	1.2
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.iteration.net/pub/patch_chinese/
DISTNAME=	zh-tw-skel-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	keichii@freebsd.org

# The zh_TW.big5 in the linux-gtk section is not a typo.
RUN_DEPENDS=	${X11BASE}/lib/aout/zh-XFree86-aoutlibs-3.3.6:${PORTSDIR}/chinese/XFree86-aoutlibs \
		${LINUX_BASE}/CLE-0.9p1:${PORTSDIR}/chinese/cle_base \
		${LOCALBASE}/modules/big5msdos.ko:${PORTSDIR}/chinese/big5fs \
		${X11BASE}/lib/X11/fonts/local/kc24f.pcf.gz:${PORTSDIR}/chinese/kcfonts \
		${X11BASE}/lib/X11/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf \
		${LOCALBASE}/share/ghostscript/fonts/MOEKai-Regular:${PORTSDIR}/chinese/moefonts-cid \
		${X11BASE}/lib/X11/fonts/TrueType/moe_sung.ttf:${PORTSDIR}/chinese/moettf \
		autob5:${PORTSDIR}/chinese/autoconvert \
		bg5ps:${PORTSDIR}/chinese/bg5ps \
		${LOCALBASE}/Acrobat4/Resource/CIDFont/MSung-Light-Acro:${PORTSDIR}/chinese/acroread-chtfont \
		b5c:${PORTSDIR}/chinese/big5con \
		tsiadd:${PORTSDIR}/chinese/libtabe \
		${LINUX_BASE}/etc/gtk/gtkrc.zh_TW.big5:${PORTSDIR}/chinese/linux-gtk \
		mutt:${PORTSDIR}/chinese/mutt \
		${LOCALBASE}/lib/netscape/zh_TW.Big5/Netscape:${PORTSDIR}/chinese/netscape47-communicator \
		${LOCALBASE}/share/vi/README.japanese:${PORTSDIR}/chinese/nvi-big5 \
		${LOCALBASE}/etc/dot.pinerc.sample:${PORTSDIR}/chinese/pine4 \
		pydict:${PORTSDIR}/chinese/pyDict \
		rxvt:${PORTSDIR}/chinese/rxvt-big5 \
		zh-telnet:${PORTSDIR}/chinese/telnet \
		tin:${PORTSDIR}/chinese/tin \
		tintin++:${PORTSDIR}/chinese/tintin++ \
		ve:${PORTSDIR}/chinese/ve \
		xcin25:${PORTSDIR}/chinese/xcin25 \
		${LOCALBASE}/lib/xemacs-21.1.12/etc/app-defaults/zh_TW.Big5/Emacs:${PORTSDIR}/chinese/xemacs21 \
		xmms:${PORTSDIR}/chinese/xmms

NO_BUILD=	yes

do-install:
#Temporary hack before adduser is modified
#	For future adduser
#	adduser -l10n -v $HOME
	${MKDIR} ${PREFIX}/share/skel/zh_TW.Big5
	${CP} ${WRKDIR}/zh_TW.Big5/* ${PREFIX}/share/skel/zh_TW.Big5
	@${ECHO} "*************************************************************"
	@${ECHO} "* English Instructions:                                     *"
	@${ECHO} "* Please tell your users to merge their old dotfiles with   *"
	@${ECHO} "* the new ones, in                                          *"
	@${ECHO} "* ${PREFIX}/share/skel/zh_TW.Big5/dot.*                    *"
	@${ECHO} "*************************************************************"
	@${ECHO} "* 中文大五碼說明:                                           *"
	@${ECHO} "* 請告知您的使用者比對他們的舊設定跟新設定, 在              *"
	@${ECHO} "* ${PREFIX}/share/skel/zh_TW.Big5/dot.*                     *"
	@${ECHO} "*************************************************************"

.include <bsd.port.mk>
