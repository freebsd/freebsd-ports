# New ports collection makefile for: CAML
# Date created:		21 July 1998
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=	caml
PORTVERSION=	0.75
PORTREVISION=	3
CATEGORIES=	lang elisp
MASTER_SITES=	http://caml.inria.fr/pub/distrib/caml-light-0.75/ \
		ftp://arcadia.informatik.uni-muenchen.de/pub/comp/programming/languages/functional/caml-light/

DISTNAME=	cl75unix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A strongly typed functional language belonging to the ML family

USE_XORG=	x11
WRKSRC=		${WRKDIR}/cl75
ALL_TARGET=	configure world bootstrap
MAN1=		camlc.1 camllex.1 camllibr.1 camllight.1 camlmktop.1 \
		camlrun.1 camlyacc.1 mletags.1 camllorder.1 camlsearch.1

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET}

# build some contrib stuff too
do-install:
	cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET}
	cd ${WRKSRC}/contrib; ${SETENV} ${MAKE_ENV} ${MAKE} all \
		${INSTALL_TARGET}

.include <bsd.port.post.mk>
