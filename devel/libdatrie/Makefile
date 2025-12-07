PORTNAME=	libdatrie
DISTVERSION=	0.2.14
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/tlwg/libdatrie/releases/download/v${DISTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Double-array trie implementation library
WWW=		https://linux.thai.net/projects/datrie/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv:wchar_t libtool localbase:ldflags pathfix tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

LDFLAGS+=	${ICONV_LIB}

.include <bsd.port.mk>
