# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brainworkshop
PORTVERSION=	4.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Brain%20Workshop%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free open-source version of the Dual N-Back mental exercise

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyglet/__init__.py:${PORTSDIR}/graphics/py-pyglet

USES=		dos2unix zip
NO_BUILD=	yes
DOS2UNIX_FILES=	brainworkshop.pyw

USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTSCOUT=	skipv:4.22

DESKTOP_ENTRIES="Brain Workshop" \
		"Dual N-Back mental exercise" \
		"${DATADIR}/brain.png" \
		"brainworkshop" \
		"Game;LogicGame;" \
		false

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/^FOLDER_RES = / s|res|${DATADIR}|; \
		/^FOLDER_DATA = / s|.data.|os.environ["HOME"]+"/.brainworkshop"|' \
		${WRKSRC}/brainworkshop.pyw

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/brainworkshop.pyw ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/res/* ${DATADIR}/

.include <bsd.port.mk>
