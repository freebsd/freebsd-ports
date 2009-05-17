# New ports collection makefile for:	subversive
# Date created:			14 Feb 2007
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	subversive
PORTVERSION=	0.7.8
PORTEPOCH=	1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,%SUBDIR%,technology/subversive/0.7/builds,:S,$,:core,} \
		http://community.polarion.com/projects/subversive/download/eclipse/2.0/builds/:connectors
DISTNAME=	Subversive-incubation-${PORTVERSION}.I20090506-1500
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:core ${CONNECTORS}:connectors

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An Eclipse plug-in that provides Subversion support

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

CONNECTORS=	Subversive-connectors-2.2.0.I20090505-1500.zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native

do-install:
	@${MKDIR} ${PREFIX}/eclipse
	@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
	@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse
	@(cd ${WRKSRC}; ${FIND} -s features plugins -not -type d) | \
		${SED} -ne 's,^,eclipse/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
