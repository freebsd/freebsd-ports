# New ports collection makefile for:	ditrack
# Date created:		2007-02-04
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	ditrack
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.ditrack.org/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gslin@gslin.org
COMMENT=	A tracking system based on Subversion repository

RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion

NO_BUILD=	yes
USE_PYTHON=	yes

.include <bsd.port.pre.mk>

do-install:
	${CP} -R ${WRKSRC}/DITrack ${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/dt* ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/index.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
