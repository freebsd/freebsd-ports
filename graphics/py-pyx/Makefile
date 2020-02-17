# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyx
PORTVERSION=	0.15
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyX-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python package for creating encapsulated PostScript figures

LICENSE=	GPLv2

USES=		python:3.4+
USE_PYTHON=	autoplist distutils
USE_TEX=	latex:build

OPTIONS_DEFINE=	KPATHSEA T1CODE
OPTIONS_DEFAULT=KPATHSEA T1CODE
KPATHSEA_DESC=	Python wrapper around kpathsea
T1CODE_DESC=	Fast t1 font encoding/decoding

KPATHSEA_CFLAGS=	-I${LOCALBASE}/include
KPATHSEA_LDFLAGS=	-L${LOCALBASE}/lib
T1CODE_CFLAGS=		-I${LOCALBASE}/include

post-patch-KPATHSEA-on:
	@${REINPLACE_CMD} -e 's|build_pykpathsea=0|build_pykpathsea=1|' ${WRKSRC}/setup.cfg

post-patch-T1CODE-on:
	@${REINPLACE_CMD} -e 's|build_t1code=0|build_t1code=1|' ${WRKSRC}/setup.cfg

.include <bsd.port.mk>
