# $FreeBSD$

PORTNAME=	cbonsai
DISTVERSION=	g20210105
CATEGORIES=	graphics

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Bonsai tree generator, written in C using ncurses

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 localbase ncurses
USE_GITLAB=	yes
GL_ACCOUNT=	jallbrit
GL_COMMIT=	9fe79e955b5d8f6dd7bdc85cbc4ac255934625d1

LDFLAGS+=	-lncurses -lpanel

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-build:
		${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
