# New ports collection makefile for:	py-game
# Date created:				14 December 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	game
PORTVERSION=	1.8.0
CATEGORIES=	devel python
MASTER_SITES=	http://pygame.seul.org/ftp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}release

MAINTAINER=	mva@sysfault.org
COMMENT=	A module designed to write games in Python

LIB_DEPENDS=	smpeg.1:${PORTSDIR}/multimedia/smpeg

USE_SDL=	ttf image mixer sdl
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PYDISTUTILS_PKGNAME=	pygame
PYDISTUTILS_PKGVERSION=	1.8.0release

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} config.py

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples -cf - . | \
		${TAR} --unlink -C ${EXAMPLESDIR} -xf -
	${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/docs -cf - . | \
		${TAR} --unlink -C ${DOCSDIR} -xf -
.endif

.include <bsd.port.mk>
