# New ports collection makefile for:	pyawale
# Date created:		14 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyawale
PORTVERSION=	0.3.1
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/pyawale/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	African board game

RUN_DEPENDS=	py*-game>=1.7.1:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes
PORTDOCS=	AUTHORS ChangeLog NEWS README

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src/
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src/
	@${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/${PORTNAME}
	@${ECHO_CMD} "exec ${PYTHON_CMD} ${DATADIR}/src/pyawale.py"\
		>> ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} "data doc src" ${DATADIR}/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
