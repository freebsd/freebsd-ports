# New ports collection makefile for:	zorro
# Version required:     1.1p8
# Date created:         03 Aug 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $Id: Makefile,v 1.4 1996/10/16 02:40:47 asami Exp $
#

DISTNAME=	zorro-1.1p8
PKGNAME=	zorro-1.1.8
CATEGORIES=	misc
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	shanee@rabbit.augusta.de

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zorro ${PREFIX}/bin/zorro
	${MKDIR} ${PREFIX}/share/zorro
	${INSTALL_DATA} ${WRKSRC}/DOTzorrorc ${PREFIX}/share/zorro
	@echo ""
	@echo "Take a look at ${PREFIX}/share/zorro/DOTzorrorc"
	@echo ""

.include <bsd.port.mk>
