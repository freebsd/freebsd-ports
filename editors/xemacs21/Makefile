# New ports collection makefile for:	X-Emacs
# Version required:	20.2
# Date created:		26 August 1997
# Whom:			Michael Elbel (me)
#
# $Id: Makefile,v 1.3 1997/11/12 21:41:33 gj Exp $
#

DISTNAME=	xemacs-20.2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.xemacs.org/pub/xemacs-20.2/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs-20.2/ \
		ftp://ftp.usyd.edu.au:/pub/Xemacs/xemacs-20.2/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/xemacs-20.2/ \
		ftp://ftp.th-darmstadt.de:/pub/editors/xemacs/xemacs-20.2/ \
		ftp://SunSITE.sut.ac.jp/pub/archives/xemacs/xemacs-20.2/ \
		ftp://ftp.miranova.com/pub/xemacs/ \
		ftp://ftp.gw.com/mirrors/pub/unix/xemacs/xemacs-20.2/

MAINTAINER=	me@FreeBSD.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		png\\.0\\.:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
STRIP=
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	i386--freebsd --prefix=${PREFIX} \
		--statedir=/var/run \
		--with-sound=native \
		--site-includes=${PREFIX}/include \
		--site-libraries=${PREFIX}/lib \
		--sitelispdir="${PREFIX}/lib/xemacs/site-lisp ${PREFIX}/share/emacs/site-lisp" \
		${WITH_MULE} ${WITH_DIALOGS}
MAN1=		ctags.1 etags.1 gnuattach.1 gnuclient.1 gnudoit.1 \
		gnuserv.1 xemacs.1

pre-configure:
	@echo "To compile in the MULE features, set the environment variable USE_MULE"

.if defined(USE_MULE)
WITH_MULE=	--with-mule
.endif

# hack to avoid shipping binaries linked with Motif
.if defined(MOTIF_STATIC)
WITH_DIALOGS=	--with-dialogs=athena
.endif

post-install:
.for file in b2m ctags etags emacsclient gnuattach gnuclient \
	gnudoit xemacs-20.2
	strip ${PREFIX}/bin/${file}
.endfor
# ``make install'' does not set the permissions like pkg_add does.
	chmod 1777 /var/run/xemacs/lock
	chmod 755 ${PREFIX}/lib/xemacs/site-lisp
	chmod 755 ${PREFIX}/share/emacs/site-lisp

.include <bsd.port.mk>
