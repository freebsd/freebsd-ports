# New ports collection makefile for:	zorro
# Version required:     1.1p8
# Date created:         03 Aug 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $Id: Makefile,v 1.2 1996/08/04 00:27:01 chuckr Exp $
#

DISTNAME=	zorro-1.1p8
PKGNAME=	zorro-1.1.8
CATEGORIES+=	misc
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	shanee@rabbit.augusta.de

LIB_DEPENDS=	tcl75\\.1\\.:${PORTSDIR}/lang/tcl75 \
		tk41\\.1\\.:${PORTSDIR}/x11/tk41

NO_BUILD=	yes

do-install:
	install -c -m 755 -g bin -o bin  ${WRKSRC}/zorro $(PREFIX)/bin/zorro
	mkdir -p $(PREFIX)/share/zorro
	install -c -m 644 -g bin -o bin $(WRKSRC)/DOTzorrorc $(PREFIX)/share/zorro
	@echo ""
	@echo "Take a look at $(PREFIX)/share/zorro/DOTzorrorc"
	@echo ""

.include <bsd.port.mk>
