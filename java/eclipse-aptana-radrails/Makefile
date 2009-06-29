# New ports collection makefile for:	eclipse-aptana-radrails
# Date created:				22 June 2009
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aptana
PORTVERSION=	1.2.1.23268
CATEGORIES=	java devel
MASTER_SITES=	http://update1.aptana.org/rails/${PORTVERSION}/ \
		http://update2.aptana.org/rails/${PORTVERSION}/
PKGNAMEPREFIX=	eclipse-
PKGNAMESUFFIX=	-radrails
DISTNAME=	org.radrails.rails_feature-${PORTVERSION}-278787EUNvWohWG-fz0019H9P9Y9

MAINTAINER=	avl@FreeBSD.org
COMMENT=	IDE for Ruby and the Ruby on Rails framework (Eclipse plugin)

RUN_DEPENDS=	${LOCALBASE}/eclipse/features/com.aptana.ide.feature_1.2.7.024747.jar:${PORTSDIR}/java/eclipse-aptana

JAVA_VERSION=	1.5+

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_JAVA=	yes
USE_ZIP=	yes

do-install:
	@(cd ${WRKDIR} && ${CP} -R features ${PREFIX}/eclipse && ${CP} -R plugins ${PREFIX}/eclipse;)

.include <bsd.port.mk>
