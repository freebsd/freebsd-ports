# New ports collection makefile for:	SpecTcl1.1
# Version required:	1.1
# Date created:		Fri Oct  3 18:50:53 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.5 1998/03/20 14:35:10 tg Exp $
#

DISTNAME=	SpecTcl1.1
PKGNAME=	SpecTcl-1.1
CATEGORIES=	devel tk80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/guitools/

MAINTAINER=	andreas@FreeBSD.ORG

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/specJava ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/specTcl ${PREFIX}/bin
	${MKDIR} ${PREFIX}/SpecTcl
	${INSTALL_DATA} ${WRKSRC}/changes ${PREFIX}/SpecTcl
	${INSTALL_DATA} ${WRKSRC}/license.terms ${PREFIX}/SpecTcl
	${MKDIR} ${PREFIX}/SpecTcl/lib
	${CP} -r ${WRKSRC}/SpecTcl/* ${PREFIX}/SpecTcl/lib
	${MKDIR} ${PREFIX}/SpecTcl/demo
	${CP} -r ${WRKSRC}/demo/* ${PREFIX}/SpecTcl/demo
	${MKDIR} ${PREFIX}/SpecTcl/examples
	${CP} -r ${WRKSRC}/examples/* ${PREFIX}/SpecTcl/examples

.include <bsd.port.mk>
