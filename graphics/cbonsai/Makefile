# $FreeBSD$

PORTNAME=	cbonsai
DISTVERSION=	1.0.4
CATEGORIES=	graphics

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Bonsai tree generator, written in C using ncurses

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 ncurses
USE_GITLAB=	yes
GL_ACCOUNT=	jallbrit
GL_COMMIT=	bf12bd4a87e0435155e6be71b3d72b1a992e6f01

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
