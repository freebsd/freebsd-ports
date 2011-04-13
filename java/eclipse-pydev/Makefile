# New ports collection makefile for:	eclipse-pydev
# Date created:		2007-11-16
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pydev
PORTVERSION=	2.0.0.2011040403
PORTREVISION=	0
CATEGORIES=	java devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Pydev%202.0
PKGNAMEPREFIX=	eclipse-
DISTNAME=	org.python.pydev.feature-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Eclipse plugin for Python and Jython development

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

JAVA_VERSION=	1.5+

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_JAVA=	yes
USE_ZIP=	yes

do-install:
.for d in features plugins
	cd ${WRKDIR}/${d} && ${COPYTREE_SHARE} . ${PREFIX}/lib/eclipse/${d}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
