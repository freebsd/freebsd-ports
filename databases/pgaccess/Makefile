# New ports collection makefile for:	pgaccess
# Version required:	0.51
# Date created:		Sat Oct  4 20:03:46 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.11 1998/04/21 21:30:21 andreas Exp $
#

DISTNAME=	pgaccess-0.88
CATEGORIES=	databases
MASTER_SITES=	http://www.flex.ro/pgaccess/

MAINTAINER=	andreas@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/pgsql/bin/postmaster:${PORTSDIR}/databases/postgresql

NO_BUILD=		yes
NO_WRKSUBDIR=		yes
FETCH_BEFORE_ARGS=	-b

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgaccess.tcl ${PREFIX}/bin/pgaccess

.include <bsd.port.mk>
