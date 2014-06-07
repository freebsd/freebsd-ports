# $FreeBSD$

PORTNAME=	micropython
PORTVERSION=	1.0.1
CATEGORIES=	lang python

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Implementation of the Python language for microcontrollers

LICENSE=	MIT

LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi

USE_PYTHON_BUILD=	yes
USES=			gmake shebangfix pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	micropython
GH_PROJECT=	micropython
GH_TAGNAME=	v1.0.1
GH_COMMIT=	a56f31d

PLIST_FILES=	bin/micropython

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}/unix

SHEBANG_FILES=	../py/py-version.sh
bash_CMD?=	/bin/sh
MAKE_ARGS+=	V=1
MAKE_ENV+=	PYTHON=${PYTHON_CMD}

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||;s|-ldl||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|AS =|AS ?=|;s|LD =|LD ?=|; \
		s|CC =|CC ?=|;s|PYTHON =|PYTHON ?=|' \
		${WRKSRC}/../py/mkenv.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micropython ${STAGEDIR}${PREFIX}/bin

regression-test: build
	${RM} ${WRKSRC}/../tests/basics/memoryerror.py
	cd ${WRKSRC} && ${MAKE_CMD} test

.include <bsd.port.mk>
