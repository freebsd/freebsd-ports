PORTNAME=	fc++
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	http://people.cs.umass.edu/~yannis/fc++/
DISTNAME=	${PORTNAME:tu}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Functional Programming in C++

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/fc++
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/fc++
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changes.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
