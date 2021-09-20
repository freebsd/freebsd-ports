PORTNAME=	REminiscence
PORTVERSION=	0.4.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://cyxdown.free.fr/reminiscence/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Rewritten engine for Flashback

LIB_DEPENDS=	libmodplug.so:audio/libmodplug
BUILD_DEPENDS=	${LOCALBASE}/include/stb/stb_vorbis.c:devel/stb

USES=		compiler:c++11-lang gmake pkgconfig sdl tar:bzip2
USE_SDL=	sdl2
ALL_TARGET=	rs
CPPFLAGS+=	-I${LOCALBASE}/include/stb

SUB_FILES=	pkg-message

PORTDOCS=	README.txt
PLIST_FILES=	bin/remin
PLIST_DIRS=	%%DATADIR%%/data

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|DATA|${DATADIR}/data|' ${WRKSRC}/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rs ${STAGEDIR}${PREFIX}/bin/remin
	@${MKDIR} ${STAGEDIR}${DATADIR}/data

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
