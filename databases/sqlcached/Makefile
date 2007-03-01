# New ports collection makefile for:  sqlcached
# Date created:        3 January 2007
# Whom:                ivoras
#
# $FreeBSD$
#

PORTNAME=	sqlcached
PORTVERSION=	r4
CATEGORIES=	databases net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ivoras@FreeBSD.org
COMMENT=	A cache daemon using SQL for data manipulation

LIB_DEPENDS=	sqlite.2:${PORTSDIR}/databases/sqlite2

WRKSRC=		${WRKDIR}/sqlcached
MAN1=			sqlcached.1

PORTDOCS=	sqlcached.html sqlcached.txt

PLIST_FILES=	bin/sqlcached etc/rc.d/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sqlcached ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/sqlcached.1 ${PREFIX}/man/man1/
	${CP}	${WRKSRC}/FreeBSD/${PORTNAME}	${LOCALBASE}/etc/rc.d/

.if !defined(NOPORTDOCS)
	    ${MKDIR} ${DOCSDIR}
	    ${INSTALL_MAN} ${WRKSRC}/doc/sqlcached.html ${DOCSDIR}/
	    ${INSTALL_MAN} ${WRKSRC}/doc/sqlcached.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
