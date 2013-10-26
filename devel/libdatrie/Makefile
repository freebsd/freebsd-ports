# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdatrie
PORTVERSION=	0.2.7.1
CATEGORIES=	devel
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/libthai/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Double-array trie implementation library

LICENSE=	LGPL21

USE_XZ=		yes
GNU_CONFIGURE=	yes
USES=		iconv pathfix
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

PORTDOCS=	README.migration

.include <bsd.port.mk>
