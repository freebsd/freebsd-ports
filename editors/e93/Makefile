# New ports collection makefile for:	e93
# Version required:	1.2r6X
# Date created:		21 June 1995
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.15 1998/02/22 08:34:54 fenner Exp $
#

DISTNAME=	e93-1.2r6X
PKGNAME=	e93-1.2.6
CATEGORIES=	editors tcl81
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	editors

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	tcl81\\.1\\.:${PORTSDIR}/lang/tcl81

MAKEFILE=	makefile
USE_X11=	yes

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
