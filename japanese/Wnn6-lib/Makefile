# New ports collection makefile for:	Wnn
# Version required:	4.2
# Date created:		22 November 1994
# Whom:			asami
#
# $Id: Makefile,v 1.8 1995/04/01 12:46:22 jkh Exp $
#

DISTNAME=	Wnn4.2
PKGNAME=	Wnn-4.2
CATEGORIES+=	japanese
MASTER_SITES=	ftp://utsun.s.u-tokyo.ac.jp/fj/

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/Xsi
IS_INTERACTIVE=	yes

# These are necesary because this package uses a different Makefile for
#  building and installing etc.
pre-build:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} Makefile.inst World)

pre-install:
	@PREFIX=${PREFIX} ${SCRIPTDIR}/pre-install
# This package uses imake's "install.man" target to install man pages but
#  I can't define USE_IMAKE because it doesn't involve xmkmf
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

pre-reinstall: pre-install

.include <bsd.port.mk>
