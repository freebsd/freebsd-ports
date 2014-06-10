# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	subversive
PORTVERSION=	1.1.2
PORTEPOCH=	1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,%SUBDIR%,technology/subversive/1.1/builds,:S,$,:core,} \
		http://community.polarion.com/projects/subversive/download/eclipse/3.0/builds/:connectors
DISTNAME=	Subversive-${PORTVERSION}.I20131116-1700
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:core ${CONNECTORS}:connectors

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Eclipse plug-in that provides Subversion support

LICENSE=	EPL

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

CONNECTORS=	Subversive-connectors-allplatforms-3.0.5.I20140122-1700.zip

USES=		zip
NO_WRKSUBDIR=	yes

.include "${.CURDIR}/../../java/eclipse/Makefile.plugins"

.include <bsd.port.mk>
