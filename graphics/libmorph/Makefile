PORTNAME=	libmorph
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.winnicki.net/morpheus/meat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for loading (and saving) 3D modeller object files

CONFLICTS=	xmorph*

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmorph.so \
		${STAGEDIR}${PREFIX}/lib/morph/loaders/*.so

.include <bsd.port.mk>
