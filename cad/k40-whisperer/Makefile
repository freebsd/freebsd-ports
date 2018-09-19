# $FreeBSD$

PORTNAME=	k40-whisperer
DISTVERSION=	0.19
CATEGORIES=	cad python
MASTER_SITES=	http://www.scorchworks.com/K40whisperer/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	K40_Whisperer-${DISTVERSION}_src

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	GUI control software for the stock K40 laser cutter controller

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/gpl-3.0.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}usb>0:devel/py-usb@${PY_FLAVOR}

USES=		python:2.7 zip

OPTIONS_DEFINE=		DOCS

NO_BUILD=	yes

WHISPERER_COMMAND=	${PORTNAME}
SUB_FILES=	pkg-message ${WHISPERER_COMMAND}
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} WHISPERER_COMMAND=${WHISPERER_COMMAND}
PLIST_SUB=	WHISPERER_COMMAND=${WHISPERER_COMMAND}

DATA=	bezmisc.py \
	CC.png \
	cspsubdiv.py \
	cubicsuperpath.py \
	down.png \
	dxf.py \
	egv.py \
	emblem64 \
	ffgeom.py \
	g_code_library.py \
	inkex.py \
	interpolate.py \
	k40_whisperer.py \
	left.png \
	LL.png \
	LR.png \
	nano_library.py \
	right.png \
	simplepath.py \
	simplestyle.py \
	simpletransform.py \
	svg_reader.py \
	UL.png \
	up.png \
	UR.png

DOCS=	README_Linux.txt \
	README_MacOS.md

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${WHISPERER_COMMAND} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DATA:S,^,${WRKSRC}/,} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
