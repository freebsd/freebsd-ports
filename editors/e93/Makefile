# New ports collection makefile for:	e93
# Version required:	1.2r6X
# Date created:		21 June 1995
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.18 1998/03/17 07:48:56 tg Exp $
#

DISTNAME=	e93-1.2r6X
PKGNAME=	e93-1.2.6
CATEGORIES=	editors tcl80
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	editors

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	tcl80\\.1\\.:${PORTSDIR}/lang/tcl80

MAKEFILE=	makefile
USE_X_PREFIX=	yes

.if !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes	# asks "ok?" about license

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL
.endif

do-install:
	${MKDIR} ${PREFIX}/lib/e93 ${PREFIX}/share/doc/e93
	(cd ${WRKSRC}; \
	  ${INSTALL_PROGRAM} e93 ${PREFIX}/bin; \
	  ${INSTALL_DATA} .e93rc ${PREFIX}/lib/e93; \
	  ${INSTALL_DATA} LICENSE.TXT ${PREFIX}/share/doc/e93/LICENSE.TXT; \
	)

.include <bsd.port.mk>
