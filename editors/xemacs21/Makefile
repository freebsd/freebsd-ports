# New ports collection makefile for:	X-Emacs
# Date created:		24 Apr 1999
# Whom:			Michael Elbel (me@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xemacs
PORTVERSION=	${XEMACS_VER}
CATEGORIES+=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS}
MASTER_SITE_SUBDIR=	xemacs-${XEMACS_REL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-elc${EXTRACT_SUFX} ${DISTNAME}-info${EXTRACT_SUFX}
DIST_SUBDIR=	xemacs

MAINTAINER?=	gj@FreeBSD.org

RUN_DEPENDS+=	${LOCALBASE}/lib/xemacs/xemacs-packages/etc/enriched.doc:${PORTSDIR}/editors/xemacs-packages
.if !defined(WITHOUT_X11)
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff
USE_XLIB=	yes
USE_XPM=	yes
.endif

XEMACS_REL=	21.1
XEMACS_VER=	21.1.14
XEMACS_ARCH=	${CONFIGURE_TARGET}

SLAVEDIRS+=	editors/xemacs21-mule
STRIP=
USE_AUTOCONF_VER=213
CONFIGURE_TARGET=${MACHINE_ARCH}--freebsd

CONFIGURE_ARGS?=--with-clash-detection \
		--lockdir=/var/run/emacs/lock \
		--with-sound=native \
		--with-session=yes \
		--site-includes=${LOCALBASE}/include \
		--site-libraries=${LOCALBASE}/lib \
		--gung-ho=yes \
		--with-ldap=no \
		--with-site-lisp \
		--with-database=berkdb \
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

.if !defined(WITHOUT_X11)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Set the environment variable WITHOUT_X11 if you "
	@${ECHO_MSG} "do not want to use X11."
CONFIGURE_ARGS+=	--with-png=yes --with-tiff=yes
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x11
.endif

.if defined(WITH_XAW3D)
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
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
# the next .endif belongs to !MULE_PORT
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
CONFIGURE_ARGS+=       --ldflags=-Wl,-znocombreloc
.endif

# fix .so references in a few man pages
pre-configure::
.for file in etc/ctags.1 etc/gnuattach.1 etc/gnuclient.1 etc/gnudoit.1
	@${SED} -e 's/\.1/&.gz/' ${WRKSRC}/${file} > ${WRKDIR}/tmp_zot
	@${MV} ${WRKDIR}/tmp_zot ${WRKSRC}/${file}
.endfor

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
# For some reason install no longer makes ${PREFIX}/lib/xemacs/site-lisp.
# Do what PLIST does for pkg_add.
	${MKDIR} ${PREFIX}/lib/xemacs/site-lisp
	${CHMOD} 755 ${PREFIX}/lib/xemacs/site-lisp
	${RM} -f ${PREFIX}/bin/send-pr
# install xemacs21.sh into ${PREFIX}/etc/rc.d
	@if [ ! -d ${PREFIX}/etc/rc.d ]; then ${MKDIR} ${PREFIX}/etc/rc.d; fi
	${INSTALL_SCRIPT} ${FILESDIR}/xemacs21.sh ${PREFIX}/etc/rc.d
.endif

.include <bsd.port.post.mk>
