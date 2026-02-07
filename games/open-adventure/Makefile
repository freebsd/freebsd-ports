PORTNAME=	open-adventure
PORTVERSION=	1.16
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	se@FreeBSD.org
COMMENT=	Modernized version of the original Colossal Cave Adventure game
WWW=		http://www.catb.org/~esr/open-adventure/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		a2x:textproc/asciidoc

USES=		gmake libedit pkgconfig python:build
USE_GITLAB=	yes
GL_ACCOUNT=	esr
GL_TAGNAME=	${PORTVERSION}

MAKE_ENV=	CCFLAGS="${CFLAGS}"
ALL_TARGET=	advent

PLIST_FILES=	bin/advent \
		share/man/man6/advent.6.gz

pre-build:
		cd ${WRKSRC}; ${PYTHON_CMD} make_dungeon.py; a2x -f manpage advent.adoc

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/advent ${STAGEDIR}${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/advent.6 ${STAGEDIR}${PREFIX}/share/man/man6

.include <bsd.port.mk>
