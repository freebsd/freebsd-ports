# Ports collection makefile for:  gnucash
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	gnucash
PORTVERSION=	1.8.3
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
RUN_DEPENDS=	${LOCALBASE}/share/slib/Template.scm:${PORTSDIR}/lang/slib \
		${site_perl}/HTML/Base.pm:${PORTSDIR}/www/p5-HTML \
		${site_perl}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${site_perl}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${site_perl}/Finance/Quote.pm:${PORTSDIR}/misc/p5-Finance-Quote \
		${site_perl}/Finance/QuoteHist.pm:${PORTSDIR}/misc/p5-Finance-QuoteHist \
		${X11BASE}/share/gnome/omf/gnucash-docs/gnucash-guide-C.omf:${PORTSDIR}/finance/gnucash-docs

site_perl=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

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

post-patch:
	@${REINPLACE_CMD} -e 's^-l(pthread|c_r)^${PTHREAD_LIBS}^g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
