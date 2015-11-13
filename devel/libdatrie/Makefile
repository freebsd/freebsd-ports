# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdatrie
PORTVERSION=	0.2.10
CATEGORIES=	devel
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Double-array trie implementation library

LICENSE=	LGPL21

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		iconv libtool pathfix tar:xz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

PORTDOCS=	README.migration
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
