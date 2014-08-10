# $FreeBSD$

PORTNAME=	micropython
PORTVERSION=	1.2
CATEGORIES=	lang python

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Implementation of the Python language for microcontrollers

LICENSE=	MIT

LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi

USES=			gmake pkgconfig python:build readline shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	micropython
GH_PROJECT=	micropython
GH_TAGNAME=	v1.2
GH_COMMIT=	d94863d

PLIST_FILES=	bin/micropython

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}/unix

SHEBANG_FILES=	../py/py-version.sh
bash_CMD?=	/bin/sh
MAKE_ARGS+=	V=1
MAKE_ENV+=	PYTHON=${PYTHON_CMD} CFLAGS_EXTRA="${CPPFLAGS} ${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-error=cpp||;s|-Werror||;/^COPT =/d' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|AS =|AS ?=|;s|LD =|LD ?=|; \
		s|CC =|CC ?=|;s|PYTHON =|PYTHON ?=|' \
		${WRKSRC}/../py/mkenv.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micropython ${STAGEDIR}${PREFIX}/bin

regression-test: build
	${RM} ${WRKSRC}/../tests/basics/memoryerror.py
	cd ${WRKSRC} && ${MAKE_CMD} test

.include <bsd.port.mk>
