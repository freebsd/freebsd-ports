# New ports collection makefile for: CAML
# Date created:		21 July 1998
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=	caml
PORTVERSION=	0.75
CATEGORIES=	lang elisp
MASTER_SITES=	ftp://ftp.inria.fr/lang/caml-light/ \
	ftp://sunsite.doc.ic.ac.uk/computing/programming/languages/ml/caml-light/ \
	ftp://arcadia.informatik.uni-muenchen.de/pub/comp/programming/languages/functional/caml-light/ \
	ftp://sunsite.icm.edu.pl/pub/programming/caml/ \
	http://wwwfun.kurims.kyoto-u.ac.jp/soft/caml-light/
DISTNAME=	cl75unix

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	A strongly typed functional language belonging to the ML family

USE_XLIB=	yes
WRKSRC=		${WRKDIR}/cl75
ALL_TARGET=	configure world bootstrap
MAN1=	camlc.1 camllex.1 camllibr.1 camllight.1 camlmktop.1 camlrun.1 camlyacc.1 mletags.1 camllorder.1 camlsearch.1

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC}/src; ${MAKE} ${ALL_TARGET} PREFIX=${PREFIX} \
	X11BASE=${X11BASE}

# build some contrib stuff too
do-install:
	cd ${WRKSRC}/src; ${MAKE} ${INSTALL_TARGET} PREFIX=${PREFIX} \
	X11BASE=${X11BASE}
	cd ${WRKSRC}/contrib; ${MAKE} all ${INSTALL_TARGET} PREFIX=${PREFIX} \
	X11BASE=${X11BASE}

.include <bsd.port.post.mk>
