# $FreeBSD$

PORTNAME=	libmatthew
DISTVERSION=	0.8.1
CATEGORIES=	devel java
MASTER_SITES=	http://www.matthew.ath.cx/projects/java/
DISTNAME=	${PORTNAME}-java-${DISTVERSION}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Selection of Java libraries by Matthew Johnson

LICENSE=	EXPAT
LICENSE_NAME=	Expat License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake localbase:ldconfig
USE_JAVA=	yes
USE_LDCONFIG=	yes

MAKE_ENV=	JAVA_HOME='${JAVA_HOME}' \
		LDSHAREFLAGS='-fpic -shared'

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/jni/*-java.so

.include <bsd.port.mk>
