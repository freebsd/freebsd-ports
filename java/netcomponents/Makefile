PORTNAME=	netcomponents
PORTVERSION=	1.3.8
PORTREVISION=	3
CATEGORIES=	java net
MASTER_SITES=	http://www.savarese.org/oro/downloads/
DISTNAME=	NetComponents-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java library with common network protocol implementations
WWW=		https://www.savarese.org/oro/index.html

# Converted from RESTRICTED
LICENSE=	NetComponents
LICENSE_NAME=	NetComponents
LICENSE_TEXT=	May not redistribute except as part of a new software product
LICENSE_PERMS=	auto-accept

DEPRECATED=	Last upstream release was in 2000 and upstream unmaintained consider using net/apache-commons-net
EXPIRATION_DATE=	2024-03-31

USES=		zip
USE_JAVA=	yes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/NetComponents-1.3.8a

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}

JARFILE=	NetComponents.jar

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		must be manually fetched from ${MASTER_SITES}.  Download\
		${DISTFILES}, place it in ${DISTDIR} and restart this build
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.post.mk>
