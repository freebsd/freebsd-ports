# New ports collection makefile for:	SearchAndRescue-data
# Date created:			10 June 2010
# Whom:				Jesse Smith <jessefrgsmith@yahoo.ca>
#
# $FreeBSD$
#

PORTNAME=	SearchAndRescue
PORTVERSION=	1.0.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME:L}/Data_Files/
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	The data files for SearchAndRescue flight simulator

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/share/${PORTNAME:L}

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR}

.include <bsd.port.mk>
