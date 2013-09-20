# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	subversive
PORTVERSION=	1.0.0
PORTEPOCH=	1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,%SUBDIR%,technology/subversive/1.0/builds,:S,$,:core,} \
		http://community.polarion.com/projects/subversive/download/eclipse/3.0/builds/:connectors
DISTNAME=	Subversive-${PORTVERSION}.I20121109-1700
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:core ${CONNECTORS}:connectors

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An Eclipse plug-in that provides Subversion support

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

LICENSE=	EPL

CONNECTORS=	Subversive-connectors-3.0.0.I20121109-1700.zip

NO_WRKSUBDIR=	yes
USE_ZIP=	yes

NO_STAGE=	yes
.include "${.CURDIR}/../../java/eclipse/Makefile.plugins"

.include <bsd.port.mk>
