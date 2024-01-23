PORTNAME=	libdatrie
PORTVERSION=	0.2.13
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Double-array trie implementation library
WWW=		https://linux.thai.net/projects/datrie/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv:wchar_t libtool localbase:ldflags pathfix tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip

LDFLAGS+=	${ICONV_LIB}

.include <bsd.port.mk>
