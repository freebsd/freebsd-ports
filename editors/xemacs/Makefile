# New ports collection makefile for:	X-Emacs
# Date created:		25 Oct 2001
# Whom:			Gary Jennejohn (gj@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xemacs-devel
PORTVERSION=	${XEMACS_VER}
CATEGORIES+=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS}
MASTER_SITE_SUBDIR=	xemacs-${XEMACS_REL}
DISTNAME=	xemacs-${XEMACS_VER}
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX} ${DISTNAME}-elc${EXTRACT_SUFX} ${DISTNAME}-info${EXTRACT_SUFX}
DIST_SUBDIR=	xemacs

MAINTAINER=	gj@FreeBSD.org

RUN_DEPENDS+=	${LOCALBASE}/lib/xemacs/xemacs-packages/etc/enriched.doc:${PORTSDIR}/editors/xemacs-packages
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

XEMACS_REL=	21.4
XEMACS_VER=	21.4.5
XEMACS_ARCH=	${CONFIGURE_TARGET}

USE_XLIB=	yes
USE_XPM=	yes
STRIP=
USE_AUTOCONF_VER=213
CONFIGURE_TARGET=${MACHINE_ARCH}--freebsd

CONFIGURE_ARGS?=--with-clash-detection \
		--with-sound=native \
		--site-includes=${LOCALBASE}/include \
		--site-libraries=${LOCALBASE}/lib \
		--with-png=yes \
		--with-tiff=yes \
		--with-ldap=no \
		--with-site-lisp \
		--with-database=berkdb \
		${WITH_XFACE} ${WITH_DIALOGS} ${WITH_OFFIX} ${WITH_GTK}
MAKE_ARGS=	prefix=${PREFIX}
MAN1=		ctags.1 etags.1 gnuattach.1 gnuclient.1 gnudoit.1 \
		gnuserv.1 xemacs.1
ALL_TARGET=	all dist

PLIST_SUB=	XEMACS_VER=${XEMACS_VER} XEMACS_ARCH=${XEMACS_ARCH}

pre-fetch:
.if !defined(WANT_GTK)
	@${ECHO_MSG} "If you want to use GTK, please set the environment variable WANT_GTK and recompile."
.endif
.if defined(HAVE_MOTIF)
.if !defined(MOTIF_STATIC)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If your MOTIF library is actually lesstif, you might occasionally"
	@${ECHO_MSG} "experience locked-up frames."
	@${ECHO_MSG} "In this case, set the environment variable MOTIF_STATIC and recompile, "
	@${ECHO_MSG} "which will force the use of athena widgets for dialogs."
.endif

# hack to avoid shipping binaries linked with Motif
.if defined(MOTIF_STATIC)
WITH_DIALOGS=	--with-dialogs=athena
.endif

.if defined(WANT_GTK)
WITH_GTK=	--with-gtk=yes \
		--with-xpm=no
USE_GTK=	yes
USE_XPM=	no
.endif

# Drop faces (libcompface) and offix (libDnd) if building package,
# autodetect otherwise
.if defined(PACKAGE_BUILDING)
WITH_XFACE?=	--with-xface=no
WITH_OFFIX?=	--with-offix=no
.endif
.endif

# fix .so references in a few man pages
pre-configure::
.for file in etc/ctags.1 etc/gnuattach.1 etc/gnuclient.1 etc/gnudoit.1
	@${SED} -e 's/\.1/&.gz/' ${WRKSRC}/${file} > ${WRKDIR}/tmp_zot
	@${MV} ${WRKDIR}/tmp_zot ${WRKSRC}/${file}
.endfor

post-install::
.for file in b2m ctags ellcc etags gnuclient xemacs-${XEMACS_VER}
	strip ${PREFIX}/bin/${file}
.endfor
# For some reason install no longer makes ${PREFIX}/lib/xemacs/site-lisp.
# Do what PLIST does for pkg_add.
	${MKDIR} ${PREFIX}/lib/xemacs/site-lisp
	${CHMOD} 755 ${PREFIX}/lib/xemacs/site-lisp
	${RM} -f ${PREFIX}/bin/send-pr
.if defined(WANT_GTK)
	@${ECHO_MSG} "Please be aware that GTK support is buggy. Do not report bugs to"
	@${ECHO_MSG} "the maintainer."
	@${ECHO_MSG} "Please also be aware that the package's name was automagically changed"
	@${ECHO_MSG} "to ${PORTNAME}${PKGNAMESUFFIX}-${XEMACS_VER}."
.endif

.include <bsd.port.mk>
