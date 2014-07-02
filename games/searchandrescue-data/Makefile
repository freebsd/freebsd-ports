# Created by: Jesse Smith <jessefrgsmith@yahoo.ca>
# $FreeBSD$

PORTNAME=	SearchAndRescue
PORTVERSION=	1.3.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME:tl}/Data_Files/
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The data files for SearchAndRescue flight simulator

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/share/${PORTNAME:tl}

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR}

.include <bsd.port.mk>
