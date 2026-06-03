PORTNAME=	hunspell
PORTVERSION=	0.7.90
PORTREVISION=	2
CATEGORIES=	korean textproc

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Korean hunspell dictionaries
WWW=		https://spellcheck-ko.github.io

LICENSE=	GPLv2+ LGPL21+ MPL11
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE.GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LICENSE.LGPL
LICENSE_FILE_MPL11=	${WRKSRC}/LICENSE.MPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}
TEST_DEPENDS=	hunspell:textproc/hunspell	\
		gmake:devel/gmake

GH_ACCOUNT=	spellcheck-ko
GH_PROJECT=	${PORTNAME}-dict-ko
USE_GITHUB=	yes

NO_ARCH=	yes
USES=		python:build,test shebangfix
SHEBANG_FILES=	tests/runtest.py

PLIST_FILES=	${DATADIR}/ko_KR.aff \
		${DATADIR}/ko_KR.dic

TEST_TARGET=	test
TEST_ENV+=	GMAKE=${GMAKE} LC_ALL=en_US.UTF-8

pre-build:
.for f in Makefile tests/Makefile
	${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|' ${WRKSRC}/${f}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ko_KR.aff ${WRKSRC}/ko_KR.dic \
	    ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
