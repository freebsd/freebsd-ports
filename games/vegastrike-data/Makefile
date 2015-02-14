# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	vegastrike
PORTVERSION=	0.5.1.r1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.5.1/
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vega Strike data files

USES=		tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes

MANUAL_PACKAGE_BUILD=	huge

PORTDATA=	* .vegastrike
PLIST_DIRS=	%%DATADIR%%/movies

do-extract:
	${MKDIR} ${WRKDIR}
	# Will extract on install phase

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} -C ${STAGEDIR}${DATADIR} -xf ${_DISTDIR}/${DISTFILES} \
	    --exclude Makefile.am --no-same-owner --strip-components=1

.include <bsd.port.mk>
