# New ports collection makefile for:	ljit
# Date created:				09 Sep 2004
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ljit
PORTVERSION=	0.2.5
PORTREVISION=	15
CATEGORIES=	deskutils
MASTER_SITES=	http://kir.vtx.ru/ljit/dl/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI tool to help LiveJournal users post images

LICENSE=	GPLv2

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gettext
USE_GNOME=	gtk20

PLIST_FILES=	bin/ljit share/locale/ru/LC_MESSAGES/ljit.mo
PORTDOCS=	BUGS NEWS README THANKS TODO

post-extract:
	@${REINPLACE_CMD} -e 's, -DMTRACE$$,, ; \
		s,prefix)/$$(DATADIRNAME,datadir,' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/po/ru_RU.mo \
		${PREFIX}/share/locale/ru/LC_MESSAGES/${PORTNAME}.mo
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
