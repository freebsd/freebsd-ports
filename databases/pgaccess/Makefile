# New ports collection makefile for:	pgaccess
# Version required:	0.96
# Date created:		Sat Oct  4 20:03:46 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

DISTNAME=	pgaccess-0.98
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.flex.ro/pub/pgaccess/

MAINTAINER=	andreas@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/pgsql/bin/postmaster:${PORTSDIR}/databases/postgresql\
		wish8.0:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/pgaccess
NO_BUILD=		yes
FETCH_BEFORE_ARGS=	-b

do-install:
	@${MKDIR} ${PREFIX}/share/pgaccess
	@cd ${WRKSRC} && /bin/pax -rwp p copyright.html main.tcl lib images ${PREFIX}/share/pgaccess
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && /bin/pax -rwp p README demo doc ${PREFIX}/share/pgaccess
.endif
	@${SED} -e 's:!!LOCALBASE!!:${LOCALBASE}:' ${WRKSRC}/pgaccess |\
	 ${SED} -e 's:!!PREFIX!!:${PREFIX}:' > ${PREFIX}/bin/pgaccess
	@${CHMOD} 555 ${PREFIX}/bin/pgaccess
.include <bsd.port.mk>
