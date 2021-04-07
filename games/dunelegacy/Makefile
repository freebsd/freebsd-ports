PORTNAME=	dunelegacy
PORTVERSION=	0.96.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Open source clone of Dune II

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lib pkgconfig sdl tar:bzip2
GNU_CONFIGURE=	yes
USE_SDL=	sdl2 mixer2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
