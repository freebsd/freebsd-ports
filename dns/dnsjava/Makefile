PORTNAME=	dnsjava
DISTVERSION=	2.1.9
PORTREVISION=	3
CATEGORIES=	dns java
MASTER_SITES=	https://github.com/dnsjava/${PORTNAME}/releases/download/v${DISTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of DNS in Java
WWW=		https://github.com/dnsjava/dnsjava/

LICENSE=	BSD2CLAUSE

USES=		java:build

NO_ARCH=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar

do-build:
# dummy, just copies the distfile during install

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${DISTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
