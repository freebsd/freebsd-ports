# New ports collection makefile for:  kicad-library
# Date created:               22 May 2010
# Whom:                       Thierry Thomas <thierry@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kicad
PORTVERSION=	1.0
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION}
PKGNAMESUFFIX=	-library
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Library modules for Kicad EDA

CONFLICTS=	kicad-devel*

USE_BZIP2=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR})
	${FIND} ${DATADIR} -name CMakeLists.txt -delete	\
		-o -name makefile -delete

.include <bsd.port.mk>
