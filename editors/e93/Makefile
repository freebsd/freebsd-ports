# New ports collection makefile for:	e93
# Version required:	1.2r6X
# Date created:		21 June 1995
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.9 1996/11/17 07:01:21 obrien Exp $
#

DISTNAME=	e93-1.2r6X
PKGNAME=	e93-1.2.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	editors

MAINTAINER=	asami@FreeBSD.ORG

MAKEFILE=	makefile
USE_X11=	yes
IS_INTERACTIVE=	yes	# asks "ok?" about license

pre-install:
	@/usr/bin/env PKG_PREFIX=${PREFIX} /bin/sh ${PKGDIR}/REQ ${PKGNAME} INSTALL
do-install:
	${MKDIR} ${PREFIX}/lib/e93 ${PREFIX}/share/doc/e93
	(cd ${WRKSRC}; \
	  ${INSTALL_PROGRAM} e93 ${PREFIX}/bin; \
	  ${INSTALL_DATA} .e93rc ${PREFIX}/lib/e93; \
	  ${INSTALL_DATA} LICENSE.TXT ${PREFIX}/share/doc/e93/LICENSE.TXT; \
	)

.include <bsd.port.mk>
