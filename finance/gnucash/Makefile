PORTNAME=	gnucash
PORTVERSION=	5.13
CATEGORIES=	finance gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Quicken-like money and finance manager
WWW=		https://www.gnucash.org/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	googletest>0:devel/googletest \
		swig:devel/swig
LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libharfbuzz.so:print/harfbuzz \
		libicudata.so:devel/icu \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40
RUN_DEPENDS=	p5-Finance-Quote>=0:finance/p5-Finance-Quote \
		p5-JSON-Parse>=0:devel/p5-JSON-Parse \
		p5-libwww>=0:www/p5-libwww \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https

USES=		cmake:insource compiler:c++17-lang cpe desktop-file-utils \
		gettext-tools gnome guile:2.2,3.0,alias,conflicts localbase \
		perl5 pkgconfig shebangfix tar:bzip2 xorg
USE_XORG=	x11
USE_GNOME=	cairo gdkpixbuf gtk30 intltool libxml2 libxslt
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCOMPILE_GSCHEMAS=OFF \
		-DENABLE_BINRELOC=OFF \
		-DGNC_SHELL=/bin/sh
SHEBANG_FILES=	common/gnc-test-env.pl
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

GLIB_SCHEMAS=	org.gnucash.GnuCash.deprecated.gschema.xml \
		org.gnucash.GnuCash.dialogs.business.gschema.xml \
		org.gnucash.GnuCash.dialogs.checkprinting.gschema.xml \
		org.gnucash.GnuCash.dialogs.commodities.gschema.xml \
		org.gnucash.GnuCash.dialogs.export.csv.gschema.xml \
		org.gnucash.GnuCash.dialogs.gschema.xml \
		org.gnucash.GnuCash.dialogs.import.csv.gschema.xml \
		org.gnucash.GnuCash.dialogs.import.generic.gschema.xml \
		org.gnucash.GnuCash.dialogs.import.qif.gschema.xml \
		org.gnucash.GnuCash.dialogs.reconcile.gschema.xml \
		org.gnucash.GnuCash.dialogs.sxs.gschema.xml \
		org.gnucash.GnuCash.dialogs.totd.gschema.xml \
		org.gnucash.GnuCash.general.finance-quote.gschema.xml \
		org.gnucash.GnuCash.gschema.xml \
		org.gnucash.GnuCash.history.gschema.xml \
		org.gnucash.GnuCash.warnings.gschema.xml \
		org.gnucash.GnuCash.window.pages.account.tree.gschema.xml \
		org.gnucash.GnuCash.window.pages.gschema.xml

OPTIONS_DEFINE=		AQBANKING DATABASE DOCS NLS OFX PYTHON
OPTIONS_DEFAULT=	AQBANKING OFX PYTHON
OPTIONS_SUB=		yes

AQBANKING_DESC=	AqBanking support (HBCI/OpenHBCI)
DATABASE_DESC=	Enable SQL database backends
OFX_DESC=	OFX support

AQBANKING_CMAKE_BOOL=	WITH_AQBANKING
AQBANKING_LIB_DEPENDS=	libaqbanking.so:finance/aqbanking \
			libgwengui-gtk3.so:devel/gwenhywfar-gtk3 \
			libgwenhywfar.so:devel/gwenhywfar
AQBANKING_VARS=		GLIB_SCHEMAS+="org.gnucash.GnuCash.dialogs.flicker.gschema.xml \
			org.gnucash.GnuCash.dialogs.import.hbci.gschema.xml"

DATABASE_CMAKE_BOOL=	WITH_SQL
DATABASE_BUILD_DEPENDS=	libdbi-drivers>=0:databases/libdbi-drivers
DATABASE_LIB_DEPENDS=	libdbi.so:databases/libdbi
DATABASE_RUN_DEPENDS=	libdbi-drivers>=0:databases/libdbi-drivers

NLS_CMAKE_BOOL_OFF=	DISABLE_NLS
NLS_USES=		gettext-runtime

OFX_CMAKE_BOOL=		WITH_OFX
OFX_LIB_DEPENDS=	libofx.so:finance/libofx
OFX_VARS=		GLIB_SCHEMAS+=org.gnucash.GnuCash.dialogs.import.ofx.gschema.xml

PYTHON_CMAKE_BOOL=	WITH_PYTHON
PYTHON_USES=		python

post-patch:
	@${REINPLACE_CMD} -e 's/-Werror //' ${WRKSRC}/CMakeLists.txt

post-install-PYTHON-on:
	@(cd ${STAGEDIR}${PREFIX} \
		&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/${PORTNAME})
	@(cd ${STAGEDIR}${PREFIX} \
		&& ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/${PORTNAME})
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gnucash/_gnucash_core_c.so

.include <bsd.port.mk>
