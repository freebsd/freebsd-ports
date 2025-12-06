PORTNAME=	libthai
DISTVERSION=	0.1.29
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/tlwg/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://linux.thai.net/pub/thailinux/software/libthai/

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Thai language support library
WWW=		https://linux.thai.net/projects/libthai/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdatrie.so:devel/libdatrie

USES=		gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENABLE=	doxygen-doc

.include <bsd.port.mk>
