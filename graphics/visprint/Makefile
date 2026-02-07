PORTNAME=	visprint
PORTVERSION=	2.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.tastyrabbit.net/visprint/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates fractal fingerprint images based on any data
WWW=		https://www.tastyrabbit.net/visprint/

LIB_DEPENDS=	libpng.so:graphics/png

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lpng

PLIST_FILES=	bin/visprint share/man/man1/visprint.1.gz

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -c visprint.c)
	(cd ${WRKSRC} && ${CC} ${LDFLAGS} visprint.o -o visprint)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/visprint ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/visprint.1.gz \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
