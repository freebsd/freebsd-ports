PORTNAME=	libthai
DISTVERSION=	0.1.30
CATEGORIES=	devel
MASTER_SITES=	https://github.com/tlwg/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://linux.thai.net/pub/thailinux/software/libthai/

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Thai language support library
WWW=		https://linux.thai.net/projects/libthai/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdatrie.so:devel/libdatrie

USES=		libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

TEST_TARGET=	check

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-static \
		--disable-doxygen-doc

.include <bsd.port.mk>
