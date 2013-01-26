# $FreeBSD$

PORTNAME=	swank-clojure
PORTVERSION=	1.2.1
CATEGORIES=	devel lisp java
MASTER_SITES=	http://download.github.com/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=olgeni
DISTNAME=	technomancy-${PORTNAME}-${PORTVERSION}-0-g0af258a

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Swank/SLIME support for Clojure

USE_JAVA=	yes
JAVA_VERSION=	1.6+

WRKSRC=		${WRKDIR}/technomancy-swank-clojure-0af258a

PLIST_FILES=	%%JAVAJARDIR%%/swank-clojure-1.2.1.jar

do-build:
	@cd ${WRKSRC} && ${JAR} cf ${PORTNAME}-${PORTVERSION}.jar -C src swank

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}

.include <bsd.port.mk>
