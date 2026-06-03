PORTNAME=			tdb
DISTVERSION=			1.4.10
PORTREVISION=			3
PORTEPOCH=			1
CATEGORIES=			databases
MASTER_SITES=			SAMBA
PKGNAMESUFFIX=			1410

MAINTAINER=			samba@FreeBSD.org
COMMENT=			Trivial Database
WWW=		https://tdb.samba.org/

LICENSE=			GPLv3

USES=				compiler pkgconfig shebangfix waf
USE_LDCONFIG=			yes
SHEBANG_GLOB=			*.py
WAF_CMD=			buildtools/bin/waf
CONFIGURE_LOG=			bin/config.log

PKGCONFIGDIR?=			${PREFIX}/libdata/pkgconfig
PLIST_SUB+=			PKGCONFIGDIR=${PKGCONFIGDIR:S;^${PREFIX}/;;}

CONFIGURE_ARGS+=		--disable-rpath \
				--disable-rpath-install \
				--bundled-libraries=NONE \
				--builtin-libraries=replace \
				--without-gettext
CONFIGURE_ENV=			PYTHONHASHSEED=1
MAKE_ENV=			PYTHONHASHSEED=1

CONFLICTS_INSTALL=		tdb tdb[0-9]*

OPTIONS_DEFINE=			MANPAGES DEBUG PYTHON
OPTIONS_DEFAULT=		MANPAGES PYTHON
OPTIONS_SUB=			yes

DEBUG_CFLAGS=			-g -ggdb3 -O0
DEBUG_CONFIGURE_ON=		--verbose --enable-debug
DEBUG_MAKE_ARGS=		--verbose

PYTHON_USES=			gettext-runtime python
PYTHON_USE+=			python=py3kplist
PYTHON_USES_OFF=		python:build,test
PYTHON_CONFIGURE_OFF=		--disable-python

MANPAGES_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
				xsltproc:textproc/libxslt
MANPAGES_CONFIGURE_ENV_OFF=	XSLTPROC="false"

# No fancy color error messages
CFLAGS+=			${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_clang=			-fno-color-diagnostics
CONFIGURE_ENV+=			NOCOLOR=yes
MAKE_ENV+=			NOCOLOR=yes
# Some symbols in tdb's linker version scripts are not defined, but since the
# scripts are generated dynamically, suppress errors with lld >= 17 due to these
# undefined symbols.
LDFLAGS+=			-Wl,--undefined-version

post-patch:
				@${REINPLACE_CMD} -e 's|%%PKGCONFIGDIR%%|${PKGCONFIGDIR}|g' \
					${BUILD_WRKSRC}/wscript

post-install:
				${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tdb*
				${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtdb.so.1

post-install-PYTHON-on:
				${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/tdb*.so

.include <bsd.port.mk>
