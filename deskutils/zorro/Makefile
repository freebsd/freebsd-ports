# New ports collection makefile for:	zorro
# Version required:     1.1p8
# Date created:         03 Aug 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $Id: Makefile,v 1.9 1997/11/22 19:55:25 jseger Exp $
#

DISTNAME=	zorro-1.1p8
PKGNAME=	zorro-1.1.8
CATEGORIES=	misc tk80
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/sorted/apps/zorro-1.1p8/

MAINTAINER=	shanee@augusta.de

LIB_DEPENDS=	tk80\\.1\\.:${PORTSDIR}/x11/tk80

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zorro ${PREFIX}/bin/zorro
	${MKDIR} ${PREFIX}/share/zorro
	${INSTALL_DATA} ${WRKSRC}/DOTzorrorc ${PREFIX}/share/zorro
	@echo ""
	@echo "Take a look at ${PREFIX}/share/zorro/DOTzorrorc"
	@echo ""

.include <bsd.port.mk>
