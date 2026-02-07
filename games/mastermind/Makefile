PORTNAME=	mastermind
DISTVERSION=	0.1.0
CATEGORIES=	games

MAINTAINER=	bigdragonsoft@gmail.com
COMMENT=	Traditional console-based Mastermind game
WWW=		https://github.com/bigdragonsoft/mastermind

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	bigdragonsoft

CFLAGS+=	-std=c99

PLIST_FILES=	bin/mastermind \
		share/man/man6/mastermind.6.gz

do-build:
	${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/mastermind ${WRKSRC}/mastermind.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mastermind ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/mastermind.6 ${STAGEDIR}${PREFIX}/share/man/man6/

.include <bsd.port.mk>
