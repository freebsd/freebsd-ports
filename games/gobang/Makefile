PORTNAME=	gobang
DISTVERSION=	0.1.2
CATEGORIES=	games
PKGNAMESUFFIX=	-game

MAINTAINER=	bigdragonsoft@gmail.com
COMMENT=	This is a Gobang game that runs in the console
WWW=		https://github.com/bigdragonsoft/gobang

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	bigdragonsoft

CFLAGS+=	-std=c99

PLIST_FILES=	bin/gobang \
		share/man/man6/gobang.6.gz

do-build:
	${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/gobang ${WRKSRC}/gobang.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gobang ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/gobang.6 ${STAGEDIR}${PREFIX}/share/man/man6/

.include <bsd.port.mk>
