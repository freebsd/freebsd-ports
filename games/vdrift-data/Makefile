# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	20100630
CATEGORIES=	games
MASTER_SITES=	SF/vdrift/vdrift/vdrift-${DATA_VERSION}
PKGNAMEPREFIX=	vdrift-
DISTNAME=	${PKGNAMEPREFIX}${DATA_VERSION}
DIST_SUBDIR=	vdrift

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Vdrift driving simulation data files

LICENSE=	GPLv2

USES=		tar:bzip2
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/vdrift
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${DATA_VERSION}

DATA_VERSION=	2010-06-30

PORTDATA=	*
PLIST_DIRS=	%%DATADIR%%/carparts/engine \
		%%DATADIR%%/carparts/exhaust \
		%%DATADIR%%/carparts/other \
		%%DATADIR%%/carparts/suspension \
		%%DATADIR%%/carparts/transmission \
		%%DATADIR%%/carparts/turbo \
		%%DATADIR%%/lists/fontinfo \
		%%DATADIR%%/settings/replays \
		%%DATADIR%%/settings/screenshots

post-extract:
	@cd ${WRKSRC}/data && \
		${FIND} * -name "SConscript*" -delete
.for DIRE in music
	@${RMDIR} ${WRKSRC}/data/${DIRE}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
