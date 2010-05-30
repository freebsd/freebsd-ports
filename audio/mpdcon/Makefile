# New ports collection makefile for:    mpdcon
# Date created:         17 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mpdcon
PORTVERSION=	1.1.99
PORTREVISION=	2
CATEGORIES=	audio gnustep
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.2%20beta%201
DISTNAME=	MPDCon-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A GNUstep MPD client

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
