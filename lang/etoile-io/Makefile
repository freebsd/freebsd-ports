# New ports collection makefile for:    etoile-io
# Date created:         19 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	io
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~%%SUBDIR%%/distfiles/
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	etoile-
DISTNAME=	Etoile-${SNAPSHOT}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project Io Language

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

SNAPSHOT=	20061221
WRKSRC=	${WRKDIR}/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Languages/Io
HEADER_DIR=	Local/Library/Headers/Io
PLIST_FILES=	Local/Tools/ioobjc

.include <bsd.port.mk>
