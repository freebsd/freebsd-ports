# New ports collection makefile for:	pgaccess
# Version required:	0.51
# Date created:		Sat Oct  4 20:03:46 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.12 1998/06/13 13:25:02 andreas Exp $
#

DISTNAME=	pgaccess-0.91
CATEGORIES=	databases
MASTER_SITES=	http://www.flex.ro/pgaccess/

MAINTAINER=	andreas@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/pgsql/bin/postmaster:${PORTSDIR}/databases/postgresql

WRKSRC=		${WRKDIR}/pgaccess
NO_BUILD=		yes
FETCH_BEFORE_ARGS=	-b

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgaccess.tcl ${PREFIX}/bin/pgaccess

.include <bsd.port.mk>
