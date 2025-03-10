PKGNAMESUFFIX=	-nrepl

COMMENT=	Notcurses REPL for s7

LIB_DEPENDS=	libnotcurses-core.so:devel/notcurses \
		libs7.so:lang/s7

MASTERDIR=	${.CURDIR}/../../lang/s7

PLIST_FILES=	bin/s7-nrepl

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -o ${WRKDIR}/s7-nrepl ${WRKSRC}/nrepl.c -ls7 -lnotcurses-core

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/s7-nrepl ${STAGEDIR}${PREFIX}/bin/

.include "${MASTERDIR}/Makefile.master"
