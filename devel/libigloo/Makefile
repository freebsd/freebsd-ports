PORTNAME=	libigloo
DISTVERSION=	0.9.5
CATEGORIES=	devel
MASTER_SITES=	https://ftp.osuosl.org/pub/xiph/releases/igloo/

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Generic C framework developed and used by the Icecast project
WWW=		https://gitlab.xiph.org/xiph/icecast-libigloo

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librhash.so:security/rhash

USES=		pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

TEST_TARGET=	check

CONFIGURE_ARGS=	--disable-static

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libigloo.la

.include <bsd.port.mk>
