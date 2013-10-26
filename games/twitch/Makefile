# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twitch
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Twitch/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An overhead 2-d shooter, reminiscent of games like Robotron

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes

NO_STAGE=	yes
do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/share/twitch
	(cd ${WRKSRC}; ${TAR} cf - images sound levels twitch.*) | \
		(cd ${PREFIX}/share/twitch; ${TAR} xf -)
	@printf "#!/bin/sh\ncd ${PREFIX}/share/twitch && \
		${PYTHON_CMD} ${PREFIX}/share/twitch/twitch.py\n" > ${WRKDIR}/twitch.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/twitch.sh ${PREFIX}/bin/twitch

.include <bsd.port.mk>
