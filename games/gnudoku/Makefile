PORTNAME=	GNUDoku
PORTVERSION=	0.93
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://offload2.icculus.org:9090/~jcspray/GNUDoku/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free program for creating and solving Su Doku puzzles
WWW=		http://icculus.org/~jcspray/GNUDoku/

LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24

USES=		compiler:c++11-lang gmake pkgconfig
USE_CXXSTD=	c++11
MAKE_ENV=	CXXLAGS="${CXXFLAGS}"
MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}"

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS=|CXXFLAGS+=|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
