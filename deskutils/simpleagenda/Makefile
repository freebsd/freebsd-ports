PORTNAME=	simpleagenda
PORTVERSION=	0.46
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils gnustep
DISTNAME=	SimpleAgenda-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple calendar and agenda application
WWW=		https://mediawiki.gnustep.org/index.php/SimpleAgenda.app

LICENSE=	GPLv2

LIB_DEPENDS=	libical.so:devel/libical \
		libuuid.so:misc/libuuid

USES=		gnustep localbase
GNU_CONFIGURE=	yes
USE_GNUSTEP=	back base build gui
USE_GITHUB=	yes
GH_ACCOUNT=	poroussel
TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} -e 's|SimpleAgenda|&.m|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '1{x; s|^|#import <AppKit/AppKitDefines.h>|; \
		G;}' ${WRKSRC}/SoundBackend.m

.include <bsd.port.mk>
