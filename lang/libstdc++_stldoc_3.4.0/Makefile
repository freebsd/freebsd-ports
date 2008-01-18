# New ports collection makefile for:	libstdc++_stldoc
# Date created:		18th January 2008
# Whom:			Bruce M. Simpson
#
# $FreeBSD$
#
# Note: Specific versions of this documentation exist for each version
# of the libstdc++ library, note versioning convention below.
#

PORTNAME=	libstdc++_stldoc_3.4.0
PORTVERSION=	20040609
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR= \
		libstdc++/doxygen
DISTNAME=	libstdc++-html-USERS-3.4.0

MAINTAINER=	bms@FreeBSD.org
COMMENT=	GNU libstdc++ API documentation

USE_BZIP2=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PORTDOCS=	*

do-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/html_user/* ${DOCSDIR}

.include <bsd.port.mk>
