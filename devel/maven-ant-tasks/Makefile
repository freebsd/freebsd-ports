# New ports collection Makefile for:	maven-ant-tasks
# Date created:		June 2010
# Whom:			Chris Rees <utisoft@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	maven-ant-tasks
PORTVERSION=	2.1.1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	maven/binaries
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	utisoft@gmail.com
COMMENT=	Allows Maven's artifact handling to be used from within an Ant build

RUN_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant

LICENSE=	ASL

USE_JAVA=	1.5+

NO_BUILD=	yes

PLIST_FILES=	%%JAVASHAREDIR%%/apache-ant/lib/${DISTNAME}${EXTRACT_SUFX}

do-install:
	@${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${JAVASHAREDIR}/apache-ant/lib/

.include <bsd.port.mk>
