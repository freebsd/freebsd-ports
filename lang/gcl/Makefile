# New ports collection makefile for:    gcl
# Version required:     2.0
# Date created:         Wed Feb  8 01:49:11  1995
# Whom:                 hsu
#
# $Id: Makefile,v 1.5 1995/04/24 11:29:11 asami Exp $
#

DISTNAME=       gcl-2.0
CATEGORIES+=	lang
MASTER_SITES=   ftp://ftp.cli.com/pub/gcl/ ftp://math.utexas.edu/pub/gcl/
EXTRACT_SUFX=	.tgz
MAKEFILE=	makefile

do-install:
	@(cd ${WRKSRC}; ${MAKE} PREFIX_DIR=${PREFIX} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

.include <bsd.port.mk>
