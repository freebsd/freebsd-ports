PORTNAME=	cursive
PORTVERSION=	0.11
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	https://www.unixpapa.com/software/
DISTNAME=	${PORTNAME}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Create ASCII character cursive handwriting
WWW=		https://www.unixpapa.com/cursive.html

USES=		tar:tgz
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/cursive \
		share/man/man6/cursive.6.gz

do-build:
	${CC} ${CFLAGS} -c ${WRKSRC}/cursive.c -o ${WRKSRC}/cursive.o
	${CC} ${CFLAGS} -c ${WRKSRC}/font.c -o ${WRKSRC}/font.o
	${CC} ${CFLAGS} -o ${WRKSRC}/cursive ${WRKSRC}/cursive.o ${WRKSRC}/font.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cursive ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cursive.6 ${STAGEDIR}${PREFIX}/share/man/man6

.include <bsd.port.mk>
