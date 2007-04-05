# New ports collection makefile for:	aolserver-nszlib
# Date created:		12 Oct 2006
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aolserver-nszlib
PORTVERSION=	1.1
CATEGORIES=	archivers www
MASTER_SITES=	ftp://ftp.crystalballinc.com/pub/vlad/
MASTER_SITE_SUBDIR=	aolserver
DISTNAME=	nszlib
DIST_SUBDIR=	aolserver

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Zlib library interface for AOLserver

AOLSERVERBASE?=	${PREFIX}/aolserver

BUILD_DEPENDS+=	${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${BUILD_DEPENDS}
PLIST_SUB+=	AOLSERVERBASE=${AOLSERVERBASE:S/${PREFIX}\///}

USE_GMAKE=	yes

MAKE_ARGS=	AOLSERVER=${AOLSERVERBASE}

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog README example.tcl
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
