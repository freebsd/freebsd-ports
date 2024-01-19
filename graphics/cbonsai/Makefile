PORTNAME=	cbonsai
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
CATEGORIES=	graphics

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Bonsai tree generator, written in C using ncurses
WWW=		https://gitlab.com/jallbrit/cbonsai

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_14=	ld: error: undefined symbol: del_panel

USES=		compiler:c11 ncurses
USE_GITLAB=	yes
GL_ACCOUNT=	jallbrit
GL_TAGNAME=	7a6f4b0b0e1ce463691885b32a81517d2839d150

MAKE_ARGS=	LDLIBS="${LDFLAGS} -lncurses -lpanel"
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
