# New ports collection makefile for:    ha
# Version required:     0999
# Date created:         24 Jan 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.2 1995/01/24 16:56:05 ache Exp $
#
DISTNAME=       ha0999
EXTRACT_SUFX=   .tgz
MASTER_SITES=   ftp://ftp.kiae.su/unix/arcers/
CATEGORIES+=	archivers
NO_WRKSUBDIR=   YES
MAKEFILE=       makefile.nix
MAKE_FLAGS=     CC=cc -f
ALL_TARGET=     ha
USE_GMAKE=      YES

install:
	cd ${WRKSRC}; ${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ha ${PREFIX}/bin
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

.include <bsd.port.mk>
