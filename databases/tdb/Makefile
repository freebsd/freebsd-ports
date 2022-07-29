PORTNAME=			tdb
DISTVERSION=			1.4.7
PORTREVISION=			0
PORTEPOCH=			1
CATEGORIES=			databases
MASTER_SITES=			SAMBA

MAINTAINER=			timur@FreeBSD.org
COMMENT=			Trivial Database

LICENSE=			GPLv3

USES=				compiler pkgconfig shebangfix waf
USE_LDCONFIG=			yes
SHEBANG_GLOB=			*.py
WAF_CMD=			buildtools/bin/waf
CONFIGURE_LOG=			bin/config.log

PKGCONFIGDIR?=			${PREFIX}/libdata/pkgconfig
PLIST_SUB+=			PKGCONFIGDIR=${PKGCONFIGDIR:S;^${PREFIX}/;;}

CONFIGURE_ARGS+=		--mandir=${MANPREFIX}/man \
				--disable-rpath \
				--disable-rpath-install \
				--bundled-libraries=NONE \
				--builtin-libraries=replace \
				--without-gettext
CONFIGURE_ENV=			PYTHONHASHSEED=1
MAKE_ENV=			PYTHONHASHSEED=1

MANPAGES_DESC=			Build and install manpages (requires textproc/docbook-xsl)

OPTIONS_DEFINE=			MANPAGES DEBUG PYTHON
OPTIONS_DEFAULT=		PYTHON
OPTIONS_SUB=			yes

DEBUG_CFLAGS=			-g -ggdb3 -O0
DEBUG_CONFIGURE_ON=		--verbose --enable-debug
DEBUG_MAKE_ARGS=		--verbose

PYTHON_USES=			gettext-runtime python:3.6+
PYTHON_USE+=			python=py3kplist
PYTHON_USES_OFF=		python:build,test
PYTHON_CONFIGURE_OFF=		--disable-python

MANPAGES_CONFIGURE_ENV_OFF+=	XSLTPROC="true"
MANPAGES_BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
				xsltproc:textproc/libxslt
# No fancy color error messages
CFLAGS+=			${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_clang=			-fno-color-diagnostics
CONFIGURE_ENV+=			NOCOLOR=yes
MAKE_ENV+=			NOCOLOR=yes

post-patch:
				@${REINPLACE_CMD} -e 's|%%PKGCONFIGDIR%%|${PKGCONFIGDIR}|g' \
					${BUILD_WRKSRC}/wscript

pre-build-MANPAGES-off:
				${MKDIR} ${BUILD_WRKSRC}/bin/default/man
				${INSTALL_MAN} ${FILESDIR}/tdb*.8 ${BUILD_WRKSRC}/bin/default/man

post-install:
				${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tdb*
				${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtdb.so.1

post-install-PYTHON-on:
				${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/tdb*.so

.include <bsd.port.mk>
