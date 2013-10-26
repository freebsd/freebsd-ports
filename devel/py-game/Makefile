# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	game
PORTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://pygame.seul.org/ftp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}release

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A module designed to write games in Python

LIB_DEPENDS=	smpeg:${PORTSDIR}/multimedia/smpeg
RUN_DEPENDS=	${PYNUMPY}

USE_SDL=	ttf image mixer sdl
USE_GCC=	any
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PYDISTUTILS_PKGNAME=	pygame
PYDISTUTILS_PKGVERSION=	${PORTVERSION}release

SDLNOX11=	sdl-nox11-[0-9]*

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|^_camera|#_camera|' \
		-e 's|^pypm|#pypm|' ${WRKSRC}/Setup.in
	@${REINPLACE_CMD} -e "s|Dependency('PORT|#Dependency('PORT|" \
		${WRKSRC}/config_unix.py

pre-configure:
	@invalid=`${PKG_INFO} -I ${SDLNOX11:C/.+/'&'/} 2>/dev/null | ${AWK} '{print $$1}'`
	@if [ ! -z "$$invalid" ]; then \
		${ECHO_MSG} "${PKGNAME} is marked as broken: devel/sdl12 needs to be built with X11 support enabled."; \
		exit 1; \
	fi

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} config.py -auto

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
