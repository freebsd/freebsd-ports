# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdatrie
PORTVERSION=	0.2.12
CATEGORIES=	devel
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Double-array trie implementation library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv libtool localbase:ldflags pathfix tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

LDFLAGS+=	${ICONV_LIB}

PORTDOCS=	README.migration
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
