# New ports collection makefile for:	files except executables for xemacs with mule
# Version required:	20.4
# Date created:		5 Dec 1997
# Whom:			Kazuyuki IENAGA <ienaga@jsys.co.jp>
#
# $Id: Makefile,v 1.3 1998/12/02 08:01:14 asami Exp $
#

DISTNAME=	xemacs-20.4
PKGNAME=	xemacs-mule-common-20.4
CATEGORIES=	editors japanese
MASTER_SITES=	ftp://unipro.jsys.co.jp/pub/editor/xemacs/20.4/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/xemacs-20.4/ \
		ftp://ftp.xemacs.org/pub/xemacs-20.4/ \
		ftp://ftp2.xemacs.org/pub/xemacs/xemacs-20.4/ \
		ftp://ftp.jpl.org/pub/elisp/
DISTFILES=	xemacs-20.4.tar.gz xemacs-20.4-elc.tar.gz \
		xemacs-20.4-info.tar.gz xemacs-20.4-mule.tar.gz \
		ps-print-jp.el.gz

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

# from xemacs-mule
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.2:${PORTSDIR}/graphics/png \
		compface.1:${PORTSDIR}/mail/faces
USE_AUTOCONF=	yes

EXTRACT_ONLY=	xemacs-20.4.tar.gz xemacs-20.4-elc.tar.gz \
		xemacs-20.4-info.tar.gz xemacs-20.4-mule.tar.gz

.include <bsd.port.pre.mk>

.for dir in \
	editors/xemacs-mule \
	japanese/xemacs \
	japanese/xemacs-canna \
	japanese/xemacs-canna+wnn4 \
	japanese/xemacs-canna+wnn6 \
	japanese/xemacs-wnn4 \
	japanese/xemacs-wnn6
.if exists(${WRKDIRPREFIX}${PORTSDIR}/${dir}/work/.install_done)
WRKDIR=		${WRKDIRPREFIX}${PORTSDIR}/${dir}/work
.if !exists(${WRKDIR}/.install_done-${PKGNAME})
rvalue_touch!=	${TOUCH} ${WRKDIR}/.install_done-${PKGNAME}
.endif
.elif exists(${WRKDIRPREFIX}${PORTSDIR}/${dir}/work/.build_done)
WRKDIR?=	${WRKDIRPREFIX}${PORTSDIR}/${dir}/work
.endif
.endfor
WRKSRC= ${WRKDIR}/xemacs-20.4

.if !defined(WRKDIR)
.if defined(PACKAGE_BUILDING)
# XXX
pre-build:
	@cd ${.CURDIR}/../xemacs-mule; make
.else
BROKEN=		You should build install one of the other xemacs ports first
.endif
.endif

INSTALL_COOKIE=	${WRKDIR}/.install_done-${PKGNAME}
PACKAGE_COOKIE=	${WRKDIR}/.package_done-${PKGNAME}
TMPPLIST=	${WRKDIR}/.PLIST.mktmp-${PKGNAME}

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	i386-unknown-freebsd \
		--with-x11 \
		--with-mule \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib
STRIP=
MAN1=		ctags.1 etags.1 gnuattach.1 gnuclient.1 gnudoit.1 \
		gnuserv.1 xemacs.1

INSTALL_TARGET=	install-arch-indep

PLIST_SUB=	XEMACS_DIR=xemacs-20.4

pre-build:
	${RM} -f ${WRKSRC}/lib-src/DOC* ${WRKSRC}/src/xemacs

pre-install:
	@${MKDIR} ${PREFIX}/lib/xemacs
	@(cd ${PREFIX}/lib/xemacs; ${MKDIR} info etc site-lisp)
	@if [ ! -f ${PREFIX}/lib/xemacs/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/lib/xemacs/info/dir; \
	fi

post-install:
# install xemacs-mule.sh into ${PREFIX}/etc/rc.d
	@${MKDIR} /var/run/emacs/lock
	chmod 1777 /var/run/emacs/lock
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${FILESDIR}/xemacs-mule.sh ${PREFIX}/etc/rc.d
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

post-package:
	@${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE}

.include <bsd.port.post.mk>
