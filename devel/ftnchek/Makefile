# New ports collection makefile for:	ftnchek
# Version required:	2.10.1
# Date created:		4 May 1998
# Whom:			kargl@apl.washington.edu
#
# $Id: Makefile,v 1.3 1998/11/28 01:20:53 asami Exp $

DISTNAME=	ftnchek
PKGNAME=	ftnchek-2.10.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netlib.org/fortran/

MAINTAINER=     kargl@apl.washington.edu

WRKSRC=		${WRKDIR}/${PKGNAME}

MAN1=		dcl2inc.1 ftnchek.1

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_dir_lispdir=${PREFIX}/share/emacs/site-lisp

pre-install:
	${MKDIR} ${PREFIX}/share/emacs/site-lisp

post-install:
	strip ${PREFIX}/bin/ftnchek

.include <bsd.port.mk>
