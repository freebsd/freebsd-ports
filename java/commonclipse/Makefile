# Created by: Sutra Zhou <zhoushuqun@gmail.com>
# $FreeBSD$

PORTNAME=	commonclipse
PORTVERSION=	1.3.0
PORTREVISION=	4
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}%20for%20eclipse%203.1M6%20and%20up
DISTNAME=	net.sf.commonclipse_${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	Commonclipse is an eclipse plugin for jakarta commons-lang users

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
PLIST_SUB=	DISTNAME=${DISTNAME}

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/eclipse
	@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
	@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse

.include <bsd.port.mk>
