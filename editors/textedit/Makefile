# New ports collection makefile for:    textedit.app
# Date created:         28 Aug 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	textedit
PORTVERSION=	4.0
PORTREVISION=	3
CATEGORIES=	editors gnustep
MASTER_SITES=	http://git.savannah.gnu.org/cgit/backbone.git/snapshot/
DISTNAME=	backbone-6343263e17c5cd771770dabc2559ac07ffedcf29

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Basic text editor for GNUstep

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

USE_GNUSTEP_MAKE_DIRS=	System/Applications/TextEdit
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

.include <bsd.port.mk>
