# New ports collection makefile for:	aolserver-nsmysql
# Date created:		12 Oct 2006
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aolserver-nsmysql
PORTVERSION=	1.0
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aolserver
DISTFILES=	nsmysql_v1.tar.gz
DIST_SUBDIR=	aolserver

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Internal MySQL database driver for AOLserver

WRKSRC=		${WRKDIR}/nsmysql_v1

AOLSERVERBASE?=	${PREFIX}/aolserver
BUILD_DEPENDS+=	${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${BUILD_DEPENDS}
PLIST_SUB+=	AOLSERVERBASE=${AOLSERVERBASE:S/${PREFIX}\///}

USE_MYSQL=	yes
USE_GMAKE=	yes

MAKE_ARGS=	AOLSERVER=${AOLSERVERBASE}

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog README INSTALL
.endif

post-patch:
	@ ${REINPLACE_CMD} -e 's|OBJS|MODOBJS|' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
