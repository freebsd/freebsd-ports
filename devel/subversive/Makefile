# New ports collection makefile for:	subversive
# Date created:			14 Feb 2007
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	subversive
DISTVERSION=	1.1.1
CATEGORIES=	devel java
MASTER_SITES=	http://www.polarion.org/projects/subversive/download/1.1/builds/
DISTNAME=	Subversive_${DISTVERSION}-LocalUpdateSite

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An Eclipse plug-in that provides Subversion support

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native

do-install:
	@${MKDIR} ${PREFIX}/eclipse
	@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
	@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse
	@(cd ${WRKSRC}; ${FIND} -s features plugins -not -type d) | \
		${SED} -ne 's,^,eclipse/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
