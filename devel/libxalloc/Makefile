PORTNAME=	libxalloc
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/
DISTNAME=	xalloc-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Memory allocation library with error checking

OPTIONS_DEFINE=	DOCS

USES=		uidfix

MAKEFILE=	${FILESDIR}/Makefile.lib
USE_LDCONFIG=	yes
MAKE_ENV=	WITHOUT_PROFILE=yes __MAKE_CONF=/dev/null SRCCONF=/dev/null

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
