# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	lite
PORTVERSION=	1.11
CATEGORIES=	editors
PKGNAMESUFFIX=	-editor		# PORTNAME alone is too vague

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight text editor written mostly in Lua

LICENSE=	MIT

USES=		gmake lua pkgconfig sdl
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	rxi
GH_TAGNAME=	38bd9b3

BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	${FILESDIR}/makefile

PORTDOCS=	usage.md

OPTIONS_DEFINE=	DOCS

post-extract:
# Prevent accidental build/use of bundled code/headers
	@${RM} -r ${BUILD_WRKSRC}/lib/lua52 ${WRKSRC}/winlib

post-patch:
	@${REINPLACE_CMD} -e '/^#include/s,lib/lua52/,,' \
		${BUILD_WRKSRC}/api/api.h
	@${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},' \
		${BUILD_WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${CP} -a ${WRKSRC}/data ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
