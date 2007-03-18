# New ports collection makefile for:	hattrickorganizer
# Date Created:		17 Jan 2005
# Whom:			Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	hattrickorganizer
PORTVERSION=	1.395
PORTEPOCH=	1
CATEGORIES=	games java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ho1
DISTNAME=	HO_${PORTVERSION:S/.//g}

MAINTAINER=	lars.engels@0x20.net
COMMENT=	A management tool for Hattrick.org written in Java

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USE_ZIP=	  yes
NO_BUILD=	  yes
USE_JAVA=	  yes
JAVA_VERSION=	  1.4+

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${REINPLACE_CMD} -e 's|HODIR=`pwd`|HODIR=${DATADIR}|'  ${WRKSRC}/HO.sh
	${REINPLACE_CMD} 's|^HOHOME=.*|HOHOME=~/\.hattrickorganizer|' ${WRKSRC}/HO.sh
	${INSTALL_SCRIPT} ${WRKSRC}/HO.sh ${PREFIX}/bin/hattrickorganizer

.include <bsd.port.mk>
