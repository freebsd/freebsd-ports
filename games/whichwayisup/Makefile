# New ports collection makefile for:	whichwayisup
# Date created:		14 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	whichwayisup
PORTVERSION=	0.7.9
PORTREVISION=	2
DISTVERSION=	${PORTVERSION:S/.//g}
CATEGORIES=	games
MASTER_SITES=	http://hectigo.net/puskutraktori/whichwayisup/
DISTNAME=	${PORTNAME}_b${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Platformer game with rotational twist

RUN_DEPENDS=	py*-game>=1.7.1:${PORTSDIR}/devel/py-game

BROKEN=		does not fetch

USE_PYTHON=	yes
USE_ZIP=	yes
PORTDOCS=	README.txt changelog.txt

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/libdir =/s|=.*|= "${PYTHON_SITELIBDIR}/${PORTNAME}"|'\
		${WRKSRC}/run_game.py
	@${REINPLACE_CMD} -e '/data_dir =/s|data_py.*data.|"${DATADIR}"|'\
		${WRKSRC}/lib/data.py
	@${RM} ${WRKSRC}/lib/data.py.bak

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/lib/
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/lib/
	@${TOUCH} ${WRKSRC}/data/music/.keep_me

do-install:
	@cd ${WRKSRC}/data/&&${COPYTREE_SHARE} . ${DATADIR}/
	@cd ${WRKSRC}/lib/&&${COPYTREE_SHARE} . ${PYTHON_SITELIBDIR}/${PORTNAME}/
	@${INSTALL_SCRIPT} ${WRKSRC}/run_game.py ${PREFIX}/bin/${PORTNAME}
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
