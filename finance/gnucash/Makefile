# $FreeBSD$
#   $MCom: ports/finance/gnucash/Makefile,v 1.26 2008/12/31 03:25:18 mezz Exp $

PORTNAME=	gnucash
PORTVERSION=	2.4.13
PORTREVISION=	1
CATEGORIES=	finance gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Quicken-like money and finance manager

LICENSE=	GPLv3

BUILD_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile \
    		${LOCALBASE}/share/guile/1.8/slibcat:${PORTSDIR}/lang/slib-guile
LIB_DEPENDS=	libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libgoffice-0.8.so:${PORTSDIR}/devel/goffice
RUN_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile \
		${LOCALBASE}/share/guile/1.8/slibcat:${PORTSDIR}/lang/slib-guile \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Finance-Quote>=0:${PORTSDIR}/finance/p5-Finance-Quote

OPTIONS_DEFINE=	AQBANKING OFX DATABASE LOCALE_TAX WEBKIT PYTHON

AQBANKING_DESC=	AqBanking support (HBCI/OpenHBCI)
OFX_DESC=	OFX support
DATABASE_DESC=	Enable SQL database backends
LOCALE_TAX_DESC=	Enable localized tax categories
WEBKIT_DESC=	Use webkit instead of gtkhtml for the HTML engine

OPTIONS_SUB=		yes
AQBANKING_CONFIGURE_ENABLE=aqbanking
AQBANKING_LIB_DEPENDS=	libgwengui-gtk2.so:${PORTSDIR}/devel/gwenhywfar-gtk2 \
			libktoblzcheck.so:${PORTSDIR}/finance/ktoblzcheck \
			libaqbanking.so:${PORTSDIR}/finance/aqbanking
OFX_CONFIGURE_ENABLE=	ofx
OFX_LIB_DEPENDS=	libofx.so:${PORTSDIR}/finance/libofx
DATABASE_CONFIGURE_ENABLE=dbi
DATABASE_LIB_DEPENDS=	libdbi.so:${PORTSDIR}/databases/libdbi
LOCALE_TAX_CONFIGURE_ON=--enable-locale-specific-tax
WEBKIT_CONFIGURE_ON=	--with-html-engine=webkit
WEBKIT_LIB_DEPENDS=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2
PYTHON_CONFIGURE_ON=	--enable-python-bindings
PYTHON_USE=		PYTHON=yes

USE_BZIP2=	yes
USES=		gettext gmake pkgconfig perl5
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix libglade2 libgnomeui
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-error-on-warning \
		--disable-doxygen

GCONF_SCHEMAS=	apps_gnucash_dialog_business_common.schemas \
		apps_gnucash_dialog_commodities.schemas \
		apps_gnucash_dialog_common.schemas \
		apps_gnucash_dialog_prices.schemas \
		apps_gnucash_dialog_print_checks.schemas \
		apps_gnucash_dialog_reconcile.schemas \
		apps_gnucash_dialog_scheduled_transctions.schemas \
		apps_gnucash_dialog_totd.schemas \
		apps_gnucash_general.schemas \
		apps_gnucash_history.schemas \
		apps_gnucash_import_generic_matcher.schemas \
		apps_gnucash_import_qif.schemas \
		apps_gnucash_warnings.schemas \
		apps_gnucash_window_pages_account_tree.schemas \
		apps_gnucash_window_pages_register.schemas

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAQBANKING}
GCONF_SCHEMAS+=	apps_gnucash_dialog_hbci.schemas
.endif

.if ! ${PORT_OPTIONS:MWEBKIT}
USE_GNOME+=	gtkhtml3
.endif

post-install:
.if ${PORT_OPTIONS:MPYTHON}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${STAGEDIR}${PYTHON_SITELIBDIR:S|${LOCALBASE}|${PREFIX}|}/${PORTNAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${STAGEDIR}${PYTHON_SITELIBDIR:S|${LOCALBASE}|${PREFIX}|}/${PORTNAME}
.endif

.include <bsd.port.mk>
