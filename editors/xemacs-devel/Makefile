# New ports collection makefile for:	X-Emacs
# Date created:		24 Apr 1999
# Whom:			Michael Elbel (me@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xemacs
PORTVERSION=	${XEMACS_VER}
CATEGORIES+=	editors
MASTER_SITES=	\
		ftp://ftp.xemacs.org/pub/xemacs/xemacs-${XEMACS_REL}/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/xemacs-${XEMACS_REL}/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/xemacs-${XEMACS_REL}/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/xemacs-${XEMACS_REL}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-elc${EXTRACT_SUFX} ${DISTNAME}-info${EXTRACT_SUFX}

MAINTAINER?=	gj@FreeBSD.org

RUN_DEPENDS+=	${LOCALBASE}/lib/xemacs/xemacs-packages/etc/enriched.doc:${PORTSDIR}/editors/xemacs-packages
LIB_DEPENDS+=	Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

XEMACS_REL=	21.1
XEMACS_VER=	21.1.9
DIST_SUBDIR=	xemacs

SLAVEDIRS+=	editors/xemacs21-mule
USE_XLIB=	yes
USE_GMAKE=	yes
STRIP=
HAS_CONFIGURE=	yes
XEMACS_ARCH=	${MACHINE_ARCH}--freebsd
CONFIGURE_ARGS?=${XEMACS_ARCH} --prefix=${PREFIX} \
		--with-clash-detection \
		--lockdir=/var/run/emacs/lock \
		--with-sound=native \
		--site-includes=${PREFIX}/include \
		--site-libraries=${PREFIX}/lib \
		--with-session=yes \
		--with-png=yes \
		--with-tiff=yes \
		${WITH_XFACE} ${WITH_DIALOGS} ${WITH_OFFIX}
MAKE_ARGS=	prefix=${PREFIX}
.if !defined(MULE_SLAVE)
MAN1=		ctags.1 etags.1 gnuattach.1 gnuclient.1 gnudoit.1 \
		gnuserv.1 xemacs.1
.endif
.if !defined(MULE_PORT)
ALL_TARGET=	all dist
.endif

PLIST_SUB=	XEMACS_VER=${XEMACS_VER} XEMACS_ARCH=${XEMACS_ARCH}

.if !defined(MULE_PORT)
pre-fetch:
	@${ECHO_MSG} "If you want the MULE features, please use the xemacs-mule port"
.if defined(HAVE_MOTIF)
.if !defined(MOTIF_STATIC)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If your MOTIF library is actually lesstif, you might occasionally"
	@${ECHO_MSG} "experience locked-up frames."
	@${ECHO_MSG} "In this case, set the environment variable MOTIF_STATIC and recompile, "
	@${ECHO_MSG} "which will force the use of athena widgets for dialogs."
.endif
.endif

# hack to avoid shipping binaries linked with Motif
.if defined(MOTIF_STATIC)
WITH_DIALOGS=	--with-dialogs=athena
.endif

# Drop faces (libcompface) and offix (libDnd) if building package,
# autodetect otherwise
.if defined(PACKAGE_BUILDING)
WITH_XFACE?=	--with-xface=no
WITH_OFFIX?=	--with-offix=no
.endif
.endif

post-install::
.if !defined(MULE_COMMON)
	${LN} -sf xemacs-${XEMACS_VER} ${PREFIX}/bin/xemacs21${BINNAMEEXT}
.for file in b2m ctags etags gnuclient xemacs-${XEMACS_VER}
	strip ${PREFIX}/bin/${file}
.endfor
.endif
.if !defined(MULE_SLAVE)
# ``make install'' does not set the permissions like pkg_add does.
	${MKDIR} /var/run/emacs/lock
	${CHMOD} 1777 /var/run/emacs/lock
	${RM} -f ${PREFIX}/bin/send-pr
# install xemacs21.sh into ${PREFIX}/etc/rc.d
	@if [ ! -d ${PREFIX}/etc/rc.d ]; then ${MKDIR} ${PREFIX}/etc/rc.d; fi
	${INSTALL_SCRIPT} ${FILESDIR}/xemacs21.sh ${PREFIX}/etc/rc.d
.endif

.include <bsd.port.mk>
