# New ports collection makefile for:	py-game
# Date created:				14 December 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	game
PORTVERSION=	1.8.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://pygame.seul.org/ftp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}release

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A module designed to write games in Python

LIB_DEPENDS=	smpeg.1:${PORTSDIR}/multimedia/smpeg

USE_SDL=	ttf image mixer sdl
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PYDISTUTILS_PKGNAME=	pygame
PYDISTUTILS_PKGVERSION=	1.8.1release

SDLNOX11=	sdl-nox11-[0-9]*

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-patch:
	@${FIND} ${WRKSRC} -type d | xargs ${CHMOD} a+rx
	@${FIND} ${WRKSRC} -type f | xargs ${CHMOD} a+r

pre-configure:
	@invalid=`${PKG_INFO} -I ${SDLNOX11:C/.+/'&'/} 2>/dev/null | ${AWK} '{print $$1}`
	@if [ ! -z "$$invalid" ]; then \
		${ECHO_MSG} "${PKGNAME} is marked as broken: devel/sdl12 needs to be built with X11 support enabled."; \
		exit 1; \
	fi

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
