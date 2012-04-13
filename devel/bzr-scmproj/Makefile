# Ports collection makefile for:	bzr-scmproj
# Date created:				2012-04-13
# Whom:					Carlo Strub <cs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bzr-scmproj
PORTVERSION=	0.6.2
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/101701273/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Organise and manage a collection of bzr branches

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
