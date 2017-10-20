# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	open-adventure
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	https://gitlab.com/${GL_ACCOUNT}/${GL_PROJECT}/repository/archive${EXTRACT_SUFX}?ref=${GL_COMMIT};/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Modernized version of the original Colossal Cave Adventure game

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/yaml/__init__.py:devel/py-yaml \
		a2x:textproc/asciidoc

ALL_TARGET=	advent
MAKE_ENV=	CCFLAGS="${CFLAGS}"

USES=		gmake pkgconfig libedit python:build
#USE_GITLAB=	yes # When USE_GITLAB has become available, MASTER_SITES and WRKSRC should be obsolete

WRKSRC=		${WRKDIR}/${PORTNAME}-${GL_COMMIT}-${GL_COMMIT}

GL_ACCOUNT=	esr
GL_PROJECT=	${PORTNAME}
GL_COMMIT=	d51238481a6a752adc8ad4d8893209d13bb7ea91

PLIST_FILES=	bin/advent man/man6/advent.6.gz

pre-build:
		cd ${WRKSRC}; ${PYTHON_CMD} make_dungeon.py; a2x -f manpage advent.adoc

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/advent ${STAGEDIR}${PREFIX}/bin
		#${MKDIR} ${STAGEDIR}${MANPREFIX}/man/man6
		${INSTALL_MAN} ${WRKSRC}/advent.6 ${STAGEDIR}${MANPREFIX}/man/man6

.include <bsd.port.mk>
