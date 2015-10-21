# Created by: Choe, Cheng-Dae
# $FreeBSD$

PORTNAME=	jep
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	devel java python
MASTER_SITES=	SF/${PORTNAME}p/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Embedded Python

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}
MAKE_ENV=	JAVA_HOME=${JAVA_HOME}
CONFIGURE_ARGS=	--prefix=${PREFIX} --exec-prefix=${PREFIX}
USE_JAVA=	yes
JAVA_VERSION=	1.6+
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool python
# Necessary, since the configure script does the LIBS and
# LDFLAGS detection wrong
LDFLAGS=	-L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/jep.jar ${STAGEDIR}${JAVAJARDIR}/

.include <bsd.port.mk>
