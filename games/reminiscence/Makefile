# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	REminiscence
PORTVERSION=	0.3.5
CATEGORIES=	games
MASTER_SITES=	http://cyxdown.free.fr/reminiscence/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Rewritten engine for Flashback

LIB_DEPENDS=	libmodplug.so:audio/libmodplug \
		libvorbisidec.so:audio/libtremor

USES=		gmake pkgconfig tar:bzip2
USE_SDL=	sdl2

ALL_TARGET=	rs

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
