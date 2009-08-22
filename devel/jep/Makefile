# New ports collection makefile for:	jep
# Date created:		2005-03-04
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	jep
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	devel java python
MASTER_SITES=	SF/${PORTNAME}p/${PORTNAME}/${PORTVERSION}

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Java Embedded Python

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}
MAKE_ENV=	JAVA_HOME=${JAVA_HOME}
CONFIGURE_ARGS=	--prefix=${PREFIX} --exec-prefix=${PREFIX}
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_PYTHON=	2.2+
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=	jep.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/jep.jar ${JAVAJARDIR}/

.include <bsd.port.mk>
