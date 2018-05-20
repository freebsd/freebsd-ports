# Created by: Gerald Pfeifer <gerald@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gcc-ecj
PORTVERSION=	4.5
CATEGORIES=	lang java
MASTER_SITES=	SOURCEWARE/java/
DISTNAME=	ecj-${PORTVERSION}.jar
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Eclipse Java Compiler used to build GCC Java

LICENSE=	EPL

NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	share/java/${DISTNAME}

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/share/java

.include <bsd.port.mk>
