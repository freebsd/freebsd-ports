# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zoneinfo
DISTVERSION=	2020a
CATEGORIES=	java misc
MASTER_SITES=	LOCAL/glewis/javazi
PKGNAMEPREFIX=	java-
DISTNAME=	javazi-${DISTVERSION}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Updated Java timezone definitions

LICENSE=	PD

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

JAVASHAREDIR=	${PREFIX}/share/java

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/zi
	(cd ${WRKSRC}/zi && ${COPYTREE_SHARE} . ${STAGEDIR}${JAVASHAREDIR}/zi)

.include <bsd.port.mk>
