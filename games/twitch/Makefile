# New ports collection makefile for:    twitch
# Date created:         		10 March 2001
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twitch
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An overhead 2-d shooter, reminiscent of games like Robotron

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes

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
