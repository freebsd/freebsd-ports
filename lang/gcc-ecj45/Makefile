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

DEPRECATED=	Long time unsupported upstream, use java/eclipse-ecj instead
EXPIRATION_DATE=	2023-03-06

NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	share/java/${DISTNAME}

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/share/java

.include <bsd.port.mk>
