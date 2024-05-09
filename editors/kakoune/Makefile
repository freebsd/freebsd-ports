PORTNAME=	kakoune
DISTVERSION=	2024.05.09
CATEGORIES=	editors
MASTER_SITES=	https://github.com/mawww/kakoune/releases/download/v${DISTVERSION}/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Modal code editor with a focus on interactivity
WWW=		https://kakoune.org

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	setsid:sysutils/setsid

USES=		compiler:c++20-lang gmake tar:bzip2
DATADIR=	${PREFIX}/share/kak
DOCSDIR=	${PREFIX}/share/doc/kak
PATCH_WRKSRC=	${WRKSRC:H}

OPTIONS_DEFINE=	DEBUG DOCS

DEBUG_MAKE_ARGS=	debug=yes
DEBUG_MAKE_ARGS_OFF=	debug=no

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/-O3/d' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/kak

do-test:
	@cd ${WRKSRC:H}/test && ${SETENV} LC_ALL=en_US.UTF-8 ./run

.include <bsd.port.post.mk>
