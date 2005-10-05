# New ports collection makefile for:	wfut
# Date Created:				04 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wfut
PORTVERSION=	38
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	oliver

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Software updater tool for WorldForge applications

USE_BZIP2=	yes
USE_JAVA=	1.5+
NO_BUILD=	yes
USE_X_PREFIX=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/WFUT.jar ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
