PORTNAME=	tinycols
DISTVERSION=	0.8.5
CATEGORIES=	games

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Jewels matching game for the terminal
WWW=		https://github.com/zedr/tinycols

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	zedr

CPPFLAGS+=	-I${NCURSESINC:/ncurses=}
LDFLAGS+=	-L${NCURSESLIB}
LIBS+=		${NCURSESLIBS}

PLIST_FILES=	bin/tinycols \
		share/man/man6/tinycols.6.gz

do-build:
	${MKDIR} ${WRKSRC}/build
	${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/build/tinycols \
	    ${WRKSRC}/src/main.c ${WRKSRC}/src/gfx.c ${WRKSRC}/src/tinycols/*.c \
	    ${WRKSRC}/src/queue.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/tinycols ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/man/tinycols.6 ${STAGEDIR}${PREFIX}/share/man/man6/

.include <bsd.port.mk>
