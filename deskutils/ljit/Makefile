# New ports collection makefile for:	ljit
# Date created:				09 Sep 2004
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ljit
PORTVERSION=	0.2.5
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://kir.vtx.ru/ljit/dl/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GUI tool to help LiveJournal users post images

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GETTEXT=	yes
USE_GNOME=	gtk20
USE_REINPLACE=	yes

post-extract:
	@${REINPLACE_CMD} -e 's, -DMTRACE$$,,' -e 's,prefix)/$$(DATADIRNAME,datadir,' \
		${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/po/ru_RU.mo ${PREFIX}/share/locale/ru/LC_MESSAGES/${PORTNAME}.mo
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in BUGS NEWS README THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
