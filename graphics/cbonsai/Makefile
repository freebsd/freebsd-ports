# $FreeBSD$

PORTNAME=	cbonsai
DISTVERSION=	g20210115
CATEGORIES=	graphics

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Bonsai tree generator, written in C using ncurses

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 ncurses
USE_GITLAB=	yes
GL_ACCOUNT=	jallbrit
GL_COMMIT=	e1070054e5bf5c30056cd31f01e8ecc8df8f02cd

MAKE_ARGS=	LDLIBS="${LDFLAGS} -lncurses -lpanel"
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
