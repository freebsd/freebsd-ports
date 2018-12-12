# $FreeBSD$

PORTNAME=	kakoune
DISTVERSION=	2018.10.27
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://github.com/mawww/kakoune/releases/download/v${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Modal code editor with a focus on interactivity

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC:H}/UNLICENSE

RUN_DEPENDS=	setsid:sysutils/ssid

USES=		compiler:c++14-lang gmake ncurses tar:bzip2

DATADIR=	${PREFIX}/share/kak
DOCSDIR=	${PREFIX}/share/doc/kak
PATCH_WRKSRC=	${WRKSRC:H}
WRKSRC_SUBDIR=	src

OPTIONS_DEFINE=	DEBUG DOCS

DEBUG_MAKE_ARGS=	debug=yes
DEBUG_MAKE_ARGS_OFF=	debug=no

post-patch:
	@${REINPLACE_CMD} -e 's,/share/man/,/man/,' -e '/-O3/d' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/kak

do-test:
	@cd ${WRKSRC:H}/test && ${SETENV} LC_ALL=en_US.UTF-8 ./run

.include <bsd.port.mk>
