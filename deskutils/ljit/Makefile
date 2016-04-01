# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ljit
PORTVERSION=	0.2.5
PORTREVISION=	15
CATEGORIES=	deskutils
MASTER_SITES=	http://kir.vtx.ru/ljit/dl/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI tool to help LiveJournal users post images

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	convert:graphics/ImageMagick

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gettext pkgconfig
USE_GNOME=	gtk20

PLIST_FILES=	bin/ljit share/locale/ru/LC_MESSAGES/ljit.mo
PORTDOCS=	BUGS NEWS README THANKS TODO

OPTIONS_DEFINE=	DOCS

post-extract:
	@${REINPLACE_CMD} -e 's, -DMTRACE$$,, ; \
		s,prefix)/$$(DATADIRNAME,datadir,' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/po/ru_RU.mo \
		${STAGEDIR}${PREFIX}/share/locale/ru/LC_MESSAGES/${PORTNAME}.mo

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
