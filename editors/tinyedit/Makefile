PORTNAME=      tinyedit
PORTVERSION=   1.0.6
CATEGORIES=    editors

MAINTAINER=    ervras@aim.com
COMMENT=       Lightweight text editor with charset conversion

LICENSE=       GPLv2
LICENSE_FILE=  ${WRKSRC}/LICENSE

USES=          ncurses gmake
USE_GITHUB=    yes
GH_ACCOUNT=    skbn
GH_PROJECT=    tinyedit
GH_TAGNAME=    main

CONFIGURE_CMD=

do-build:
	(cd ${WRKSRC} && ${GMAKE} -f Makefile.unix)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tinyedit ${STAGEDIR}${PREFIX}/bin/te
	${INSTALL_MAN} ${FILESDIR}/te.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
