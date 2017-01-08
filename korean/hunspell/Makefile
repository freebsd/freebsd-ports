# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	0.5.6
PORTREVISION=	3
CATEGORIES=	korean textproc

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Korean hunspell dictionaries

LICENSE=	GPLv2+ LGPL21+ MPL
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE.GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LICENSE.LGPL
LICENSE_FILE_MPL=	${WRKSRC}/LICENSE.MPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml
TEST_DEPENDS=	hunspell:textproc/hunspell

GH_ACCOUNT=	changwoo
GH_PROJECT=	${PORTNAME}-dict-ko
USE_GITHUB=	yes

NO_ARCH=	yes
USES=		python:build,test

PLIST_FILES=	%%DATADIR%%/ko_KR.aff \
		%%DATADIR%%/ko_KR.dic

do-build:
	@(cd ${WRKSRC} && ${PYTHON_CMD} make-aff-dic.py ko_KR.aff ko_KR.dic \
	    dict-ko-builtins.xml dict-ko-galkwi.xml)

do-test:
	@(cd ${WRKSRC}/tests && for T in $$(ls -1 *.test); do \
	    echo "Testing $$T..."; \
	    ${PYTHON_CMD} runtest.py $$T || exit 1; done)
do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ko_KR.aff ${WRKSRC}/ko_KR.dic \
	    ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
