# New ports collection makefile for:	pgaccess
# Version required:	0.96
# Date created:		Sat Oct  4 20:03:46 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

DISTNAME=	pgaccess-0.96
CATEGORIES=	databases
MASTER_SITES=	http://www.flex.ro/pgaccess/

MAINTAINER=	andreas@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/pgsql/bin/postmaster:${PORTSDIR}/databases/postgresql\
		wish8.0:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/pgaccess
NO_BUILD=		yes
FETCH_BEFORE_ARGS=	-b

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgaccess.tcl ${PREFIX}/bin/pgaccess

.include <bsd.port.mk>
