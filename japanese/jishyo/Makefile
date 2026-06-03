PORTNAME=	jishyo
PORTVERSION=	0.1
PORTREVISION=	14
CATEGORIES=	japanese gnustep
MASTER_SITES=	http://www.eskimo.com/~pburns/Dictionaries/files/
DISTNAME=	Jishyo-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English to Japanese dictionary for GNUstep
WWW=		https://www.eskimo.com/~pburns/Dictionaries/

LICENSE=	GPLv2+

PORTSCOUT=	skipv:0.2

USES=		gnustep
USE_GNUSTEP=	back base build gui

CPPFLAGS+=	-fcommon

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Jishyo.app/Jishyo

.include <bsd.port.mk>
