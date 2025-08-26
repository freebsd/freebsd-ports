PORTNAME=	tevent
DISTVERSION=	0.17.0
CATEGORIES=	devel
MASTER_SITES=	SAMBA
PKGNAMESUFFIX=	017

MAINTAINER=	samba@FreeBSD.org
COMMENT=	Talloc based event loop library
WWW=		https://tevent.samba.org/

LICENSE=	LGPL3

BUILD_DEPENDS=	talloc243>=2.4.3:devel/talloc243
RUN_DEPENDS=	talloc243>=2.4.3:devel/talloc243

USES=		compiler pkgconfig shebangfix waf
USE_LDCONFIG=	yes
WAF_CMD=	buildtools/bin/waf
SHEBANG_GLOB=	*.py
CONFIGURE_LOG=	bin/config.log

PKGCONFIGDIR?=	${PREFIX}/libdata/pkgconfig

CONFIGURE_ARGS=	--builtin-libraries=replace \
		--bundled-libraries=!talloc,cmocka \
		--disable-rpath \
		--disable-rpath-install \
		--without-gettext
CONFIGURE_ENV=	PYTHONHASHSEED=1
MAKE_ENV=	PYTHONHASHSEED=1
# Some symbols in tevent's linker version scripts are not defined, but since the
# scripts are generated dynamically, suppress errors with lld >= 17 due to these
# undefined symbols.
LDFLAGS+=	-Wl,--undefined-version

CONFLICTS_INSTALL=	tevent tevent[0-9]*

PLIST_SUB=	PKGCONFIGDIR=${PKGCONFIGDIR:S;^${PREFIX}/;;}

OPTIONS_DEFINE=		DEBUG PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

DEBUG_CONFIGURE_ON=	--enable-debug \
			--verbose
DEBUG_MAKE_ARGS=	--verbose
DEBUG_CFLAGS=		-g -ggdb3 -O0

PYTHON_USES=		gettext-runtime python
PYTHON_USES_OFF=	python:build,test
PYTHON_USE=		PYTHON=py3kplist
PYTHON_CONFIGURE_OFF=	--disable-python

post-patch:
	@${REINPLACE_CMD} -e 's|%%PKGCONFIGDIR%%|${PKGCONFIGDIR}|g' \
		${BUILD_WRKSRC}/wscript

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/tevent/libcmocka-tevent.so
	${RM} ${STAGEDIR}${PREFIX}/lib/tevent/libpytalloc-util.cpython-${PYTHON_SUFFIX}-tevent.so
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/tevent
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtevent.so

post-install-PYTHON-on:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_tevent*.so
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
