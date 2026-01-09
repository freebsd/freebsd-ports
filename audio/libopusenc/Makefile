PORTNAME=	libopusenc
PORTVERSION=	0.3
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/opus/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	High-level API for encoding .opus files
WWW=		https://opus-codec.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libopus.so:audio/opus

USES=		libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-mode	# avoid autotools cascade
CONFIGURE_ARGS+=--disable-doc			# requires doxygen
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
