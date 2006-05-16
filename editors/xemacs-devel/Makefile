# New ports collection makefile for:	X-Emacs
# Date created:		25 Oct 2001
# Whom:			Gary Jennejohn (gj@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xemacs-devel
PORTVERSION=	${XEMACS_VER:S/-/./}
PORTEPOCH=	1
CATEGORIES+=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS}
MASTER_SITE_SUBDIR=	xemacs-${XEMACS_REL}
DISTNAME=	xemacs-${XEMACS_VER:S/-b/./}
#DISTFILES=	${DISTNAME}.11${EXTRACT_SUFX}
DIST_SUBDIR=	xemacs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	This port tracks the development (GAMMA) version of the XEmacs text editor

CONFLICTS=	emacs-19.* emacs-21.* \
		xemacs-[0-9]* \
		xemacs-mule-[0-9]* xemacs-devel-mule-[0-9]*

RUN_DEPENDS+=	${LOCALBASE}/lib/xemacs/xemacs-packages/etc/enriched.doc:${PORTSDIR}/editors/xemacs-packages
.if !defined(WITHOUT_X11)
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		compface.1:${PORTSDIR}/mail/faces
USE_XLIB=	yes
USE_XPM=	yes
.endif

XEMACS_MAJOR_VER?=	21
XEMACS_REL=		${XEMACS_MAJOR_VER}.5
XEMACS_VER=		${XEMACS_MAJOR_VER}.5-b27
XEMACS_ARCH=		${CONFIGURE_TARGET}

WRKSRC=		${WRKDIR}/xemacs-${XEMACS_VER:S/-b/./}
STRIP=
USE_AUTOTOOLS=	autoconf:259
CONFIGURE_TARGET=${MACHINE_ARCH}--freebsd

CONFIGURE_ARGS?=--enable-clash-detection \
		--enable-sound=native,nonas,noesd \
		--with-site-includes=${LOCALBASE}/include \
		--with-site-libraries=${LOCALBASE}/lib \
		--with-ldap=no \
		--with-postgresql=no \
		--with-site-lisp \
		--enable-database=berkdb \
		--disable-debug \
		--disable-error-checking \
		--disable-kkcc \
		--disable-newgc	\
		${WITH_XFACE} ${WITH_DIALOGS} ${WITH_OFFIX} ${WITH_GTK}
MAKE_ARGS=	prefix=${PREFIX}
MAN1=		ctags.1 etags.1 gnuattach.1 gnuclient.1 gnudoit.1 \
		gnuserv.1 xemacs.1
ALL_TARGET=	all dist

PLIST_SUB=	XEMACS_VER=${XEMACS_VER} XEMACS_ARCH=${XEMACS_ARCH}

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/lib/libXm.so)
USE_MOTIF=	yes
HAVE_MOTIF=	yes
.endif

pre-fetch:
#.if !defined(WANT_GTK)
#	@${ECHO_MSG} "If you want to use GTK, please set the environment variable WANT_GTK "
#	@${ECHO_MSG} "and recompile."
#.endif
.if defined(HAVE_MOTIF)
.if !defined(MOTIF_STATIC)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If your MOTIF library is actually lesstif, you might occasionally"
	@${ECHO_MSG} "experience locked-up frames."
	@${ECHO_MSG} "In this case, set the environment variable MOTIF_STATIC and recompile, "
	@${ECHO_MSG} "which will force the use of athena widgets for dialogs."
.endif
.if !defined(WITHOUT_X11)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Set the environment variable WITHOUT_X11 if you "
	@${ECHO_MSG} "do not want to use X11."
CONFIG_ARGS+= --with-png=yes --with-tiff=yes
.endif
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--with-x11=no
.endif

# hack to avoid shipping binaries linked with Motif
.if defined(MOTIF_STATIC)
WITH_DIALOGS=	--enable-dialogs=athena
.endif

.if defined(WITH_XAW3D)
LIB_DEPENDS+=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d
CONFIGURE_ARGS+=	--with-athena=3d
.endif

#.if defined(WANT_GTK)
#WITH_GTK=	--with-gtk=yes \
#		--with-xpm=no
# doesn't work with gtk12?
#USE_GNOME=	gtk20
#USE_XPM=	no
#.endif

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
.for file in b2m ctags ellcc etags gnuclient ootags xemacs-${XEMACS_VER}
	${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
	${FIND} ${PREFIX}/lib/xemacs-${XEMACS_VER} -name \*.orig \
		-exec ${RM} -f \{} \;
	${RM} -f ${PREFIX}/bin/send-pr \
		 ${PREFIX}/lib/xemacs-${XEMACS_VER}/${XEMACS_ARCH}/modules/auto-autoloads.el~
#.if defined(WANT_GTK)
#	@${ECHO_MSG} "Please be aware that GTK support is buggy. Do not report bugs to"
#	@${ECHO_MSG} "the maintainer."
#	@${ECHO_MSG} "Please also be aware that the package's name was automagically changed"
#	@${ECHO_MSG} "to ${PORTNAME}${PKGNAMESUFFIX}-${XEMACS_VER}."
#.endif

.include <bsd.port.post.mk>
