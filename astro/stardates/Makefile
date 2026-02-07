PORTNAME=	stardates
PORTVERSION=	1.6.1
CATEGORIES=	astro
MASTER_SITES=	ftp://ftp.cc.umanitoba.ca/startrek/stardates-pgms/ \
		http://trek.starshine.org/downlink/utilities/ \
		http://trek-stage.parts-unknown.org/downlink/

MAINTAINER=	freebsd-ports@henrik.synth.no
COMMENT=	Displays date in 5 formats (including stardate of course)

LICENSE=	BSD4CLAUSE

PLIST_FILES=	bin/stardate share/man/man1/stardate.1.gz

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/stardate.c -o ${WRKSRC}/stardate

do-install:
	${INSTALL} ${WRKSRC}/stardate ${STAGEDIR}${PREFIX}/bin
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/stardate
	${INSTALL_MAN} ${WRKSRC}/stardate.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
