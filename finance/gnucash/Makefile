# Ports collection makefile for:  gnucash
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#   $MCom: ports/finance/gnucash/Makefile,v 1.14 2007/03/13 05:58:37 marcus Exp $
#

PORTNAME=	gnucash
PORTVERSION=	2.0.5
PORTREVISION=	2
CATEGORIES=	finance gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.gnucash.org/pub/gnucash/sources/stable/
MASTER_SITE_SUBDIR=	gnucash

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Quicken-like money and finance manager

BUILD_DEPENDS=	guile>=1.6.8_2:${PORTSDIR}/lang/guile
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		ofx.3:${PORTSDIR}/finance/libofx \
		gwrap-core-runtime.0:${PORTSDIR}/devel/g-wrap
RUN_DEPENDS=	guile>=1.6.8_2:${PORTSDIR}/lang/guile \
		${LOCALBASE}/share/guile/1.6/slibcat:${PORTSDIR}/lang/slib-guile \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Finance/Quote.pm:${PORTSDIR}/finance/p5-Finance-Quote \
		${SITE_PERL}/HTML/TableExtract.pm:${PORTSDIR}/www/p5-HTML-TableExtract \
		${SITE_PERL}/Finance/QuoteHist.pm:${PORTSDIR}/finance/p5-Finance-QuoteHist \
		${LOCALBASE}/share/gnome/omf/gnucash-docs/gnucash-guide-C.omf:${PORTSDIR}/finance/gnucash-docs

OPTIONS=	AQBANKING	"AqBanking support (HBCI/OpenHBCI)"	off

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_XPM=	yes
USE_PERL5=	yes
USE_GNOME=	gnomeprefix gtkhtml3 libgsf_gnome libglade2 \
		libgnomeprint libgnomeprintui
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=--with-glib-config=${GLIB_CONFIG} \
		--enable-ofx \
		--disable-error-on-warning
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lintl"

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
		apps_gnucash_warnings.schemas \
		apps_gnucash_window_pages_account_tree.schemas \
		apps_gnucash_window_pages_register.schemas

.include <bsd.port.pre.mk>

# WITH_OPENHBCI is old synonym for aqbanking option
.if defined(WITH_AQBANKING) || defined(WITH_OPENHBCI)
LIB_DEPENDS+=	aqbanking.5:${PORTSDIR}/finance/aqbanking \
		ktoblzcheck.4:${PORTSDIR}/finance/ktoblzcheck
CONFIGURE_ARGS+=--enable-hbci
PLIST_SUB=	AQBANKING=""
.else
CONFIGURE_ARGS+=--disable-hbci
PLIST_SUB=	AQBANKING="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${datarootdir}/info|${PREFIX}/info| ; \
	    	s|libgtkhtml-3.8|libgtkhtml-3.14|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(datadir)/aclocal|${PREFIX}/share/aclocal|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
