PORTNAME=	bucklespring
PORTVERSION=	2.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Nostalgia bucklespring keyboard sound
WWW=		https://github.com/barak/bucklespring

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		autoreconf gmake openal pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	barak
USE_XORG=	x11 xtst
GNU_CONFIGURE=	yes

MAKE_ENV+=	PATH_AUDIO=${DATADIR}/wav

LDFLAGS_i386=	-Wl,-znotext

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
