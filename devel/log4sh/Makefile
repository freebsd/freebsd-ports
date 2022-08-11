PORTNAME=	log4sh
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%201.4.X%20%28stable%29/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Common logging library for Bourne shell scripts

USES=		cpe

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	lib/log4sh
PORTDOCS=	log4sh.html

ALL_TARGET=	build

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/shell/log4sh ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/log4sh.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
