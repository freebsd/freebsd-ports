# $FreeBSD$

PORTNAME=	kakoune
DISTVERSION=	2018.04.13
CATEGORIES=	editors
MASTER_SITES=	https://github.com/mawww/kakoune/releases/download/v${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Modal code editor with a focus on interactivity

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/../UNLICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc

USES=		compiler:c++14-lang gmake ncurses tar:bzip2

DATADIR=	${PREFIX}/share/kak
DOCSDIR=	${PREFIX}/share/doc/kak
WRKSRC_SUBDIR=	src

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's,/share/man/,/man/,' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/kak

do-test:
	@cd ${WRKSRC}/../test && ${SETENV} LC_ALL=en_US.UTF-8 ./run

.include <bsd.port.mk>
