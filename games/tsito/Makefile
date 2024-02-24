PORTNAME=	tsito
PORTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/xiangqi-engine/xiangqi-engine/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese chess (Xiangqi) program
WWW=		https://xiangqi-engine.sourceforge.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
LIBS+=		-lcompat

.include <bsd.port.mk>
