PORTNAME=			tevent
DISTVERSION=			0.16.1
PORTREVISION=			3
PORTEPOCH=			0
CATEGORIES=			devel
MASTER_SITES=			SAMBA
PKGNAMESUFFIX=			016

MAINTAINER=			samba@FreeBSD.org
COMMENT=			Talloc based event loop library
WWW=				https://tevent.samba.org/

LICENSE=			LGPL3

BUILD_DEPENDS=			talloc242>=2.4.2:devel/talloc242
RUN_DEPENDS=			talloc242>=2.4.2:devel/talloc242

USES=				compiler pkgconfig shebangfix waf
USE_LDCONFIG=			yes
SHEBANG_GLOB=			*.py
WAF_CMD=			buildtools/bin/waf
CONFIGURE_LOG=			bin/config.log

PKGCONFIGDIR?=			${PREFIX}/libdata/pkgconfig
PLIST_SUB=			PKGCONFIGDIR=${PKGCONFIGDIR:S;^${PREFIX}/;;}

CONFIGURE_ARGS=			--disable-rpath \
				--disable-rpath-install \
				--bundled-libraries=!talloc,cmocka \
				--builtin-libraries=replace \
				--without-gettext
CONFIGURE_ENV=			PYTHONHASHSEED=1
MAKE_ENV=			PYTHONHASHSEED=1

CONFLICTS_INSTALL=		tevent tevent[0-9]*

OPTIONS_DEFINE=			DEBUG PYTHON
OPTIONS_DEFAULT=		PYTHON
OPTIONS_SUB=			yes

DEBUG_CFLAGS=			-g -ggdb3 -O0
DEBUG_CONFIGURE_ON=		--verbose --enable-debug
DEBUG_MAKE_ARGS=		--verbose

PYTHON_USES=			gettext-runtime python
PYTHON_USE=			python=py3kplist
PYTHON_USES_OFF=		python:build,test
PYTHON_CONFIGURE_OFF=		--disable-python

# No fancy color error messages
CFLAGS+=			${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_clang=			-fno-color-diagnostics
CONFIGURE_ENV+=			NOCOLOR=yes
MAKE_ENV+=			NOCOLOR=yes
# Some symbols in tevent's linker version scripts are not defined, but since the
# scripts are generated dynamically, suppress errors with lld >= 17 due to these
# undefined symbols.
LDFLAGS+=			-Wl,--undefined-version

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
