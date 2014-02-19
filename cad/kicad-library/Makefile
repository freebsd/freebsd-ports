# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
PORTVERSION=	1.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_LOCAL}	\
		SF/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION}
MASTER_SITE_SUBDIR=	thierry/${PORTNAME}
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
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	${FIND} ${STAGEDIR}${DATADIR} -name CMakeLists.txt -delete	\
		-o -name makefile -delete

.include <bsd.port.mk>
