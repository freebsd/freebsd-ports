# New ports collection makefile for:	Wnn
# Version required:	4.2
# Date created:		22 November 1994
# Whom:			asami
#
# $Id: Makefile,v 1.12 1996/09/19 04:37:04 asami Exp $
#

DISTNAME=	Wnn4.2
PKGNAME=	jp-Wnn-4.2
CATEGORIES=	japanese
MASTER_SITES=	ftp://utsun.s.u-tokyo.ac.jp/fj/

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/Xsi
IS_INTERACTIVE=	yes

# These are necesary because this package uses a different Makefile for
#  building and installing etc.
do-build:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} Makefile.inst World)

post-install:
# This package uses imake's "install.man" target to install man pages but
#  I can't define USE_IMAKE because it doesn't involve xmkmf
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
