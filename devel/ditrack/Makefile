# New ports collection makefile for:	ditrack
# Date created:		2007-02-04
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	ditrack
PORTVERSION=	0.8
CATEGORIES=	devel
MASTER_SITES=	http://www.ditrack.org/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tracking system based on Subversion repository

RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion

NO_BUILD=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	DITrack
WRKSRC=		${WRKDIR}/DITrack-${PORTVERSION}

.include <bsd.port.pre.mk>

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/upgrade-0.7-db.py ${DATADIR}
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/index.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
