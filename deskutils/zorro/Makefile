# New ports collection makefile for:	zorro
# Version required:     1.1p8
# Date created:         03 Aug 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $Id: Makefile,v 1.1.1.1 1996/08/04 00:22:21 chuckr Exp $
#

DISTNAME=	zorro-1.1p8
PKGNAME=	zorro-1.1
CATEGORIES+=	misc x11
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	shanee@rabbit.augusta.de

LIB_DEPENDS=	tcl75\\.1\\.:${PORTSDIR}/lang/tcl75 \
		tk41\\.1\\.:${PORTSDIR}/x11/tk41

NO_BUILD=	yes

do-install:
	cp ${WRKDIR}/zorro-1.1p8/zorro $(PREFIX)/bin/zorro

post-install:
	@echo ""
	@echo "Take a look at work/zorro-1.1p8/DOTzorrorc
	@echo ""

.include <bsd.port.mk>
