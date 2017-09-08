# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	jishyo
PORTVERSION=	0.1
PORTREVISION=	7
CATEGORIES=	japanese gnustep
MASTER_SITES=	http://www.eskimo.com/~pburns/Dictionaries/files/
DISTNAME=	Jishyo-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English to Japanese dictionary for GNUstep

LICENSE=	GPLv2+

PORTSCOUT=	skipv:0.2

USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Jishyo.app/Jishyo

.include <bsd.port.mk>
