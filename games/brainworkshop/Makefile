# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brainworkshop
PORTVERSION=	4.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Brain%20Workshop%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free open-source version of the Dual N-Back mental exercise

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyglet/__init__.py:graphics/py-pyglet

USES=		dos2unix python:run zip
NO_BUILD=	yes
DOS2UNIX_FILES=	brainworkshop.pyw

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTSCOUT=	skipv:4.22

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

DESKTOP_ENTRIES="Brain Workshop" \
		"Dual N-Back mental exercise" \
		"${DATADIR}/brain.png" \
		"brainworkshop" \
		"Game;LogicGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e '/^FOLDER_RES = / s|res|${DATADIR}|; \
		/^FOLDER_DATA = / s|.data.|os.environ["HOME"]+"/.brainworkshop"|' \
		${WRKSRC}/brainworkshop.pyw

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/brainworkshop.pyw ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/res/* ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
