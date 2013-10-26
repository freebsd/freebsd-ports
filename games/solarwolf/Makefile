# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	solarwolf
PORTVERSION=	1.5
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.pygame.org/shredwheat/solarwolf/

MAINTAINER=	benlutz@datacomm.ch
COMMENT=	An action/arcade game originally based of SolarFox on the Atari 2600

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes
MAN6=		solarwolf.6

NO_STAGE=	yes
post-extract:
	${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} 755
	${CHMOD} 755 ${WRKSRC}/solarwolf.py

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/share/solarwolf
	(cd ${WRKSRC}; tar -cf - --exclude ".xvpics" .) | \
		(cd ${PREFIX}/share/solarwolf; tar --unlink -xf -)
	@printf "#!/bin/sh\ncd ${PREFIX}/share/solarwolf && \
		exec ${PYTHON_CMD} ${PREFIX}/share/solarwolf/solarwolf.py\n" > ${WRKDIR}/solarwolf.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/solarwolf.sh ${PREFIX}/bin/solarwolf
	@${GUNZIP_CMD} -c ${WRKSRC}/dist/${MAN6}.gz > ${MAN6PREFIX}/man/man6/${MAN6}

.include <bsd.port.mk>
