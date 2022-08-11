PORTNAME=	ctags
PORTVERSION=	5.8j2
CATEGORIES=	japanese devel
MASTER_SITES=	http://hp.vector.co.jp/authors/VA025040/ctags/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Feature-filled tagfile generator with Japanese support

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-macro-patterns --with-readlib
WRKSRC=		${WRKDIR}/${DISTNAME:S/j1//}
SUB_FILES=	pkg-message

PLIST_FILES=	bin/jexctags include/readtags.h lib/readtags.o \
		man/man1/jexctags.1.gz
PORTDOCS=	README README_J.TXT

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E 's,(bin|lib|inc|man1)dir),DESTDIR)$$(&,g' \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jexctags

.include <bsd.port.mk>
