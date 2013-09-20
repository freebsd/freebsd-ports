# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	ditrack
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tracking system based on Subversion repository

RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion

WRKSRC=		${WRKDIR}/DITrack-${PORTVERSION}
NO_BUILD=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	DITrack

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/upgrade-0.7-db.py ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
