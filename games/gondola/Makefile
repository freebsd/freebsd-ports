# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gondola
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://files.arcticpaint.com/gondola/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	Gondola-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Create and optimize a distribution network of gondolas

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rabbyt>=0.8.1:${PORTSDIR}/graphics/py-rabbyt \
		${PYTHON_PKGNAMEPREFIX}pyglet>=1.1:${PORTSDIR}/graphics/py-pyglet \
		avbin>=7:${PORTSDIR}/multimedia/avbin

USE_ZIP=	yes
USE_PYTHON=	2.5+
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST=	PROGRAM_DIR="${PREFIX}/lib/${PORTNAME}"

WRKSRC=		${WRKDIR}/Gondola-${PORTVERSION}

PORTDATA=	*

DESKTOP_ENTRIES="Gondola" \
		"Create and optimize a distribution network of gondolas" \
		"" \
		"gondola" \
		"Game;StrategyGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|g' ${WRKSRC}/gamelib/*.py
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/gamelib/data.py ${WRKSRC}/gamelib/main.py
	@${RM} -f ${WRKSRC}/gamelib/*.{bak,orig}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "snowui gamelib simplejson run_game.py" \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} '*' ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
