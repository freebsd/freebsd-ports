# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PyX
PORTVERSION=	0.14.1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	12

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python package for creating encapsulated PostScript figures

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase python:3.3+
USE_TEX=	latex:build
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		T1CODE KPATHSEA
OPTIONS_DEFAULT=	T1CODE KPATHSEA
T1CODE_DESC=		Fast t1 font encoding/decoding
KPATHSEA_DESC=		Python wrapper around kpathsea
KPATHSEA_USE=		TEX=kpathsea

post-patch-KPATHSEA-on:
	@${REINPLACE_CMD} -e 's|build_pykpathsea=0|build_pykpathsea=1|' ${WRKSRC}/setup.cfg

post-patch-T1CODE-on:
	@${REINPLACE_CMD} -e 's|build_t1code=0|build_t1code=1|' ${WRKSRC}/setup.cfg

post-install-KPATHSEA-on:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyx/pykpathsea.so

post-install-T1CODE-on:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyx/font/_t1code.so

.include <bsd.port.mk>
