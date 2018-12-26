# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdeflate
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	archivers

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast, whole-buffer DEFLATE-based compression library

LICENSE=	MIT

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	ebiggers
USE_LDCONFIG=	yes

MAKE_ARGS=	V=1

PLIST_FILES=	bin/libdeflate-gunzip bin/libdeflate-gzip \
		include/libdeflate.h \
		lib/libdeflate.a lib/libdeflate.so lib/libdeflate.so.0
PORTDOCS=	NEWS README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
