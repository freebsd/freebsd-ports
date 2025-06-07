PORTNAME=	kakoune
DISTVERSION=	2025.06.03
CATEGORIES=	editors
MASTER_SITES=	https://github.com/mawww/kakoune/releases/download/v${DISTVERSION}/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Modal code editor with a focus on interactivity
WWW=		https://kakoune.org

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

# See https://github.com/mawww/kakoune/issues/2520
RUN_DEPENDS=	setsid:sysutils/setsid

USES=		compiler:c++23-lang tar:bzip2
DATADIR=	${PREFIX}/share/kak
DOCSDIR=	${PREFIX}/share/doc/kak

OPTIONS_DEFINE=	DEBUG DOCS

DEBUG_MAKE_ARGS=	debug=yes

TEST_TARGET=	test
TEST_ENV+=	LC_ALL=en_US.UTF-8

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/kak

.include <bsd.port.mk>
