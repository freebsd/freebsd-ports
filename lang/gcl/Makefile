# New ports collection makefile for:    gcl
# Version required:     1.1
# Date created:         Wed Feb  8 01:49:11  1995
# Whom:                 hsu
#
# $Id: Makefile,v 1.1.1.1 1995/02/12 21:10:01 hsu Exp $
#

DISTNAME=       gcl-1.1
MASTER_SITES=   ftp://ftp.cli.com/pub/gcl/ ftp://math.utexas.edu/pub/gcl/
CATEGORIES+=	languages
EXTRACT_SUFX=	.tgz
MAKEFILE=	makefile

INSTALL_COOKIE=	${WRKDIR}/.install_done
install: build ${INSTALL_COOKIE}

${INSTALL_COOKIE}:
	@echo "===>  Installing for ${DISTNAME}"
	@${MAKE} ${.MAKEFLAGS} pre-install
	@(cd ${WRKSRC}; ${MAKE} PREFIX_DIR=${PREFIX} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

.include <bsd.port.mk>
