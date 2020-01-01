# $FreeBSD$
#   $MCom: ports/finance/gnucash/Makefile,v 1.26 2008/12/31 03:25:18 mezz Exp $

PORTNAME=	gnucash
PORTVERSION=	3.8
CATEGORIES=	finance gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}b${EXTRACT_SUFX}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Quicken-like money and finance manager

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libgnome-keyring.so:security/libgnome-keyring \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libguile-2.2.so:lang/guile2 \
		libgc-threaded.so:devel/boehm-gc-threaded \
		libboost_date_time.so:devel/boost-libs \
		libicudata.so:devel/icu
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-Finance-Quote>=0:finance/p5-Finance-Quote

USES=		cmake:insource compiler:c++11-lib desktop-file-utils \
		gettext-tools gnome libtool localbase perl5 pkgconfig \
		shebangfix tar:bzip2 xorg
USE_XORG=	x11
USE_CXXSTD=	c++11
USE_GNOME=	cairo gtk30 intltool libxml2 libxslt
USE_LDCONFIG=	yes

INSTALLS_ICONS=	yes
CMAKE_ARGS=	-DCOMPILE_GSCHEMAS=OFF \
		-DENABLE_BINRELOC=OFF \
		-DGNC_SHELL=/bin/sh
SHEBANG_FILES=	common/gnc-test-env.pl libgnucash/quotes/gnc-fq-dump
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

GLIB_SCHEMAS=	org.gnucash.dialogs.business.gschema.xml \
		org.gnucash.dialogs.checkprinting.gschema.xml \
		org.gnucash.dialogs.commodities.gschema.xml \
		org.gnucash.dialogs.export.csv.gschema.xml \
		org.gnucash.dialogs.gschema.xml \
		org.gnucash.dialogs.import.csv.gschema.xml \
		org.gnucash.dialogs.import.generic.gschema.xml \
		org.gnucash.dialogs.import.qif.gschema.xml \
		org.gnucash.dialogs.reconcile.gschema.xml \
		org.gnucash.dialogs.sxs.gschema.xml \
		org.gnucash.dialogs.totd.gschema.xml \
		org.gnucash.general.finance-quote.gschema.xml \
		org.gnucash.gschema.xml \
		org.gnucash.history.gschema.xml \
		org.gnucash.warnings.gschema.xml \
		org.gnucash.window.pages.account.tree.gschema.xml \
		org.gnucash.window.pages.gschema.xml

OPTIONS_DEFINE=	AQBANKING DATABASE DOCS NLS OFX PYTHON TEST
OPTIONS_DEFAULT=	AQBANKING OFX

AQBANKING_DESC=	AqBanking support (HBCI/OpenHBCI)
DATABASE_DESC=	Enable SQL database backends
OFX_DESC=	OFX support

OPTIONS_SUB=		yes
AQBANKING_CMAKE_BOOL=	WITH_AQBANKING
AQBANKING_LIB_DEPENDS=	libgwenhywfar.so:devel/gwenhywfar \
			libgwenhywfar.so:devel/gwenhywfar \
			libktoblzcheck.so:finance/ktoblzcheck \
			libaqbanking.so:finance/aqbanking
AQBANKING_VARS=		GLIB_SCHEMAS+=org.gnucash.dialogs.import.hbci.gschema.xml
DATABASE_CMAKE_BOOL=	WITH_SQL
DATABASE_BUILD_DEPENDS=	libdbi-drivers>=0:databases/libdbi-drivers
DATABASE_LIB_DEPENDS=	libdbi.so:databases/libdbi
DATABASE_RUN_DEPENDS=	libdbi-drivers>=0:databases/libdbi-drivers
NLS_CMAKE_BOOL_OFF=	DISABLE_NLS
NLS_USES=		gettext-runtime
OFX_CMAKE_BOOL=		WITH_OFX
OFX_LIB_DEPENDS=	libofx.so:finance/libofx
OFX_VARS=		GLIB_SCHEMAS+=org.gnucash.dialogs.import.ofx.gschema.xml
PYTHON_CMAKE_BOOL=	WITH_PYTHON
PYTHON_USES=		python:3.3+
TEST_BUILD_DEPENDS=	${NONEXISTENT}:devel/googletest:build \
			googletest>0:devel/googletest

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTEST}
GMOCK_WRKSRC!=	cd ${PORTSDIR}/devel/googletest && ${MAKE} -V WRKSRC
CONFIGURE_ENV+=	GMOCK_ROOT="${GMOCK_WRKSRC}"
.endif

post-patch-TEST-off:
	@(cd ${WRKSRC} ; \
		${FIND} . -type f -name CMakeLists.txt \
		-exec ${REINPLACE_CMD} -e '/add_subdirectory *(test.*)/d' \
		-e '/enable_testing()/d' -e '/include (GncAddTest)/d' \
		-e '/gnc_gtest_configure()/d' -e '/scm-test-core/d' {} +)

post-install:
	@(cd ${STAGEDIR}${DATADIR}/icons/hicolor && \
		${RMDIR} 16x16/apps 22x22/apps 22x22 24x24/apps 32x32/apps 32x32\
		48x48/apps 48x48 64x64/apps 64x64 96x96/apps 96x96 \
		128x128/apps 128x128 256x256/apps 256x256 scalable/apps scalable)
	@(cd ${STAGEDIR}${PREFIX}/share/icons/hicolor && \
		${RMDIR} 24x24/actions 16x16/actions)

post-install-PYTHON-on:
	@(cd ${STAGEDIR}${PREFIX} \
		&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/${PORTNAME})
	@(cd ${STAGEDIR}${PREFIX} \
		&& ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/${PORTNAME})
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gnucash/_gnucash_core_c.so

.include <bsd.port.post.mk>
