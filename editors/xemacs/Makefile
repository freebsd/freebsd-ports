# New ports collection makefile for:	X-Emacs
# Date created:		25 Oct 2001
# Whom:			Gary Jennejohn (gj@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xemacs
PORTVERSION=	${XEMACS_VER}
CATEGORIES+=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS}
MASTER_SITE_SUBDIR=	xemacs-${XEMACS_REL}
DISTNAME=	xemacs-${XEMACS_VER}
DIST_SUBDIR=	xemacs

MAINTAINER?=	pawel.worach@telia.com
COMMENT?=	This port tracks the stable version of the XEmacs text editor

XEMACS_REL=	21.4
XEMACS_VER=	21.4.17
XEMACS_ARCH=	${CONFIGURE_TARGET}

RUN_DEPENDS+=	${LOCALBASE}/lib/xemacs/xemacs-packages/etc/enriched.doc:${PORTSDIR}/editors/xemacs-packages

USE_BZIP2=	yes
STRIP=
USE_AUTOCONF_VER=213
CONFIGURE_TARGET=${MACHINE_ARCH}--freebsd

CONFIGURE_ARGS?=--with-clash-detection \
		--with-sound=native,nonas,noesd \
		--site-includes=${LOCALBASE}/include \
		--site-libraries=${LOCALBASE}/lib \
		--with-ldap=no \
		--with-site-lisp \
		--with-database=berkdb \
		${WITH_SCROLLBARS} ${WITH_DIALOGS} ${WITH_WIDGETS} \
		${WITH_XFACE} ${WITH_OFFIX}
MAKE_ARGS=	prefix=${PREFIX}
MAN1=		ctags.1 etags.1 gnuattach.1 gnuclient.1 gnudoit.1 \
		gnuserv.1 xemacs.1
ALL_TARGET=	all dist

PLIST_SUB=	XEMACS_VER=${XEMACS_VER} XEMACS_ARCH=${XEMACS_ARCH}

.include <bsd.port.pre.mk>

# Undump and malloc do not behave on amd64 at the moment
.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--with-system-malloc --pdump
BROKEN=		"Incomplete pkg-plist"
.endif

.if !defined(WITHOUT_X11)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		compface.1:${PORTSDIR}/mail/faces
CONFIGURE_ARGS+=	--with-png --with-jpeg --with-tiff
USE_XLIB=	yes
USE_XPM=	yes
.if !defined(WITHOUT_MOTIF) && !defined(MOTIF_STATIC)
USE_MOTIF=	yes
WITH_SCROLLBARS=	--with-scrollbars=motif
WITH_DIALOGS=	--with-dialogs=motif
WITH_WIDGETS=	--with-widgets=motif
.else
WITH_SCROLLBARS=	--with-scrollbars=athena
WITH_DIALOGS=	--with-dialogs=athena
WITH_WIDGETS=	--with-widgets=athena
.if defined(WITH_XAW3D)
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
CONFIGURE_ARGS+=	--with-athena=3d
.endif
.endif
.else
CONFIGURE_ARGS+=	--without-x11
.endif

pre-patch:
.if !defined(WITHOUT_X11)
.if !defined(WITHOUT_MOTIF) && !defined(MOTIF_STATIC)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If your MOTIF library is lesstif you might occasionally"
	@${ECHO_MSG} "experience locked-up frames."
	@${ECHO_MSG} "In this case, set the environment variable WITHOUT_MOTIF"
	@${ECHO_MSG} "and recompile, which will force the use of athena for"
	@${ECHO_MSG} "scrollbars, dialogs and widgets."
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Set the environment variable WITHOUT_X11 if you do not"
	@${ECHO_MSG} "want to use X11."
.endif

# Drop faces (libcompface) and offix (libDnd) if building package,
# autodetect otherwise
.if defined(PACKAGE_BUILDING)
WITH_XFACE?=	--with-xface=no
WITH_OFFIX?=	--with-offix=no
.endif

# fix .so references in a few man pages
pre-configure::
.for f in etc/ctags.1 etc/gnuattach.1 etc/gnuclient.1 etc/gnudoit.1
	@${SED} -e 's/\.1/&.gz/' ${WRKSRC}/${f} > ${WRKDIR}/tmp_zot
	@${MV} ${WRKDIR}/tmp_zot ${WRKSRC}/${f}
.endfor

post-install::
.for f in b2m ctags ellcc etags gnuclient xemacs-${XEMACS_VER}
	${STRIP_CMD} ${PREFIX}/bin/${f}
.endfor
# For some reason install no longer makes ${PREFIX}/lib/xemacs/site-lisp.
# Do what PLIST does for pkg_add.
	${MKDIR} ${PREFIX}/lib/xemacs/site-lisp
	${CHMOD} 755 ${PREFIX}/lib/xemacs/site-lisp
	${RM} -f ${PREFIX}/bin/send-pr

.include <bsd.port.post.mk>
