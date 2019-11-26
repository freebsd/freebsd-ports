# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	netscape-java40
PORTVERSION=	1999.11.15
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	LOCAL/thierry
DISTNAME=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Classes to allow a Java applet access to JavaScript objects

LICENSE=	Netscape
LICENSE_NAME=	Netscape
LICENSE_FILE=	${WRKSRC}/License
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror auto-accept

USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes

JARFILES=	java40.jar

PLIST_FILES=	${JARFILES:S|^|%%JAVAJARDIR%%/|}

do-install:
	${INSTALL_DATA} ${JARFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
