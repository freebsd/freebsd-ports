# New ports collection makefile for:	ftnchek
# Date created:		4 May 1998
# Whom:			kargl@apl.washington.edu
#
# $FreeBSD$

PORTNAME=	ftnchek
PORTVERSION=	3.1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netlib.org/fortran/
DISTFILES=	${PORTNAME}.tgz

MAINTAINER=	ports@FreeBSD.org

MAN1=		dcl2inc.1 ftnchek.1

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_dir_lispdir=${PREFIX}/share/emacs/site-lisp

pre-install:
	${MKDIR} ${PREFIX}/share/emacs/site-lisp

post-install:
	strip ${PREFIX}/bin/ftnchek

.include <bsd.port.mk>
