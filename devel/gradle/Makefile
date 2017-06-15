# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	gradle
PORTVERSION=	3.2.1
CATEGORIES=	devel java
MASTER_SITES=	https://services.gradle.org/distributions/ \
		http://services.gradle.org/distributions/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Project automation tool

LICENSE=	APACHE20

# Gradle depends on native-platform which has a native component that
# requires libstdc++.so.6, because it was compiled with g++.
# See https://github.com/adammurdoch/native-platform/issues/8
LIB_DEPENDS=	libstdc++.so.6:misc/compat9x

NO_ARCH=	yes
USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/-bin$$//}
SUB_LIST=	PORTVERSION=${PORTVERSION} \
		JAVA=${JAVA}
SUB_FILES=	gradle

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gradle ${STAGEDIR}${PREFIX}/bin/gradle
	(cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
