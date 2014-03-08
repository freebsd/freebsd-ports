# $FreeBSD$
#   $MCom: ports/finance/gnucash/Makefile,v 1.26 2008/12/31 03:25:18 mezz Exp $

PORTNAME=	gnucash
PORTVERSION=	2.6.2
CATEGORIES=	finance gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Quicken-like money and finance manager

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile \
    		${LOCALBASE}/share/guile/1.8/slibcat:${PORTSDIR}/lang/slib-guile
LIB_DEPENDS=	libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2 \
		libgoffice-0.8.so:${PORTSDIR}/devel/goffice
RUN_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile \
		${LOCALBASE}/share/guile/1.8/slibcat:${PORTSDIR}/lang/slib-guile \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Finance-Quote>=0:${PORTSDIR}/finance/p5-Finance-Quote

OPTIONS_DEFINE=	AQBANKING OFX DATABASE LOCALE_TAX PYTHON GTKMM

AQBANKING_DESC=	AqBanking support (HBCI/OpenHBCI)
OFX_DESC=	OFX support
DATABASE_DESC=	Enable SQL database backends
LOCALE_TAX_DESC=	Enable localized tax categories
GTKMM_DESC=	Enable GTKMM based UI

OPTIONS_SUB=		yes
AQBANKING_CONFIGURE_ENABLE=aqbanking
AQBANKING_LIB_DEPENDS=	libgwengui-gtk2.so:${PORTSDIR}/devel/gwenhywfar-gtk2 \
			libktoblzcheck.so:${PORTSDIR}/finance/ktoblzcheck \
			libaqbanking.so:${PORTSDIR}/finance/aqbanking
OFX_CONFIGURE_ENABLE=	ofx
OFX_LIB_DEPENDS=	libofx.so:${PORTSDIR}/finance/libofx
DATABASE_CONFIGURE_ENABLE=dbi
DATABASE_BUILD_DEPENDS=	libdbi-drivers>=0:${PORTSDIR}/databases/libdbi-drivers
DATABASE_LIB_DEPENDS=	libdbi.so:${PORTSDIR}/databases/libdbi
DATABASE_RUN_DEPENDS=	libdbi-drivers>=0:${PORTSDIR}/databases/libdbi-drivers
DATABASE_CONFIGURE_ON=	--with-dbi-dbd-dir=${LOCALBASE}/lib/dbd
LOCALE_TAX_CONFIGURE_ON=--enable-locale-specific-tax
PYTHON_CONFIGURE_ON=	--enable-python
PYTHON_USE=		PYTHON=yes
GTKMM_USE=		GNOME=gtkmm24
GTKMM_CONFIGURE_ON=	--enable-gtkmm
GTKMM_CONFIGURE_OFF=	--disable-gtkmm

USE_XORG=	x11
USE_BZIP2=	yes
USES=		desktop-file-utils gettext gmake perl5 pkgconfig shebangfix
INSTALLS_ICONS=	yes
USE_GNOME+=	gtk20 libgnomecanvas libxml2 libxslt:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-error-on-warning \
		--disable-doxygen
SHEBANG_FILES=	src/quotes/gnc-fq-dump

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
		org.gnucash.gschema.xml \
		org.gnucash.history.gschema.xml \
		org.gnucash.warnings.gschema.xml \
		org.gnucash.window.pages.account.tree.gschema.xml \
		org.gnucash.window.pages.gschema.xml

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAQBANKING}
GLIB_SCHEMAS+=	org.gnucash.dialogs.import.hbci.gschema.xml
.endif

.if ${PORT_OPTIONS:MOFX}
GLIB_SCHEMAS+=	org.gnucash.dialogs.import.ofx.gschema.xml
.endif

post-install:
.if ${PORT_OPTIONS:MPYTHON}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${STAGEDIR}${PYTHON_SITELIBDIR:S|${LOCALBASE}|${PREFIX}|}/${PORTNAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${STAGEDIR}${PYTHON_SITELIBDIR:S|${LOCALBASE}|${PREFIX}|}/${PORTNAME}
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gnucash/_gnucash_core_c.so
.endif
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*so*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gnucash/lib*.so

.include <bsd.port.mk>
