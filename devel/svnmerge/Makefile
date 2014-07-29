# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	svnmerge
PORTVERSION=	#  See ../subversion16/Makefile.inc
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER= ports@FreeBSD.org
COMMENT=	Python script to managing merges in a Subversion repository

BROKEN=		Tries to fetch during extract phase
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-08-22

RUN_DEPENDS=	${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion16

USES=	tar:bzip2
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
