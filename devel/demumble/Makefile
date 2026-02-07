PORTNAME=	demumble
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Better c++filt and undname in one binary (symbol demangler)
WWW=		https://github.com/nico/demumble

LICENSE=	APACHE20

USES=		cmake python:test
USE_GITHUB=	yes
GH_ACCOUNT=	nico

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

do-test:
	@${LN} -f ${BUILD_WRKSRC}/${PORTNAME} ${WRKSRC}
	${PYTHON_CMD} ${WRKSRC}/demumble_test.py

.include <bsd.port.mk>
