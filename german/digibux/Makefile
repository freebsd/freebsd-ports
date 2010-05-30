# New ports collection makefile for:    digibux
# Date created:         16 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	digibux
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	german gnustep
MASTER_SITES=	http://gnu.ethz.ch/repository/digibux/
DISTNAME=	digibux_${PORTVERSION}+CVS20060118.orig

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Reader for editions of Digitale Bibliothek

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/digibux-${PORTVERSION}+CVS20060118

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
