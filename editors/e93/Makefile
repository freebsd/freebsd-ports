# New ports collection makefile for:	e93
# Version required:	1.2r6X
# Date created:		21 June 1995
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.4 1995/09/12 22:47:20 asami Exp $
#

DISTNAME=	e93-1.2r6X
PKGNAME=	e93-1.2.6
CATEGORIES+=	editors
MASTER_SITES=	ftp://ftp.x.org/contrib/editors/ \
		ftp://crl.dec.com/pub/X11/contrib/editors/

MAINTAINER=	asami@FreeBSD.ORG

LIB_DEPENDS=	tcl75\\.1\\.:${PORTSDIR}/lang/tcl75

MAKEFILE=	makefile
USE_X11=	yes
IS_INTERACTIVE=	yes	# asks "ok?" about license

pre-install:
	@/usr/bin/env PKG_PREFIX=${PREFIX} /bin/sh ${PKGDIR}/REQ ${PKGNAME} INSTALL
do-install:
	mkdir -p ${PREFIX}/lib/e93 ${PREFIX}/share/doc/e93
	(cd ${WRKSRC}; \
	  install -c -s e93 ${PREFIX}/bin; \
	  install -c .e93rc ${PREFIX}/lib/e93; \
	  install -c LICENSE.TXT ${PREFIX}/share/doc/e93/LICENSE.TXT; \
	)

.include <bsd.port.mk>
