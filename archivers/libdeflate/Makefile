# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdeflate
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast, whole-buffer DEFLATE-based compression library

LICENSE=	MIT

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	ebiggers
USE_LDCONFIG=	yes

MAKE_ARGS=	V=1

PLIST_FILES=	bin/gunzip bin/gzip \
		include/libdeflate.h \
		lib/libdeflate.a lib/libdeflate.so lib/libdeflate.so.0
PORTDOCS=	NEWS README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's| -O2 -fomit-frame-pointer||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gunzip ${WRKSRC}/gzip \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libdeflate.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libdeflate.[as]* ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
