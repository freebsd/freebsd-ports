# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	open-adventure
PORTVERSION=	1.9
CATEGORIES=	games

MAINTAINER=	se@FreeBSD.org
COMMENT=	Modernized version of the original Colossal Cave Adventure game

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/yaml/__init__.py:devel/py-yaml@${PY_FLAVOR} \
		a2x:textproc/asciidoc

USES=		gmake libedit pkgconfig python:build
USE_GITLAB=	yes
GL_ACCOUNT=	esr
GL_COMMIT=	f2f238e9e42ed76f9cfac219f37142cd7bcf6edb

MAKE_ENV=	CCFLAGS="${CFLAGS}"
ALL_TARGET=	advent

PLIST_FILES=	bin/advent \
		man/man6/advent.6.gz

pre-build:
		cd ${WRKSRC}; ${PYTHON_CMD} make_dungeon.py; a2x -f manpage advent.adoc

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/advent ${STAGEDIR}${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/advent.6 ${STAGEDIR}${MANPREFIX}/man/man6

.include <bsd.port.mk>
