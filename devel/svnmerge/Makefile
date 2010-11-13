# New ports collection makefile for:	svnmerge
# Date created:				2010-11-10
# Whom:					Tom Judge <tom@tomjudge.com>
#
# $FreeBSD$

PORTNAME=	svnmerge
PORTVERSION=	${SVN_PORTVERSION}
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	tom@tomjudge.com
COMMENT=	A Python script to managing merges in a Subversion repository

RUN_DEPENDS=	${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion

USE_BZIP2=	yes
USE_PYTHON=	2.5+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/subversion-${SVN_PORTVERSION}/contrib/client-side/svnmerge

PLIST_FILES=	bin/svnmerge
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

SVN_PORTDIR=		${PORTSDIR}/devel/subversion
SVN_PORTVERSION!=	cd ${SVN_PORTDIR} && ${MAKE} -V PORTVERSION

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${SVN_PORTDIR} && ${MAKE} DISABLE_CONFLICTS=yes WRKDIR=${WRKDIR} extract

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/svnmerge.py ${PREFIX}/bin/svnmerge
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/svnmerge.README ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
