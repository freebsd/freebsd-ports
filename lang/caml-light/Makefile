# New ports collection makefile for: CAML
# Version required:	0.74
# Date created:		21 July 1998
# Whom:			jkoshy
#
# $Id: Makefile,v 1.4 1998/11/20 15:26:10 kuriyama Exp $
#

DISTNAME=	cl74unix
PKGNAME=	caml-0.74
CATEGORIES=	lang elisp
MASTER_SITES=	ftp://ftp.inria.fr/lang/caml-light/ \
	ftp://sunsite.doc.ic.ac.uk/computing/programming/languages/ml/caml-light/ \
	ftp://arcadia.informatik.uni-muenchen.de/pub/comp/programming/languages/functional/caml-light/ \
	ftp://sunsite.icm.edu.pl/pub/programming/caml/ \
	http://wwwfun.kurims.kyoto-u.ac.jp/soft/caml-light/

MAINTAINER=	jkoshy@freebsd.org

BROKEN_ELF=	cp: bignum/libbignum.a: No such file or directory

USE_XLIB=	yes
WRKSRC=		${WRKDIR}/cl74
ALL_TARGET=	configure world bootstrap
MAN1=	camlc.1 camllex.1 camllibr.1 camllight.1 camlmktop.1 camlrun.1 camlyacc.1 mletags.1 camllorder.1 camlsearch.1

do-build:
	cd ${WRKSRC}/src; ${MAKE} ${ALL_TARGET} PREFIX=${PREFIX} \
	X11BASE=${X11BASE}

do-install:
	cd ${WRKSRC}/src; ${MAKE} ${INSTALL_TARGET} PREFIX=${PREFIX} \
	X11BASE=${X11BASE}

# build some contrib stuff too
post-install:
	cd ${WRKSRC}/contrib; ${MAKE} all ${INSTALL_TARGET} PREFIX=${PREFIX} \
	X11BASE=${X11BASE}

.include <bsd.port.mk>
