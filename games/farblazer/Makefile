# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	farblazer
PORTVERSION=	0.7
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://www.pygame.org/gamelets/games/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An action/arcade game originally based of StarBlazer on the Apple ][

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes

NO_STAGE=	yes
do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}; ${TAR} cf - .) | \
		(cd ${DATADIR}; ${TAR} --exclude=\*.orig --unlink -xf -)
	@printf "#!/bin/sh\ncd ${DATADIR} && \
		exec ${PYTHON_CMD} ${DATADIR}/${PORTNAME}.py \"$$\@\"\n" > ${WRKDIR}/${PORTNAME}.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
