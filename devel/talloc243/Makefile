PORTNAME=	talloc
DISTVERSION=	2.4.3
CATEGORIES=	devel
MASTER_SITES=	SAMBA
PKGNAMESUFFIX=	243

MAINTAINER=	samba@FreeBSD.org
COMMENT=	Hierarchical pool based memory allocator
WWW=		https://talloc.samba.org/

LICENSE=	LGPL3

USES=		compiler pkgconfig shebangfix waf
USE_LDCONFIG=	yes
WAF_CMD=	buildtools/bin/waf
SHEBANG_GLOB=	*.py
CONFIGURE_LOG=	bin/config.log

PKGCONFIGDIR?=	${PREFIX}/libdata/pkgconfig

CONFIGURE_ARGS+=	--builtin-libraries=replace \
			--bundled-libraries=NONE \
			--disable-rpath \
			--disable-rpath-install \
			--without-gettext
CONFIGURE_ENV=		PYTHONHASHSEED=1
MAKE_ENV=		PYTHONHASHSEED=1
# Some symbols in talloc's linker version scripts are not defined, but since the
# scripts are generated dynamically, suppress errors with lld >= 17 due to these
# undefined symbols.
LDFLAGS+=		-Wl,--undefined-version

CONFLICTS_INSTALL=	talloc talloc[0-9]*

PLIST_SUB+=	PKGCONFIGDIR=${PKGCONFIGDIR:S;^${PREFIX}/;;}

OPTIONS_DEFINE=		DEBUG MANPAGES PYTHON
OPTIONS_DEFAULT=	MANPAGES PYTHON
OPTIONS_SUB=		yes

DEBUG_CONFIGURE_ON=	--enable-debug \
			--verbose
DEBUG_MAKE_ARGS=	--verbose
DEBUG_CFLAGS=		-g -ggdb3 -O0

MANPAGES_BUILD_DEPENDS=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
				xsltproc:textproc/libxslt
MANPAGES_CONFIGURE_ENV_OFF=	XSLTPROC="false"

PYTHON_USES=		gettext-runtime python
PYTHON_USES_OFF=	python:build,test
PYTHON_CONFIGURE_OFF=	--disable-python

post-patch:
	@${REINPLACE_CMD} -e 's|%%PKGCONFIGDIR%%|${PKGCONFIGDIR}|g' \
		${BUILD_WRKSRC}/wscript

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtalloc.so.2

post-install-PYTHON-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpytalloc-util*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/talloc*.so

.include <bsd.port.mk>
