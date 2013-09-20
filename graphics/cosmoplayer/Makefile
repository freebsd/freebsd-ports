# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	cosmoplayer
PORTVERSION=	2.1.1
PORTREVISION=	2
CATEGORIES=	graphics
#MASTER_SITES=	http://opendx.npaci.edu/libs/
MASTER_SITES=	http://distfiles.macports.org/${PORTNAME}/	\
		http://lil.fr.distfiles.macports.org/${PORTNAME}/	\
		http://ftp.leg.uct.ac.za/pub/packages/macports/distfiles/${PORTNAME}/
DISTNAME=	${PORTNAME}-jar

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Java classes to support VRML

RUN_DEPENDS=	${JAVALIBDIR}/java40.jar:${PORTSDIR}/devel/netscape-java40

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

JARFILES=	npcosmop211.jar LICENSE.npcosmop211.txt

PLIST_FILES=	${JARFILES:S|^|%%JAVAJARDIR%%/|}

NO_STAGE=	yes
post-extract:
	${MV} ${WRKDIR}/comsoplayer-jar ${WRKSRC}
	${MV} ${WRKSRC}/License ${WRKSRC}/LICENSE.npcosmop211.txt

do-install:
	${INSTALL_DATA} ${JARFILES:S|^|${WRKSRC}/|} ${JAVAJARDIR}

.include <bsd.port.mk>
