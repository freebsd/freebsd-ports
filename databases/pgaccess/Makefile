# New ports collection makefile for:	pgaccess
# Date created:		Sat Oct  4 20:03:46 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	pgaccess
PORTVERSION=	0.98.7
CATEGORIES=	databases
MASTER_SITES=	http://www.flex.ro/pgaccess/download/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
LIB_DEPENDS=	pgtcl.2:${PORTSDIR}/databases/postgresql7

WRKSRC=		${WRKDIR}/pgaccess
NO_BUILD=		yes

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
