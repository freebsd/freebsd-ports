PORTNAME=	pyx
PORTVERSION=	0.16
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyX-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python package for creating encapsulated PostScript figures
WWW=		https://pyx-project.org/ \
		https://github.com/pyx-project/pyx

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python tex
USE_PYTHON=	autoplist concurrent distutils
USE_TEX=	latex:build

OPTIONS_DEFINE=	KPATHSEA T1CODE
OPTIONS_DEFAULT=KPATHSEA T1CODE
KPATHSEA_DESC=	Python wrapper around kpathsea
T1CODE_DESC=	Fast t1 font encoding/decoding

KPATHSEA_CFLAGS=	-I${LOCALBASE}/include
KPATHSEA_LDFLAGS=	-L${LOCALBASE}/lib
KPATHSEA_LIB_DEPENDS=	libkpathsea.so:devel/tex-kpathsea
KPATHSEA_VARS=		KPATHSEA=1
KPATHSEA_VARS_OFF=	KPATHSEA=0
T1CODE_CFLAGS=		-I${LOCALBASE}/include
T1CODE_VARS=		T1CODE=1
T1CODE_VARS_OFF=	T1CODE=0

post-patch:
	@${REINPLACE_CMD} -e 's|%%KPATHSEA%%|${KPATHSEA}|; s|%%T1CODE%%|${T1CODE}|' ${WRKSRC}/setup.cfg

post-install-KPATHSEA-on:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

post-install-T1CODE-on:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
