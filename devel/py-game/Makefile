# New ports collection makefile for:	py-game
# Date created:				14 December 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	py-game
PORTVERSION=	1.6
CATEGORIES=	devel python
MASTER_SITES=	http://pygame.seul.org/ftp/
DISTNAME=	${PORTNAME:S/-//}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A module designed to write games in Python

BUILD_DEPENDS=	${PYNUMERIC}
LIB_DEPENDS=	smpeg.1:${PORTSDIR}/multimedia/smpeg
RUN_DEPENDS=	${PYNUMERIC}

USE_SDL=	ttf image mixer sdl
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

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
