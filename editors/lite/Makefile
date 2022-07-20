PORTNAME=	lite
PORTVERSION=	1.11
CATEGORIES=	editors
PKGNAMESUFFIX=	-editor		# PORTNAME alone is too vague

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight text editor written mostly in Lua

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	a38b89ca26dde1353cf1.patch:-p1

LICENSE=	MIT

USES=		gmake lua pkgconfig sdl
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	rxi
GH_PROJECT=	${PORTNAME}-colors:colors ${PORTNAME}-plugins:plugins
GH_TAGNAME=	38bd9b3 5b77292:colors 4a9e1f3:plugins

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
	${CP} -a ${WRKSRC_colors}/colors ${STAGEDIR}${DATADIR}/user
	${MV} ${WRKSRC_plugins}/plugins/language_*.lua \
		${STAGEDIR}${DATADIR}/plugins
	${CP} -a ${WRKSRC_plugins}/plugins \
		${STAGEDIR}${DATADIR}/plugins/extra

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
