# New ports collection makefile for:	gondola
# Date created:		03 Apr 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gondola
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://arcticpaint.com/static/gondola/downloads/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	Gondola-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Create and optimize a distribution network of gondolas

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rabbyt>=0.8.1:${PORTSDIR}/graphics/py-rabbyt \
		${PYTHON_PKGNAMEPREFIX}pyglet>=1.1:${PORTSDIR}/graphics/py-pyglet \
		avbin>=7:${PORTSDIR}/multimedia/avbin

USE_ZIP=	yes
USE_PYTHON=	2.4+
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST=	PROGRAM_DIR="${PREFIX}/lib/${PORTNAME}"

WRKSRC=		${WRKDIR}/Gondola-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|g' ${WRKSRC}/gamelib/*.py
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/gamelib/data.py ${WRKSRC}/gamelib/main.py
	@${RM} -f ${WRKSRC}/gamelib/*.{bak,orig}

do-install:
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "snowui gamelib simplejson run_game.py" \
		${PREFIX}/lib/${PORTNAME}
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} '*' ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
