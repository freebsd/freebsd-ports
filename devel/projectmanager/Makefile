# New ports collection makefile for:	projectmanager
# Date created:         28 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	projectmanager
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	devel gnustep
MASTER_SITES=	http://download.gna.org/pmanager/0.2/
DISTNAME=	ProjectManager-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Simple, but very usable development environment

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	WizardKit:${WIZARDKIT_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	HighlighterKit:${HIGHLIGHTERKIT_PORT}

MAKE_FLAGS+=	debug=no

WIZARDKIT_PORT?=		devel/wizardkit
HIGHLIGHTERKIT_PORT?=		devel/highlighterkit

.include <bsd.port.mk>
