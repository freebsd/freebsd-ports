# Ports collection makefile for:  gnucash
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#   $MCom: ports/finance/gnucash/Makefile,v 1.26 2008/12/31 03:25:18 mezz Exp $
#

PORTNAME=	gnucash
PORTVERSION=	2.2.9
PORTREVISION=	3
CATEGORIES=	finance gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION} \
		http://www.gnucash.org/pub/gnucash/sources/stable/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Quicken-like money and finance manager

BUILD_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile \
    		${LOCALBASE}/share/guile/1.8/slibcat:${PORTSDIR}/lang/slib-guile
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		goffice-0.8.7:${PORTSDIR}/devel/goffice
RUN_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile \
		${LOCALBASE}/share/guile/1.8/slibcat:${PORTSDIR}/lang/slib-guile \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Finance/Quote.pm:${PORTSDIR}/finance/p5-Finance-Quote \
		${SITE_PERL}/HTML/TableExtract.pm:${PORTSDIR}/www/p5-HTML-TableExtract \
		${SITE_PERL}/Finance/QuoteHist.pm:${PORTSDIR}/finance/p5-Finance-QuoteHist \
		${LOCALBASE}/share/omf/gnucash-docs/gnucash-guide-C.omf:${PORTSDIR}/finance/gnucash-docs

OPTIONS=	AQBANKING	"AqBanking support (HBCI/OpenHBCI)"	off	\
		OFX		"OFX support"				off	\
		POSTGRESQL	"Enable Postgresql as Backend"		off

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XORG=	xpm x11
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_PERL5=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix libgsf_gnome libglade2 \
		libgnomeprint libgnomeprintui gtkhtml3
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
GC_LIBS=	-L${LOCALBASE}/lib -lintl
CONFIGURE_ARGS=--with-glib-config=${GLIB_CONFIG} \
		--disable-error-on-warning

MAN1=		gnc-prices.1 gnucash.1
INFO=		gnucash-design

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

.include <bsd.port.pre.mk>

# WITH_OPENHBCI is old synonym for aqbanking option
.if defined(WITH_AQBANKING) || defined(WITH_OPENHBCI)
LIB_DEPENDS+=	aqbanking.30:${PORTSDIR}/finance/aqbanking \
		ktoblzcheck.6:${PORTSDIR}/finance/ktoblzcheck
GCONF_SCHEMAS+=	apps_gnucash_dialog_hbci.schemas
CONFIGURE_ARGS+=--enable-hbci
GC_LIBS+=	-laqbanking
PLIST_SUB+=	AQBANKING=""
.else
CONFIGURE_ARGS+=--disable-hbci
PLIST_SUB+=	AQBANKING="@comment "
.endif

.if defined(WITH_OFX)
CONFIGURE_ARGS+=--enable-ofx
LIB_DEPENDS+=	ofx.4:${PORTSDIR}/finance/libofx
PLIST_SUB+=	OFX=""
.else
CONFIGURE_ARGS+=--disable-ofx
PLIST_SUB+=	OFX="@comment "
.endif

.if defined(WITH_POSTGRESQL)
CONFIGURE_ARGS+=--enable-sql
PLIST_SUB+=	PGBACKEND=""
USE_PGSQL+=	yes
GC_LIBS+=	-lpq
.else
CONFIGURE_ARGS+=--disable-sql
PLIST_SUB+=	PGBACKEND="@comment "
.endif

CONFIGURE_ENV+=	LIBS="${GC_LIBS}"

.include <bsd.port.post.mk>
