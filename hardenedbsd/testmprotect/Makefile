PORTNAME=	testmprotect
PORTVERSION=	1.0
CATEGORIES=	hardenedbsd
MAINTAINER=	shawn.webb@hardenedbsd.org
MASTER_SITES=	http://hardenedbsd.org/distfiles/

PLIST_FILES= \
	bin/testmprotect

do-install:
	cp ${WRKSRC}/testmprotect ${STAGEDIR}${PREFIX}/bin/testmprotect
	chmod u+rx,g+rx,o+rx ${STAGEDIR}${PREFIX}/bin/testmprotect

.include <bsd.port.mk>
