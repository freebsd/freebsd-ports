PORTNAME=	open-adventure
PORTVERSION=	1.21
CATEGORIES=	games

MAINTAINER=	se@FreeBSD.org
COMMENT=	Modernized version of the original Colossal Cave Adventure game
WWW=		http://www.catb.org/~esr/open-adventure/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		a2x:textproc/asciidoc

USES=		gmake libedit pkgconfig python:build
USE_GITLAB=	yes
GL_ACCOUNT=	esr

MAKE_ENV=	CCFLAGS="${CFLAGS}"
ALL_TARGET=	advent

PLIST_FILES=	bin/advent \
		share/applications/advent.desktop \
		share/icons/advent/advent.svg \
		share/man/man6/advent.6.gz

pre-build:
		cd ${WRKSRC}; ${PYTHON_CMD} make_dungeon.py && a2x -f manpage advent.adoc

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/advent ${STAGEDIR}${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/advent.6 ${STAGEDIR}${PREFIX}/share/man/man6
		${INSTALL_DATA} ${WRKSRC}/advent.desktop ${STAGEDIR}${PREFIX}/share/applications
		${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/advent
		${INSTALL_DATA} ${WRKSRC}/advent.svg ${STAGEDIR}${PREFIX}/share/icons/advent

.include <bsd.port.mk>
