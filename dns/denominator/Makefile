PORTNAME=	denominator
DISTVERSION=	4.7.1
PORTREVISION=	3
CATEGORIES=	dns java
MASTER_SITES=	https://bintray.com/artifact/download/netflixoss/maven/com/netflix/${PORTNAME}/${PORTNAME}-cli/${PORTVERSION}/
DISTNAME=	${PORTNAME}-cli-${PORTVERSION}-fat.jar
EXTRACT_SUFX=

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Portably control DNS clouds
WWW=		https://github.com/Netflix/denominator

DEPRECATED=	Project has been archived use dns/py-dns-lexicon
EXPIRATION_DATE=	2026-09-30

USES=		java

STRIP=		# none
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-extract:
	@${MKDIR} ${WRKDIR}/${DISTNAME}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
