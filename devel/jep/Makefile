# New ports collection makefile for:	jep
# Date created:		2005-03-04
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	jep
PORTVERSION=	1.1
CATEGORIES=	devel java python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jepp

MAINTAINER=	whitekid@gmail.com
COMMENT=	Java Embedded Python

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}
CONFIGURE_ARGS=	--prefix=${PREFIX} --exec-prefix=${PREFIX}
USE_JAVA=	yes
JAVA_VERSION=	1.2+
USE_PYTHON=	yes
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes

MAN1=	jep.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/jep.jar ${JAVAJARDIR}

.include <bsd.port.mk>
