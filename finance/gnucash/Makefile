# Ports collection makefile for:  gnucash
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	gnucash
PORTVERSION=	1.8.9
PORTREVISION=	1
CATEGORIES=	finance gnome
MASTER_SITES=	http://www.gnucash.org/pub/gnucash/sources/stable/ \
		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
		http://www.linas.org/pub/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnucash

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Quicken-like money and finance manager

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile \
		guppi.16:${PORTSDIR}/math/guppi \
		popt.0:${PORTSDIR}/devel/popt \
		ofx.0:${PORTSDIR}/finance/libofx \
		db4.0:${PORTSDIR}/databases/db4 \
		gw-standard.0:${PORTSDIR}/devel/g-wrap
RUN_DEPENDS=	${LOCALBASE}/share/guile/slibcat:${PORTSDIR}/lang/slib-guile \
		${SITE_PERL}/HTML/Base.pm:${PORTSDIR}/www/p5-HTML \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Finance/Quote.pm:${PORTSDIR}/finance/p5-Finance-Quote \
		${SITE_PERL}/Finance/QuoteHist.pm:${PORTSDIR}/finance/p5-Finance-QuoteHist \
		${X11BASE}/share/gnome/omf/gnucash-docs/gnucash-guide-C.omf:${PORTSDIR}/finance/gnucash-docs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_XPM=	yes
USE_PERL5=	yes
USE_GNOME=	gnomeprefix gnomehack gnomeprint libglade gtkhtml libghttp
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-glib-config=${GLIB_CONFIG} \
		--enable-ofx \
		--disable-error-on-warning
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lintl"

MAN1=		gnc-prices.1 gnucash.1
INFO=		gnucash-design

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/db41/db_185.h)
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db41
post-patch:
	@${REINPLACE_CMD} -e "s|db4/db_185.h|db41/db_185.h|g" \
		${WRKSRC}/configure
.else
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
.endif

.if exists(${LOCALBASE}/include/openhbci.h) || defined(WITH_OPENHBCI)
LIB_DEPENDS+=	openhbci.13:${PORTSDIR}/finance/openhbci \
		ktoblzcheck.1:${PORTSDIR}/finance/ktoblzcheck
CONFIGURE_ARGS+=--enable-hbci
.endif

post-configure:
	@${RM} ${WRKSRC}/src/doc/design/gnucash-design.info

.include <bsd.port.post.mk>
