PORTNAME=	libtmcg
DISTVERSION=	1.3.18
CATEGORIES=	games security
MASTER_SITES=	SAVANNAH
DISTNAME=	libTMCG-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for creating secure and fair online card games
WWW=		https://www.nongnu.org/libtmcg/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libgmp.so:math/gmp

USES=		gmake libtool localbase:ldflags
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

INFO=		libTMCG

.include <bsd.port.mk>
