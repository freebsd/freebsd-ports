# New ports collection makefile for:    ha
# Version required:     0.999beta
# Date created:         24 Jan 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.3 1995/04/01 12:43:23 jkh Exp $
#

DISTNAME=       ha0999
PKGNAME=        ha-0.999b
CATEGORIES+=	archivers
MASTER_SITES=   ftp://ftp.kiae.su/unix/arcers/
EXTRACT_SUFX=   .tgz

MAINTAINER=     ache@FreeBSD.ORG

NO_WRKSUBDIR=   yes
MAKEFILE=       makefile.nix
MAKE_FLAGS=     CC=cc -f
ALL_TARGET=     ha
USE_GMAKE=      yes

install:
	cd ${WRKSRC}; ${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ha ${PREFIX}/bin
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

.include <bsd.port.mk>
