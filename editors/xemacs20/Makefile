# New ports collection makefile for:	X-Emacs
# Date created:		26 August 1997
# Whom:			Michael Elbel (me)
#
# $FreeBSD$
#

PORTNAME=	xemacs
PORTVERSION=	20.4
CATEGORIES=	editors
MASTER_SITES=	\
		ftp://ftp.xemacs.org/pub/xemacs/${DISTNAME}/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/${DISTNAME}/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/${DISTNAME}/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/${DISTNAME}/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/${DISTNAME}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${MULEDISTFILE}

MAINTAINER=	gj@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
STRIP=
HAS_CONFIGURE=	yes
XEMACS_ARCH=	${MACHINE_ARCH}--freebsd
CONFIGURE_ARGS=	${XEMACS_ARCH} --prefix=${PREFIX} \
		--with-clash-detection \
		--lockdir=/var/run/emacs/lock \
		--with-sound=native \
		--site-includes=${PREFIX}/include \
		--site-libraries=${PREFIX}/lib \
		--sitelispdir="${PREFIX}/lib/xemacs/site-lisp ${PREFIX}/share/emacs/site-lisp" \
		--infopath=${PREFIX}/lib/xemacs/info:${PREFIX}/info:${X11BASE}/info:/usr/info:${PREFIX}/lib/texmf/doc/info:/usr/lib/texmf/doc:/usr/share/info \
		--with-session=yes \
		${WITH_XFACE} ${WITH_MULE} ${WITH_DIALOGS} ${WITH_OFFIX}
MAN1=		ctags.1 etags.1 gnuattach.1 gnuclient.1 gnudoit.1 \
		gnuserv.1 xemacs.1
ALL_TARGET=	all dist
PLIST_SUB=	XEMACS_VER=20.4 XEMACS_ARCH=${XEMACS_ARCH}

# Have
pre-configure:
	@${ECHO_MSG} "To compile in the MULE features, set the environment variable WITH_MULE"
.if defined(HAVE_MOTIF)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If your MOTIF library is actually lesstif, you might occasionally"
	@${ECHO_MSG} "experience locked-up frames."
	@${ECHO_MSG} "In this case, set the environment variable MOTIF_STATIC and recompile, "
	@${ECHO_MSG} "which will force the use of athena widgets for dialogs."
.endif

.if defined(WITH_MULE)
WITH_MULE=	--with-mule
MULEDISTFILE=	${DISTNAME}-mule.tar.gz
PLIST=		${PKGDIR}/PLIST.mule
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

post-install:
.for file in b2m ctags etags gnuclient ${DISTNAME}
	strip ${PREFIX}/bin/${file}
.endfor
# ``make install'' does not set the permissions like pkg_add does.
	${CHMOD} 1777 /var/run/emacs/lock
	${CHMOD} 755 ${PREFIX}/lib/xemacs/site-lisp
	${CHMOD} 755 ${PREFIX}/share/emacs/site-lisp
	${RM} -f ${PREFIX}/bin/send-pr
# install xemacs20.sh into ${PREFIX}/etc/rc.d
	@if [ ! -d ${PREFIX}/etc/rc.d ]; then ${MKDIR} ${PREFIX}/etc/rc.d; fi
	${INSTALL_SCRIPT} ${FILESDIR}/xemacs20.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
