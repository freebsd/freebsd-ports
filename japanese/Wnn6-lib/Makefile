# New ports collection makefile for:	Wnn
# Version required:	4.2
# Date created:		22 November 1994
# Whom:			asami
#
# $id: Makefile,v 1.0 1994/10/21 00:00:00 asami Exp $
#

DISTNAME=	Wnn4.2
MASTER_SITES=	ftp://utsun.s.u-tokyo.ac.jp/fj/
PKG_CMD=	pkg_create -N
WRKSRC=		${WRKDIR}/Xsi

# These are necesary because this package uses a different Makefile for
#  building and installing etc.
pre-build:
	@echo "===>  Building for ${DISTNAME}"
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} Makefile.inst World)
build: configure pre-build depends ${BUILD_COOKIE}

# This package uses imake's "install.man" target to install man pages but
#  I can't define USE_IMAKE because it doesn't involve xmkmf
pre-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
