# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	svnmerge
PORTVERSION=	#  See ../subversion16/Makefile.inc
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	tj@FreeBSD.org
COMMENT=	A Python script to managing merges in a Subversion repository

RUN_DEPENDS=	${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion16

USE_BZIP2=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/subversion-${PORTVERSION}/contrib/client-side/svnmerge

PLIST_FILES=	bin/svnmerge
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

SVN_PORTDIR=		${PORTSDIR}/devel/subversion16
.include		"${SVN_PORTDIR}/Makefile.inc"

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
