# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	scourge-data
PORTVERSION=	0.21.1
CATEGORIES=	games
MASTER_SITES=	SF/scourge/scourge/${PORTVERSION}
DISTNAME=	scourge-${PORTVERSION}.data
DIST_SUBDIR=	scourge

MAINTAINER=	games@FreeBSD.org
COMMENT=	S.C.O.U.R.G.E data files

NO_BUILD=	yes
NO_ARCH=	*

WRKSRC=		${WRKDIR}/scourge_data
DATADIR=	${PREFIX}/share/scourge
PORTDATA=	*

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
