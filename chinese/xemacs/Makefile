# New ports collection makefile for:	zh-XEmacs
# Date created:		30 Oct 1999
# Whom:			Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xemacs
PORTVERSION=	20.4
PORTREVISION=	2
CATEGORIES=	chinese editors
MASTER_SITES=	${MASTER_SITE_XEMACS}
MASTER_SITES+=	ftp://ftp.tnt.uni-hannover.de/pub/editors/xemacs/20.4/ \
		ftp://ftp.sunsite.org.uk/Mirrors/ftp.xemacs.org/pub/xemacs/%SUBDDIR%/
MASTER_SITE_SUBDIR=	${DISTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-mule${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XEmacs text editor version 20, with XIM support and Big5 settings

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	xcin2.5:${PORTSDIR}/chinese/xcin25 \
		${X11BASE}/lib/X11/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf

USE_GMAKE=	yes
USE_XPM=	yes
STRIP=
HAS_CONFIGURE=	yes
XEMACS_ARCH=	${MACHINE_ARCH}--freebsd
CONFIGURE_ARGS=	${XEMACS_ARCH} --prefix=${PREFIX} \
		--with-mule \
		--with-xfs \
		--with-clash-detection \
		--lockdir=/var/run/emacs/lock \
		--with-sound=native \
		--site-includes=${PREFIX}/include \
		--site-libraries=${PREFIX}/lib \
		--sitelispdir="${PREFIX}/lib/xemacs/site-lisp ${PREFIX}/share/emacs/site-lisp" \
		--with-session=yes \
		--with-menubars=lucid --with-xim=xlib
MAN1=		ctags.1 etags.1 gnuattach.1 gnuclient.1 gnudoit.1 \
		gnuserv.1 xemacs.1
ALL_TARGET=	all dist
PLIST_SUB=	XEMACS_VER=20.4 XEMACS_ARCH=${XEMACS_ARCH}

# Have
pre-configure:
.if defined(HAVE_MOTIF)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If your MOTIF library is actually lesstif, you might"
	@${ECHO_MSG} "occasionally experience locked-up frames."
	@${ECHO_MSG} "In this case, set the environment variable MOTIF_STATIC"
	@${ECHO_MSG} "and recompile, which will force the use of athena
	@${ECHO_MSG} "widgets for dialogs."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Since XIM of LessTif is reported buggy, you have to set"
	@${ECHO_MSG} "REAL_MOTIF if you really have Motif. Otherwise it is"
	@${ECHO_MSG} "compiled with raw xlib by default."
.endif

# hack to avoid shipping binaries linked with Motif
.if defined(MOTIF_STATIC)
CONFIGURE_ARGS+= --with-dialogs=athena
.endif

# Drop faces (libcompface) and offix (libDnd) if building package,
# autodetect otherwise
.if defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+= --with-xface=no --with-offix=no
.endif

post-install:
.for file in b2m ctags etags gnuclient ${DISTNAME}
	strip ${PREFIX}/bin/${file}
.endfor
# ``make install'' does not set the permissions like pkg_add does.
	${CHMOD} 1777 /var/run/emacs/lock
	${CHMOD} 755 ${PREFIX}/lib/xemacs/site-lisp
	${CHMOD} 755 ${PREFIX}/share/emacs/site-lisp
	${RM} -f ${PREFIX}/bin/send-pr
	${RM} -f ${PREFIX}/lib/xemacs-20.4/lisp/mule/mule-init.el.orig
# Install xemacs20.sh into ${PREFIX}/etc/rc.d
	@if [ ! -d ${PREFIX}/etc/rc.d ]; then ${MKDIR} ${PREFIX}/etc/rc.d; fi
	${INSTALL_SCRIPT} ${FILESDIR}/xemacs20.sh ${PREFIX}/etc/rc.d
# Install Chinese Big5 related files.
	@${MKDIR} ${PREFIX}/lib/xemacs-20.4/etc/app-defaults/zh_TW.Big5
	@${INSTALL_DATA} ${FILESDIR}/Emacs ${PREFIX}/lib/xemacs-20.4/etc/app-defaults/zh_TW.Big5
	@${INSTALL_DATA} ${FILESDIR}/sample.emacs ${PREFIX}/lib/xemacs-20.4/etc/app-defaults/zh_TW.Big5
# Display XIM usages.
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
