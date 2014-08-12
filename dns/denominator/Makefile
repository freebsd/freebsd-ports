# Created by: Steve Wills <swills@freebsd.org>
# $FreeBSD$

PORTNAME=	denominator
PORTVERSION=	4.3.3
CATEGORIES=	dns java
MASTER_SITES=	http://dl.bintray.com/content/netflixoss/${PORTNAME}/${PORTNAME}-cli/release/${PORTVERSION}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Portably control DNS clouds

USE_JAVA=	yes
NO_BUILD=	yes
STRIP=		# none
PLIST_FILES=	bin/${PORTNAME}

do-extract:
	@${MKDIR} ${WRKDIR}/${DISTNAME}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
