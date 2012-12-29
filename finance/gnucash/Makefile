# $FreeBSD$
#   $MCom: ports/finance/gnucash/Makefile,v 1.26 2008/12/31 03:25:18 mezz Exp $

PORTNAME=	gnucash
PORTVERSION=	2.4.11
PORTREVISION=	2
CATEGORIES=	finance gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Quicken-like money and finance manager

LICENSE=	GPLv3

BUILD_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile \
    		${LOCALBASE}/share/guile/1.8/slibcat:${PORTSDIR}/lang/slib-guile
LIB_DEPENDS=	gnome-keyring:${PORTSDIR}/security/libgnome-keyring \
		goffice-0.8:${PORTSDIR}/devel/goffice
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

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_PERL5=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix libglade2 libgnomeui
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-error-on-warning \
		--disable-doxygen

MAN1=		gnucash.1

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
LIB_DEPENDS+=	gwengui-gtk2:${PORTSDIR}/devel/gwenhywfar-gtk2 \
		ktoblzcheck:${PORTSDIR}/finance/ktoblzcheck \
		aqbanking:${PORTSDIR}/finance/aqbanking

GCONF_SCHEMAS+=	apps_gnucash_dialog_hbci.schemas
CONFIGURE_ARGS+=--enable-aqbanking
PLIST_SUB+=	AQBANKING=""
.else
CONFIGURE_ARGS+=--disable-aqbanking
PLIST_SUB+=	AQBANKING="@comment "
.endif

.if ${PORT_OPTIONS:MOFX}
CONFIGURE_ARGS+=--enable-ofx
LIB_DEPENDS+=	ofx:${PORTSDIR}/finance/libofx
PLIST_SUB+=	OFX=""
.else
CONFIGURE_ARGS+=--disable-ofx
PLIST_SUB+=	OFX="@comment "
.endif

.if ${PORT_OPTIONS:MDATABASE}
CONFIGURE_ARGS+=--enable-dbi
LIB_DEPENDS+=	dbi:${PORTSDIR}/databases/libdbi
PLIST_SUB+=	DATABASE=""
.else
CONFIGURE_ARGS+=--disable-dbi
PLIST_SUB+=	DATABASE="@comment "
.endif

.if ${PORT_OPTIONS:MLOCALE_TAX}
CONFIGURE_ARGS+=--enable-locale-specific-tax
.endif

.if ${PORT_OPTIONS:MWEBKIT}
CONFIGURE_ARGS+=--with-html-engine=webkit
LIB_DEPENDS+=	webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2
.else
USE_GNOME+=	gtkhtml3
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=--enable-python-bindings
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MPYTHON}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${PYTHON_SITELIBDIR:S|${LOCALBASE}|${PREFIX}|}/${PORTNAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${PYTHON_SITELIBDIR:S|${LOCALBASE}|${PREFIX}|}/${PORTNAME}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
